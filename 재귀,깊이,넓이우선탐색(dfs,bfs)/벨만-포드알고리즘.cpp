//벨만 포드는 시작노드 ~ 끝노드간의 간선 갯수를 최소로 사용할 수 있을 것이다 라는 접근이다. 노드가 n개 이면 간선의 최대수는 n-1로 그 안에서 시작~끝이동의 최소비용을 찾는다.
// n-1개가 넘는 이동이 필요하다는 것은 회로가 발생한다는 것이다: 노드 2를 두번 방문하는데, 첫번째 방문 때 5, 두번째 방문 떄 4라면 비용이 줄어드므로 음의 사이클이 된다.
//전제는 벨만포드로 풀려면 음의 사이클이 발생하지 않아야 한다는 것이다.
// 그래프화 시키지 않고 구조체형 1차원 벡터에 저장해두고 탐색한다.

// x축: 모든 노드에 대해서, y축: 1부터 간선 n-1개까지. --> 바깥 포문은 간선 갯수, 안쪽 for문은 노드갯수.
// dist 1차원 배열에 점수를 무한대로 초기화 후, 노드간의 이동 비용이 더 작은것이 발생하면 갱신한다. 

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int s;
	int e;
	int val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
};

int dist[101];

int main()
{
	int n, m, s, e, a, b, c;
	vector<Edge> Ed;

	cin >> n >> m;

	//벡터에 간선 정보 초기화
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}

	//dist값 초기화, 무한대로.
	for (int i = 1; i < n + 1; i++) {
		dist[i] = 2147000000;
	}

	cin >> s >> e;
	dist[s] = 0; //s에서 s가는데 0
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < Ed.size(); j++) {
			int u = Ed[j].s;
			int v = Ed[j].e;
			int w = Ed[j].val;
			//저장된 간선정보를 꺼내어 dist비교한다.
			if (dist[u] != 2147000000 && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
			// dist[u]; 출발노드가 갖고있는 점수가 무한대가 아니고(무한대면 비용을 더해도 무한대이니)
			// 출발노드 + 비용값이 기존에 도착노드에 대해 저장된 값(dist[v]에는 v까지 오는데 드는 비용이므로)보다 작으면 갱신
			// 엣지 벡터값이 변하지 않고, 앞서 for문이 1회 돌았다면 돌아서 갱신된 내용을 바탕으로 2회의 계산이 되믈 간선 두번 썼다고 보는 것이다. 
		}
	}

	//앞서 n-1번 간선 사용까지 구했는데, n번쨰에 최소비용이 발생한다면 음의 사이클이 존재한단것.
	for (int j = 0; j < Ed.size(); j++) {
		int u = Ed[j].s;
		int v = Ed[j].e;
		int w = Ed[j].val;
		
		if (dist[u] != 2147000000 && dist[u] + w < dist[v])
		{
			cout << "-1";
			exit(0);
		}
	}

	cout << dist[e];
	return 0;
}