
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int a[21][21], dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 }, dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 }; //서북방향부터 시계방향으로.

// 섬을 하나 발견하고, 위치 이동해가며 방향 탐색시에 2차원 좌표를 갱신해야하므로, 구조체 만든다.
struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

int main()
{
	int n, cnt = 0;
	// Loc x; 기본 생성자를 안만들어줬으니 여기서 만들고 넘어가지 말고, 필요할 때 값을 넣어 초기화할 곳에 만들자.
	queue<Loc> Q;
	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (a[i][j] == 1) { 
				// 섬의 일부가 발견되면 
				Q.push(Loc(i, j));
				a[i][j] = 0; // 그 부분은 지도에서 0으로 만들어주고, 8방향을 돌면서 섬의 다른 부분이 있는지 확인
				
				while (!Q.empty()) {
					Loc x = Q.front(); // 발견된 위치를 x에 넣고 큐에서 뺀다.
					Q.pop();

					for (int k = 0; k < 8; k++) {
						if (a[x.x + dx[k]][x.y + dy[k]] == 1) {
							// a[i + dx[k]][j + dy[k]] 으로 하면 i,j가 아닌 발견한 위치에 대해서 방향 탐색을 해야하므로, 안된다.
							a[x.x + dx[k]][x.y + dy[k]] == 0; //있으면 0으로 만들어주고,
							Q.push(Loc(x.x + dx[k], x.y + dy[k])); // 그 위치를 큐에 넣는다.
							// 현재의 x에서 8방향 모두 탐색해 큐에 넣고나면, front의 값을 x로 갱신해 그곳에서 또 8방향 탐색한다.
						}
					}
				}
				cnt++; //큐가 비면 섬의 부분을 모두 탐색한 것으로 cnt증가.
			}
		}
	}

	cout << cnt;
	return 0;
}