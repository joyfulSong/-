//각 점수를 기준으로 어떻게 모든 점수와 비교하느냐? 항상 j는 i기준 따라갈 필요 없다.
// 브루트 포스
#include <iostream>

using namespace std;

int main()
{
	int N, max;

	int a[101];
	int res[101];
	
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		res[i] = 1; // 모든 석차 우선 1로 초기화
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i] > a[j]) res[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << res[i] << " ";
	}
	return 0;
}