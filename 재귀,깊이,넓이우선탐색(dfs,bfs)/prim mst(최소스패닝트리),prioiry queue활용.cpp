// 우선순위 큐의 최소힙정렬을 이용해 점수가 작은 것을 연결한다. 
// 임의의 시작노드를 선택후, 연결 가능한 노드들을 큐에 넣고, 가중치(->우선순위)가 작은 것을 선택해 (배열에 노드 체크(중복 노드 선택 안하도록), pop, 점수합산)
// 정점 n개가 다 만들어지면 (방향 그래프로 생각) 트리 완성.

//앞 문제의 포커스가 간선 추가에 있었다면, 이 방법은 노드 추가에 집중.

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int ch[101];

struct Edge {
	int edge;
	int val;
	Edge(int a, int b) {
		edge = a;
		val = b;
	}
	bool operator < (const Edge& b)const {
		return val > b.val; // (최소힙)
	}
};


int main()
{
	int v, e, a, b, c, res = 0;
	
	priority_queue<Edge> Q;
	vector<pair<int, int>> map[30]; //인접리스트 만들려고.

	cin >> v >> e;

	for (int i = 1; i < e + 1; i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c)); // 무방향 인접리스트 사용해야함.
	}

	Q.push(Edge(1, 0)); //정점1에서부터 시작함.
	while (Q.empty()) {
		// 큐가 비면 모든 정점을 선택한 것. 
		// 앞서 푸쉬되어 8노드가 큐에 존재하나 현재 최소값이 8이라서 ch가 되어버렸는데, 남아있는 8노드가 만약 최소힙이라면 pop하고 아래 if문에서 ch에 걸리므로 그냥 지나침. 그다음 top이 tmp에 들어감. 이와같이 필요없는게 큐에서 나가게됨.
		Edge tmp = Q.top(); 
		// 최소힙으로 정렬된 루트 노드를 저장해둠.
		// 예: 2번정점에서 3, 9 방문 가능하면, 가능한 노드+점수 다 푸쉬해두고, 9가 최소라 선택되었다면
		//     9에서 3을 바로 갈수는 없지만, 최소힙값이 3노드라서 다음 노드는 3이 선택되는 것. 
		//     즉, 푸쉬는 가능한 모든 노드를 넣고, 다음노드로 선택되는 것은 한 단계 이전에 선택된 노드에서 연결되는 노드가 아닐 수 있음.
		Q.pop();
		int v = tmp.edge; //현재 노드
		int cost = tmp.val; // 가중치값
		if (ch[v] == 0) {
			//이노드를 처음 방문하는것이라면,
			res += cost; //현재 노드 방문하는데 드는 비용을 더하고 방문했다고 체크.
			ch[v] = 1;
			// 다음번 방문 가능한 노드들: map[v]의 인접리스트 내에 저장된 노드들의 번호와 점수를 Edge형으로 큐에 푸쉬함.
			// 최소힙으로 정렬되어, 가중치가 가장 적은게 맨 위에 있게됨. 
			for (int i = 0; i < map[v].size(); i++) {
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	cout << res;
	return 0;
}