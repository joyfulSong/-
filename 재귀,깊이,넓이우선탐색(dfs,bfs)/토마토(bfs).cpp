
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int a[1001][1001], dis[1001][1001], res = -2147000000, dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
// 몇일만에 익는지 기록하는 dis 이차원배열: 초기 익은 토마토로인해 0에서1이되고, 그 1된 토마토로 인해 다음번에는 1에서 2가 되어야 하므로.
struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

int main()
{
	int n, m, cnt = 0;

	queue<Loc> Q; //처음에 익은 토마토들을 다 넣어주고, 토마토가 익을때마다 넣어서 다음번에 사용하도록 한다.
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) Q.push(Loc(i, j)); //익은 토마토 만나면 넣어준다.
		}
	}


	while (!Q.empty()) { //네 방향 탐색으로 얻은 1에 대해 방향탐색이 끝나서 큐가 비면 for문이 돌아서 멀리 있는 1을 발견해 또 돈다.
		Loc tmp = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			if ((tmp.x + dx[i]) < 1 || (tmp.x + dx[i]) > m || (tmp.y + dy[i]) < 1 || (tmp.y + dy[i]) > n) continue;
			if (a[tmp.x + dx[i]][tmp.y + dy[i]] == 0) {
				a[tmp.x + dx[i]][tmp.y + dy[i]] = 1;
				dis[tmp.x + dx[i]][tmp.y + dy[i]] = dis[tmp.x][tmp.y] + 1;
				Q.push(Loc(tmp.x + dx[i], tmp.y + dy[i]));
			}
		}


	}


	int flag = false; //아래서 0이 있는 지 확인용도.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0) {
				flag = true; //안익은 토마토 하나라도 발견되면.
				cout << "-1";
				exit(0);
			}
		}
	}

	//최댓값 찾기.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (res < dis[i][j]) {
				res = dis[i][j];
			}
		}
	}

	return 0;
}