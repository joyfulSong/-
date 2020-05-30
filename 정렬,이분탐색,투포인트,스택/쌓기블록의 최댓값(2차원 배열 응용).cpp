// 정면 기준으로 전체 각 열을 초기화 시키고,
// 우측면 열 기준으로 더 크게 입력되어 입력되어 있는 값은 우측열 값 기준으로 바꾼다. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[11][11], b[11]; // b는 정면때 쓰고 측면때 재사용
int main()
{
	int n, sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[j][i] = b[i]; //한 열(i)의 모든 행(j)에 초기화한다. 
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > b[i]) a[i][j] = b[i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
	}

	cout << sum;

	return 0;
}

