// 그래프에는 무방향(양방향), 방향(단방향), 가중치(노드간 이동시 점수붙음)이 있음
// 인접행렬에 map을 저장함으로서 그래프를 만들 수 있다. 
// 그래프는 간선과 노드로 이루어져 있음.
// 인접행렬에 1로 체크 혹은 점수를 저장해, 탐색함으로서 이동가능한지 본다.
// 양방향이면 map[a][b] = map[b][a] = 1을 저장한다. 


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int map[51][51];

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;

	//숫자 1부터를 사용해줄거라 1부터 받는다.
	for (int i = 1; i < m + 1; i) { //노드간 간선 정보가 들어오므로 간선의 갯수만큼 받아야한다. 
		cin >> a >> b >> c;
		map[a][b] = c; // a정점에서 b정점으로 가중치 c증가.
 	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
} 

