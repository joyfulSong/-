// 상태트리는 레벨 확인을 가시화해서 볼 수 있다.
// 각 노드에서 다음 노드로 이동가능한 것을 그래프로 레벨화 해서 표현하면 된다.
//    5
//  / | \
// 6  4  10
// .........

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int ch[10001], dis[10001], dx[3] = { -1, 1, 5 };

int main()
{
	int s, e, x;
	queue<int> q; //크기 안정해도 됨 대신 q.pop(). 크기 정하면 q->pop()

	cin >> s >> e;

	q.push(s);
	ch[s] = 1;

	while (!q.empty()) {
		x = q.front();
		q.pop();
		
		for (int i = 0; i < 3; i++) {
			//예외처리
			if (x + dx[i] <= 0 || x + dx[i] > 10000) continue;
			if (ch[e] != 0) break;
			if (ch[x + dx[i]] == 0) {
				ch[x + dx[i]] = 1;
				dis[x + dx[i]] = dis[x] + 1;
				q.push(x + dx[i]);
				
			}
		}
	}

	cout << dis[e];
}