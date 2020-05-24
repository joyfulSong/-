// i에 대해 검사할 때 자신보다 앞선 사람들의 점수가 자신보다 크거나 같으면 자신의 등수는 밀려남
//앞선 사람들의 점수가 자기보다 작아야만 자신이 제칠 수 있다는 것을 포인트로 삼음.
// 등수 배열을 안만들고 cnt를 한 반복마다 출력하고 초기화하면 됨.
#include <iostream>
#include <vector> //10만이기에 동적할당.
#include <algorithm>
using namespace std;

int main()
{
	int N, cnt;
	cin >> N;

	vector<int> a(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	cout << "1" << " "; // 맨 앞사람은 1등. 뒤에 더 점수 큰 사람이 있어도, 같이 1등하는 것임. 
	for (int i =1 ; i < N; i++) {
		cnt = 0;
		for (int j = i-1; j >= 0; j--) {
			if (a[j] >= a[i]) cnt++;
		}
		cout << cnt+1 << " ";
	}
	return 0;
}

