// 소인수분해 응용
// int형 변수 = 2^31 - 1 개만 담을 수 있음. n!을 구해넣으면 오버플로우
// n!을 구성하는 숫자 중 2와 5의 갯수를 확인해, 둘 중 작은 갯수가 10의 갯수이다. (2가 3개이고 5가 2개이면 10은 두번 만들어지므로)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, tmp, j, cnt1 = 0, cnt2 = 0;

	cin >> N;

	for (int i = 1; i < N; i++) {
		tmp = i;
		j = 2;
		while (1) {
			if (tmp % j == 0) {
				if (j == 2) cnt1++;
				else if (j == 5) cnt2++;
				tmp = tmp / j;
			}
			else j++;
			if (tmp == 1) break;
		}
	}
	if (cnt1 < cnt2) cout << cnt1;
	else cout << cnt2;

	return 0;
}

// 나 n!을 구성하는 숫자 두개씩을 곱해봐서 10으로 나눠지는 횟수를 구한다. 
//int main()
//{
//	int N, a, b, tmp, cnt = 0;
//
//	cin >> N;
//
//	vector<int> fac(N);
//	for (int i = 0; i < N; i++) {
//		fac[i] = N - i;
//	}
//
//	int i = 0;
//	while(1) {
//		if (i<N) {
//			a = fac[i];
//			b = fac[i + 1];
//			tmp = (b * a);
//			while (tmp % 10 == 0) {
//					cnt++;
//					tmp = tmp / 10;
//			}
//			i = i + 2;
//		}
//		else
//			break;
//	}
//
//	cout << cnt; 
//	return 0;
//
//
//}