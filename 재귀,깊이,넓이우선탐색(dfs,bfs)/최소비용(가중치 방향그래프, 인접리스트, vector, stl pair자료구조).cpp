#include <iostream>
#include <vector> // pair의 헤더인 utility를 vector나 algorithm이 이미 갖고 있음. 
#include <algorithm>
// 두개의 데이터 형을 한쌍으로 묶는것
// pair<int, char> p;
//p = make_pair(10, 'T'); 가능

// #define x first
// #define y second
using namespace std;

int n, ch[30], cost = 2147000000;
vector<pair<int,int> > map[30]; //n으로 잡으면 안됨. constant 값이어야함.

void DFS(int v, int sum) {
	if (n == v) {
		if (sum < cost) cost = sum;
	}
	else {
		for (int i = 0; i < map[v].size(); i++) {
			if (ch[map[v][i].first] == 0) {
				// v노드에서 map[v][0].first에 저장되어있는 이동가능한 다음노드로 간적이 없다면
				ch[map[v][i].first] = 1; // map[v][0].x 가능.
				DFS(map[v][i].first, sum + map[v][i].second);
				ch[map[v][i].first] = 0;
			}
		}
	}
}
int main()
{
	int m, a, b, c;
	cin >> n >> m;

	for (int i = 1; i < m + 1; i++) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c }); // push_bakc(make_pair(b,c));
	}

	ch[1] = 1;
	DFS(1, 0);

	cout << cost;
}