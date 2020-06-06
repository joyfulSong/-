//Kruskal 알고리즘: 최소 스패닝 트리 = 최소비용신장트리
//간선을 간선 가중치 값에 따라 오름차순으로 정렬하고 (n개의 노드를 연결하기 위해서는 n-1개의 간선이필요하므로) n-1개 선택.
//단! 회로가 되게하는 노드는 선택 x.
// 2 3 --> find(2)->9, find(3)-> 3이면 둘이 같은 집합이 아니므로 연결, 스패닝.
// 2 8 은 둘다 9를 return하게 되는데, 같은 집합내에 속한다는 것이므로 또 연결하면 회로가 되니 선택하지 않는다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int unf[101];

struct Edge {
	int edge;
	int node2;
	int val;
	Edge(int a, int b, int c) {
		edge = a;
		node2 = b;
		val = c;
	}
	bool operator<(Edge& b) {
		return val < b.val; //오름차순 정렬
	}
};

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

int Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main()
{
	int v, e, a, b, c, res = 0;
	vector<Edge> C; //세개 field가진 구조체형으로 저장해 sort하려고.

	cin >> v >> e;
	
	for (int i = 1; i < v + 1; i++) {
		unf[i] = i;
	}

	for (int i = 1; i < e + 1; i++) {
		cin >> a >> b >> c;
		C.push_back(Edge(a, b, c));
	}
	sort(C.begin(), C.end()); //오름차순 정렬

	//벡터에는 0부터 들어갔음
	for (int i = 0; i < e; i++) {
		// 앞 문제는 두 노드간을 모두 연결해 집합으로 만든 후에 어떤 원소가 집합에 있는지를 확인했다면,
		// 지금은 연결하기 앞서 두 노드의 집합 단위를 확인하고 난 뒤에 다를 경우 연결해준다.
		// 매 포문에서 연결정보가 갱신되므로, 루트노드가 생겨나간다.
		int fa = Find(C[i].edge);
		int fb = Find(C[i].node2);
		if (fa != fb) {
			res += C[i].val;
			Union(C[i].edge, C[i].node2);
		}
	}

	cout << res;
	return 0;
}