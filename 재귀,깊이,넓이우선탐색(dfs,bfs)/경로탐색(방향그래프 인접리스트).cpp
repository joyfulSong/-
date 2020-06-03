// 64번(인접행렬)과 다르게 인접리스트 사용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> map[30];
//벡터 자체를 30객체 만들고, 각 객체에 push_back으로 이동가능한 노드 정보를 넣는다.
//map[0]|[1]|[2]|[3]|[4]....
//       [2]
//       [3]
//       [4]
// 1번 vertex에서 방문가능한 노드는 2, 3, 4이다.

//인접행렬은 1, 0 이 섞여서 전체 n*n행렬에 저장되어 있으니
//어떤 vertex가 방문가능한지 보려면 map[n][n]에서 i=1, j=1~n까지 다돌아야했는데,
//인접리스트는 map[1].size()만큼만 돌면 1번 노드가 방문 가능한 노드의 갯수가 바로 나와서 그만큼만 돌면된다.

int ch[30], cnt = 0, n;
// ch[1]은 1번 노드를 방문했는지. 이는 ch[map[v][i]]를 통해 1, 0으로 체크가능한데,
// v에서 i로 방문가능하다고 저장되어있는 노드가 2라면 ch[2] = 1로 체크해주면 되는 것이다. 

void DFS(int v) {
	if (v == n) {
		cnt++; //n번 노드 방문하면 DFS끝
	}
	else {
		for (int i = 0; i < map[v].size(); i++) {
			if (ch[map[v][i]] == 0) {
				ch[map[v][i]] = 1;
				DFS(map[v][i]);
				ch[map[v][i]] = 0;
			}
		}
	}
}
int main()
{
	int m, a, b;

	cin >> n >> m;
	for (int i = 1; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b); // a번 vertex는 b를 방문 가능하다고 뒤에서 밀어넣어 저장. (아래서부터 쌓음)
	}

	ch[1] = 1;
	DFS(1); //1번 노드부터 탐색 시작.

	return 0;
}

