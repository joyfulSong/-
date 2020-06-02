 //아이패드 알고리즘강의 노트 41페이지 그림 참고 혹은 강의 그림참고(64강)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int	n, map[30][30], ch[30], cnt = 0; //cnt는 가능한 갯수 카운팅 용, ch는 중복방문하지 않도록 함
// DFS(2-->5) 방문후 v==n으로 끝까지 가서 함수 끝나고 (if-else이므로 if문 돌고나면 함수 끝남)
// 스택프레임에 이전인 DFS(2)로 돌아가면 ch[5]를 체크해제해야함.
// v==n이 되어 스택프레임이 꽉 찰때까지를 카운트 한번으로 치므로, 그 한 카운트 안에서는 노드를 중복 방문하지 않기 위해서이다. 

void DFS(int v) {
	if (v == n) {
		cnt++;
	}
	else {
		//인접행렬로 넘어갈수 있으면 넘어가도록 for문으로 인접행렬을 탐색한다.
		for (int i = v; i < n + 1; i++) {
			if (map[v][i] == 1 && ch[i] == 0) {
				// 갈 수 있다고 체크되어있고 아직 방문 안한 상태라면,
				ch[i] = 1; // 방문했다고 체크.
				DFS(i); // v에서 i로 이동
				ch[i] = 0;
			}
		}
	}
}

int main()
{
	int m, a, b;
	cin >> m;
	for (int i = 1; i < m + 1; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	ch[1] = 1;
	DFS(1); // 재귀로 dfs(완전탐색)으로 가능한 모든 경우를 찾는다.
	
	return 0;
}
 