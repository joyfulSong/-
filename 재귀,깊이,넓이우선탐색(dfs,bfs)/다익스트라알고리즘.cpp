// 최소 거리 비용
//다익스트라는 간선값이 양수여야만 적용할 수 있다. 노드 번호가 증가한다면 비용값이 더 커질 수 밖에 없음
// 가중치 방향 그래프이므로 인접리스트로 푼다.
// dist라는 배열을 만들고, 모두 int의 최댓값인 2^31-1 == 2147000000으로 초기화 해둔다. 여기엔 1에서 i로 가는데 드는 최소비용을 저장한다.

// 노드에서 이동가능한 노드들을 탐색하며 dist 배열값을 갱신한다. (기존에 저장된 값보다 작으면 갱신)
// dist 배열 중 최솟값을 새로운 부모 노드로 선택하고 돈다. 배열을 도는데 시간이 걸리니 logN으로 해결가능하도록 최소힙으로 부모노드를 선택한다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int vex;
	int dis;
	Edge(int a, int b) {
		vex = a;
		dis = b;
	}
	bool operator < (const Edge& b)const {
		return dis > b.dis; // 내림차순, 최소힙
	}
};

int main()
{
	priority_queue<Edge> Q;
	vector<pair<int, int>> graph[30]; //인접리스트 저장용, 큐에서 노드 정보를 얻으면 연결정보는 map으로 얻음.

	int n, m, a, b, c;
	cin >> n >> m;

	vector<int> dist(n + 1, 2147000000); // dist저장용. 위의 Q로 최소힙을 사용해 dist 최소값 선택하려고.
	for (int i = 1; i < m + 1; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c)); 
	}

	Q.push(Edge(1, 0));
	dist[1] = 0;

	while (!Q.empty()) {
		int now = Q.top().vex;
		int cost = Q.top().dis;
		Q.pop();

		if (cost > dist[now]) continue; // 저장된 dist보다 top으로 꺼낸 값이 더 크면 최소비용 아님. 갱신 x
		
		for (int i = 0; i < graph[now].size(); i++) {
			//now에서 연결가능한 모든 노드 탐색
			int next = graph[now][i].first;
			int nextDis = cost+graph[now][i].second;
			if (dist[next] > nextDis) { //연결 가능한 노드에 대한 비용이 기존에 저장된 값보다 작으면 갱신
				dist[next] = nextDis;
				Q.push(Edge(next, nextDis)); // 갱신후 큐에 넣어서 이 노드를 부모노드로 삼아 또 다른 노드를 탐색하도록 한다.
			}
		}
	}
	for (int i = 2; i < n + 1; i++) {
		if (dist[i] != 2147000000) cout << i << " : " << dist[i] << "\n";
		else cout << i << " : impossible" << "\n";
	}
	return 0;
}