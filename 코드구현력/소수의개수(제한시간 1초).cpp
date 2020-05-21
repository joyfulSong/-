//수학적으로 대단한 연산을 하는게 아니라, 어떻게 하면 반복문 도는 횟수를 줄일 수 있을지, 수학적 근거를 생각해본다.
// 36 = 1 * 36
//      2 * 18
//      3 * 12
//      4 * 9
//      6 * 6 
// 자신의 제곱근까지만 확인하면 나머지 배수는 자동으로 확인된다. 


#include <iostream>

using namespace std;

int main()
{
	int N, cnt = 0, flag = 1; 

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 2; j * j <= i; j++) { // 약수가 있는지 확인은 자신의 제곱근까지 하면 됨
			if (i % j == 0) {
				flag = 0; // false
				break; // i의 약수가 하나라도 있으면 소수가 아님.
			}
			//약수가 없으면
			if (flag == 1) cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}