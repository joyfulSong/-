// 자리수별로 3이 있는 모든 경우의 수를 따진다.
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	int N, lf = 1, rt, current, k = 1, res = 0; // while문에서 lf기준으로 하기에 초기화를 1로 해준다. k는 자릿수, 1의자리부터 시작
	cin >> N;

	//N으로 받아온 숫자를 1의자리를 current로 지정해 left, right로 나누어 
	//current 자리의 수가 3일때의 토탈 가능한 수의 갯수를 구해나간다. 
	// 타고 올라간 lf가 0이 되면 종료한다. (다 올라갔을 때)
	while (lf != 0) {
		lf = N / (k * 10); // 현재 자릿수가 1이면 1의 자리를 뜯어내야하므로.
		rt = N % k; // 현재 자릿수 뜯어내기 
		current = (N / k) % 10; // N/k는 현재위치가 마지막 자리가 되도록 하고, 여기서 10으로 나눈 나머지를 구하면 그 마지막 자리만 떼어진다. 

		if (current > 3) res = res + (lf + 1) * k; // current의 3이 온다고 생각하면, rt는 0부터 9x 까지 모두 가능하므로, k를 곱해주고, lf +1인 것은 000인 경우부터 자기자신 lf까지이기에.
		else if (current == 3) res = res + (lf * k) + (rt + 1); // 현재 자리가 3이면 왼쪽은 000부터 lf이전까지 (lf가 12이면 11까지)가능하고, 12345일 때, rt의 00부터 45까지를 더해주면 된다. 
		else res = res + (lf * k); // 3보다 작을때. 1 2 '2' 4 5 라면 백의 자리에 3이 올 수 없으니, lf는 00부터 11까지, rt는 모든 경우(00부터 45까지) 가 가능하다. 

		//res 계산 끝났으면 k증가시키기
		k = k * 10;
	}

	cout << res;
	return 0;
}

