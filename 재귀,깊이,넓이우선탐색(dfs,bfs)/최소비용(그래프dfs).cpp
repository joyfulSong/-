// 최소비용은 다익스트라 알고리즘으로 푸는게 간단함.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[30][30], ch[30], n, cost = 2147000000; //min이라고 하니 전역변수로서 모호하다고 뜸.

void DFS(int v, int sum) {
	if (n == v) {
		if (sum < cost) cost = sum;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (map[v][i] != 0 && ch[i] == 0) {
				ch[i] = 1;
				DFS(i, sum+ map[v][i]);
				// 스택프레임에 DFS(노드, 점수)가 저장이 되어있으므로, 다시 이 스택프레임으로 돌아오면 저장되어있던 점수부터 다시 누적할 수 있다.
				ch[i] = 0;

			}
		}
	}
}

int main()
{
	int m, a, b, c;
	cin >> n >> m;

	for (int i = 1; i < m; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	ch[1] = 1;
	DFS(1, 0); //sum으로 0부터 받아와서 출력.

	cout << cost;
	return 0;
}

