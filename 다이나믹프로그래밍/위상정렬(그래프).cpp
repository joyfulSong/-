// 위상정렬은 일의 선후관계가 얽혀있을 때 일하는 순서를 찾는 것으로 답이 여러개가 될 수 있다.
// 인접행렬을 2차원으로 방향그래프로 만든다. 
// 연결된 간선의 개수를 차수라고 하는데, 들어오는 간선을 진입차수라고 부른다. 이것이 위상정렬에서 중요. (먼저 해야할 작업의 갯수를 나타내므로; j작업에 연결된 앞선 i작업들이 있다는 것)
// 작업을 입력받을 때 그래프를 만들며 진입차수를 저장해야 한다. a, b중 b가 다음작업이므로 그 작업에 +1을해 진입차수를 degree라는 배열에 저장한다. 
// 진입차수가 0인것부터 큐에 넣고, 빼면 그 작업이 끝난것이므로 출력하고, 이 작업이 영향을 준 모든 그래프(i가 빠졌으면 [i][모든]그래프를 탐색해 degree를 감소시켜, 0되면 또 큐에 넣는다.
// bfs처럼 while문 돈다.

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n;
	vector<vector<int>> graph(n + 1, vector<int>(0));
	vector<int> degree (n + 1);
	queue<int> Q;
	
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		graph[a][b] = 1; //방향그래프
		degree[b]++;
	}

	// 0인것 찾아 큐에넣기
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) Q.push(i);
	}

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		cout << now << " "; //꺼낸작업은 끝난작업
		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 1)
				degree[i]--; //now와 연결되어있던 그래프가 있으면 1로 마킹되어있을거고, (비용없으니 그냥 1) 그 i에 대한 degree를 감소시켜준다.
			if (degree[i] == 0) Q.push(i);
		}
	}


	return 0;
}



