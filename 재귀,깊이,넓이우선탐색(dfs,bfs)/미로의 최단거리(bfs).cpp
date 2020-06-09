// 최단경로의 가짓수는 bfs로. 
// 경로수는 출발점에서 도착점까지 이동한 횟수.: 단순히 방문 가능한 곳 방문하면 cnt증가하는 것으로 하면 모든 0인 곳의 갯수만큼 cnt가 증가하게 되어버린다. 
// 최단거리를 봐야하므로, 이전의 좌표에서 현재의 좌표로 이동했을 때 +1로 누적시켜야한다.
// bfs이므로 종료 지점에 먼저 도착한게 최단거리이다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int a[8][8], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }, dis[10][10]; // 12시방향부터 시계방향으로.

struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

int main()
{
	int cnt = 0;
	queue<Loc> Q;

	for (int i = 1; i < 8; i++) {
		for (int j = 1; j < 8; j++) {
			cin >> a[i][j];
		}
	}

	Q.push(Loc(1, 1));
	a[1][1] = 1; //벽으로 만들어준다.

	while (!Q.empty()) {
		Loc x = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) { //상하좌우 돌면서 0인곳 만나면 1로 만들기, 푸쉬.
			//범위 벗어나면 예외. (2차원 배열 초기화 0때문에)
			if ((x.x + dx[i]) < 1 || (x.y + dy[i]) < 1 || (x.x + dx[i]) > 7 || (x.y + dy[i]) > 7) continue;
			if (a[x.x + dx[i]][x.y + dy[i]] == 0) {
				a[x.x + dx[i]][x.y + dy[i]] = 1;
				Q.push(Loc(x.x + dx[i], x.y + dy[i]));
				dis[x.x + dx[i]][x.y + dy[i]] = dis[x.x][x.y] + 1;//현재위치에 저장된 거리값에 +1
				cnt++;
			}
		}
	}
	if (dis[7][7] != 0) {
		cout << dis[7][7];
	}
	else cout << "-1";

	return 0;
}
	

	
