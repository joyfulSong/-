// (1,1)에서 (3,3)으로 갈 때, 오른, 아래만이 최단경로의 이동방향이고, 위, 왼은 돌아가는 방향이다.
// bfs라면 최단경로 찾으며 좌표를 바꾸겠지만 이거는 dp로 풀려 하니 모든 i,j에 값을 다 저장한다.
// 0행과 0열은 오른쪽으로만 아래로만 이동이므로 먼저 구해놓는다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[21][21], dy[21][21];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	dy[0][0] = a[0][0]; // 시작점
	for (int i = 1; i < n; i++) {
		dy[0][i] = a[0][i] + dy[0][i - 1];
		dy[i][0] = a[i][0] + dy[i - 1][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			// i,j까지 오는데 최소 비용은 위쪽, 왼쪽중에 작은 것에 자기자신 값 더한것이다. (오는데 위에서 아래로, 왼쪽에서 오른쪽으로 왓으므로)
			dy[i][j] = min(dy[i - 1][j], dy[i][j - 1]) + a[i][j];
		}
	}

	cout << dy[n-1][n-1];

}