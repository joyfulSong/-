// 일의자리는 몇자리수이든, 10으로 나눈 나머지가 된다. 
#include <iostream>

using namespace std;

int main()
{
	int N, tmp, cnt = 0, digit;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		tmp = i;
				while (tmp > 0) {
					digit = tmp % 10; // 일의 자리를 넣어주는 용도. 3나누기 10도 3이기에 일의자리를 따로 또 걸러줄 필요 없음. 
					if (digit == 3) cnt++; // 일의 자리를 3으로 나눠보아 나눠지면 cnt증가
					tmp = tmp / 10; // 일의자리를 없애준다.
			}
		}
	cout << cnt;
	return 0;
}