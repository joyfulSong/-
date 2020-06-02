// 어떤 원소를 입력하지 않는 경우도 있어야함.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, cnt = 0, a[11], path[11]; //a는 원소 담는용, path는 참일 때 배열 출력용

void DFS(int L, int s) {
	if (L == n + 1) { //이 종료조건이 없으면 sum이 m과 같아질때까지 계속 증가함. 레벨의 한계를 정해둬야. 
		if (s == m) {
			cnt++;
			for (int i = 1; i < L; i++) { //n이 4이고 아래 else문에서 L이 5가 되면 이 if문으로 들어오므로
				cout << path[i];
			}
			cout << "\n";
		}
	}
	// 스택프레임에서 끝 레벨에 도달시, m값과 비교 후 진행중이던 함수라인으로 돌아가 트리를 확장한다.
	else {
		path[L] = +a[L];
		s += a[L];
		DFS(L + 1, s); //sum에 L+1에 해당하는 원소를 더하고 싶은것이므로 a[]를 넘기는게 아니라 인덱스만 넘긴다.
		path[L] -= a[L]; // path[L] -= a[L] path[L] = -a[L] 서로 다르니 주의.
		s -= a[L]; 
		DFS(L + 1, s);
		path[L] = 0;
		DFS(L+1, s); //안더해도 다음 레벨로 넘어가야한다.
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}

	DFS(1, 0);

	if (cnt == 0) cout << "-1";
	else cout << cnt;


	return 0;
}

