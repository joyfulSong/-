// 들어온 순서대로 쌓는것이 아니라, 벽돌을 그 중에 알맞게 선택해서 쌓는것. 
// 내림차순으로 먼저 정렬을 해두어서 밑면의 넓이는 선택에서 생각하지 않아도 되게한다.
// dy[i]에는 i번째 벽돌을 맨 위에 두었을 때의 최대 높이로 한다. 
// : 앞선 번호의 벽돌(밑면 넓이가 더 넓은 벽돌이) 자신보다 무겁고, 그 무거운 벽돌중 저장된 높이가 가장 높은 것에 + 자신의 높이.
//   자신보다 가벼우면 자신 높이만 저장한다.

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

struct Bricks {
	int m, w, h;
	Bricks(int a, int b, int c) {
		m = a;
		w = b;
		h = c;
	}
	bool operator < (const Bricks& bb)const {
		return m > bb.m; // 내림차순. 넓이가 넓은게 앞에 오도록.
	}
};

int main()
{
	int n, a, b, c, res=0;
	cin >> n;

	vector<Bricks> brick, vector<int> dy(n); //0부터 돌것임. brick는 push_back할거라서 크기 안잡아도 됨.

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		brick.push_back(Bricks(a, b, c)); // 사용자정의 자료형으로 넣을 때는 pushback
	}

	sort(brick.begin(), brick.end()); //내림차순 정렬, m에대해서.

	// 맨앞의 dy는 넣어줘야 크기 비교 가능
	dy[0] = brick[0].h;
	for (int i = 1; i < n; i++) {
		int max_h = 0; // 최대 높이 비교용
		for (int j = i - 1; j >= 0; j--) {
			if (brick[j].w > brick[i].w&& dy[j] > max_h)
				max_h = brick[j].h;
		}
		dy[i] = max_h + brick[i].h;
		res = max(res, dy[i]); // 지금 얻은 dy[i]와 현재까지 제일 높이가 컸던 값과 크기 비교해 큰것으로 답 갱신
	}

	cout << res;
	return 0;
}

