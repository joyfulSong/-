
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 내방법: i포문이 돌면서 핀을 정하고, j가 N보다 작거나 같을때까지 연속으로 돌아 N을 만들어낸다. 
int main()
{
	int N, tmp, i, j, k , cnt = 0;

	int a[1000];

	cin >> N;
	for (i = 0; i < N; i++) {
		a[i] = i + 1;
	}

	for (i = 0; i < N; i++) {
		tmp = 0;
		j = i;
		while (tmp <= N) {
			tmp += a[j];
			if (a[j] != N && tmp == N) { //a[j] == N이면 자기 자신 하나이므로 연속된 수가 아님.
				cnt++;
				for (k = i; k < j; k++) { 
					cout << a[k] << " + ";
				}
				cout << a[j] << " = " << N << "\n";
				break;
			}
			j++;
		}
		
	}
	cout << cnt;
	return 0;
}

// 선생님
//// 15 = (6 *2)+1+2 = (6+1)+(6+2) 로 나타낼 수 있다.
//// 즉 연속된 수의 갯수를 넘버링해 각각에 같은 크기의 숫자를 배분해주면 연속된 수로 표현이 되는것이다. 
//// 얼마의 수를 배분해야하는지 알기 위해 (15 - 1 - 2)/2 를 한다.
//int main() {
//	int a, b = 1, tmp, i, cnt = 0;
//	cin >> a;
//	tmp = a; //a를 변형시켜야 하므로 tmp로 대신 사용
//	tmp--; // 1부터 빼면서 진행
//	while (tmp > 0)//나눈 몫이 0보다 클때까지.
//	{
//		b++; //b는 연속된 수의 개수를 나타냄. tmp가 빼기 1한것부터이므로, b는 2부터.
//		tmp = tmp - b;// 연속된 수 두개로 나타내지는지 볼때, 15- 1- 2가 되도록 함.
//		if (tmp / b) {
//			for (i = 0; i < b; i++) {
//				//연속된 수 b개만큼 출력, +붙은건 마지막-1개 까지.
//				cout << (tmp / b) + i << " + ";
//			}
//			cout << (tmp / b) + b << " = " << a << "\n";
//		}
//	}
//	cout << cnt;
//}