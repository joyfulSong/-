// 2차원 배열 탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[51][51]; //전역변수 0으로 초기화. 
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int n, cnt = 0, res = 0;
	cin >> n;

	// 1부터 받기 떄문에 네 테두리는 자동으로 0으로 남겨짐.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) { //한 행씩
		for (int j = 1; j <= n; j++) { //해당 행의 각 열씩
			cnt = 0;
			for (int k = 0; k < 4; k++) { // 배열요소 한개를 잡아 
				// 그의 9시 12시 3시 6시 방향 한개씩과 크기비교
				if (a[i + dx[k]][j + dy[k]] < a[i][j]) cnt++;
				// a[i + dx[k]][j + dy[k]] >= a[i][j] 봉우리 후보보다 큰 상하좌우가 한개라도 발견되면 
				// flag = 1, break;

			}

			//네개 다 돌고 cnt == 4이면 상하좌우보다 크다는 것이므로 
			if (cnt == 4) res++; // 봉우리 갯수 추가.
			//if flag == 0 res++;
		}
	}

	cout << res;
		return 0;
} 

