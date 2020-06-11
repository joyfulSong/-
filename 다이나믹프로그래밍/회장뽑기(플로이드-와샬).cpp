// 1번이 2번과 바로 친구 1점
//       3번과 친구한명 거친 친구 2점
//       4번과도 3번처럼
//       5번과는 친구 두명거친 친구 3점
// 이면 1번은 3점을 점수로 한다는게 문제에서의 점수의 의미. 
// 회장은 최솟값을 가져야 한다: 모든 정점과의 거리 들중 최댓값이 한 노드의 점수인데, 이것이 최소가 되도록 하려면, 모든 정점과의 최단거리를 갖는 노드여야 한다.
// 
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

main()
{
	ios_base::sync_with_stdio(false);
	int n, a, b, score; // 회장점수 저장용
	cin >> n;
	vector<vector<int>> dis(n + 1, vector<int>(n + 1, 100));
	vector<int> res(n + 1);

	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0; //자기자신 초기화
	}

	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dis[a][b] = 1;
		dis[b][a] = 1; // 친구사이이므로 1로 초기화 양방향 그래프

	}

	// i친구와 j친구가 k친구를 거쳐서 친구인지 확인한다. 
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
				//i와 j가 친구가 될 수 있는 경로가 많아도, 최솟값을 저장: 
				//각 회원의 점수를 정할 때 주의할 점은 어떤 두 회원이 친구 사이이면서 동시에 친구의 친구사이이면, 이 두 사람은 친구사이라고 본다.
			}
		}
	}
	
	//한회원의 점수는 각 회원과의 점수중 최댓값이다. (문제의 정의: 친구친구친구사이면 그걸 점수로한다고)
	//회장은 점수가 가장 작은것이므로 최댓값을 구한 다음, 각 최댓값중 최소가 되는 것을 구해 score에 저장
	score = 100;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res[i] = max(res[i],dis[i][j]); //i하나 잡고 한 행에 대해 전체 열을 돈다.
		}
		score = min(score, res[i]);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (res[i]==score) cnt++; //회장점수 발견되면 증가
		}
	}
	cout << score << " " << cnt << "\n";
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (res[i] == score) cout << i << " ";
		}
	}
	
	return 0;
}



