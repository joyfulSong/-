// 이중 포문으로 하지 않고, 수학적으로 생각
// a + b = sum / b + c/ c + d /....
// b + c = sum + c - a 이므로
// sum + a[i] + a[i-K]: 새롭게 갱신된 i의 한칸 더하고, 갱신이전의 남은 i한칸 지우고.

#include <iostream>
#include <vector> //10만이기에 동적할당.
using namespace std;

int main()
{
	int N, K, sum = 0, max;

	cin >> N >> K;

	vector<int> T(N);//크기 지정 소괄호

	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}

	for (int i = 0; i < K; i++) {
		sum += T[i];
	}

	max = sum;
	for (int i = K; i < N; i++) {
		sum = sum + T[i] - T[i - K];
		if (sum > max) {
			max = sum;
		}
	}

	cout << max << "\n";

	return 0;
}

// 내 방법: i로 밀고 나가며 j로 k까지 더해주는 이중포문 --> 10만  * 10만으로 시간복잡도 N제곱. 타임리밋초과. 
// 이중 포문으로 할 때도, 마지막 구간은 i를 N-K로 잡아두고, K가 i부터 N까지 돌기때문에 지정 N-K로.
//int main()
//{
//	int N, K, max = -2147000000;
//
//	cin >> N >> K;
//
//	vector<int> T(N);
//	vector<int> A(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> T[i];
//	}
//
//	for (int i = 0; i < (N - K); i++) {
//		for (int j = i; j < K; j++) {
//			A[i] += T[j];
//		}
//		if (A[i] > max) {
//			max = A[i];
//		}
//	}
//	cout << max << "\n";
//
//	return 0;
//}