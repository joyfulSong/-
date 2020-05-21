#include <iostream>
using namespace std;

int reverse(int x) {
	int res = 0, tmp = 0; // 답 저장용
	while (x > 0) { // 숫자를 10으로 나눈 나머지가 1의 자리의 숫자, 10으로 나누어 x값 갱신
		// 아래 코드로 910이 019되는 것도 방지해줌
		tmp = x % 10;
		res = res * 10 + tmp; // 기존 res(이전 반복때 1의자리가 0이 아니었다면 그 값이 들어있음)에 10을 곱하고 현재의 1의자리를 더해 역순으로 만듬
		x = x / 10; 
	}
	return res;
}

bool isPrime(int x) { // 소수는 1과 자기자신만이 약수이므로, 2부터 자기자신이전까지 나눠본다.
	bool flag = true; // 약수가 나타나면 false로 바꿔준다.
	if (x == 1) return false; // num이 100이라 뒤집은 숫자가 1이면 아래 for문에서 flag반환이 안되므로. 
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			flag = false;
			break; // 발견되면 더 돌것 없으므로.
		}
	}
	return flag;
}

int main()
{
	int N, num, tmp;
	cin >> N; // 자연수의 갯수

	for (int i = 0; i < N; i++) {
		cin >> num; //자연수 받기

		tmp = reverse(num); // 역순으로 만들기 
		if (isPrime(tmp)) cout << tmp << endl;		
	}
	return 0;
}