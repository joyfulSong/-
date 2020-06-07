
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int ch[20], res[20], a[20]; // 중복사용 방지용, 답안 저장용, 초기 배열 저장용
int n, r, cnt = 0;
int DFS(int L) {
	if (L == r) {
		//오름차순으로 입력되었는데, 앞 수 부터 가지치기 하므로, 오름차순으로 값이 저장되어, 출력은 당연히 오름차순으로 된다.
		for (int i = 0; i < r; i++) {
			cout << res[i] << " ";
		}
		cnt++;
		cout << endl;
	}
	else {
		for (int i = 1; i < n + 1; i++) {
			//L노드 한개에 대해서 n개의 가지를 뻗어 가능한 수열의 트리를 만든다.
			if (ch[L] == 0) {
				res[L] = a[i]; // i번째 배열요소를 res에 넣어준다.
				ch[L] = 1;
				DFS(L + 1);
				ch[L] = 0; // DFS(L+1)은 L==r이 될때까지 스택프레임을 쌓으며 증가하다가, 출력후 빠져나와야 이 라인으로 돌아오므로, 그때 체크 해제를 해 줘서 그 숫자를 사용할 수 있게 해준다.
			}
		}
	}
}
int main()
{
	int n, r;
	cin >> n >> r;

	DFS(1);

	return 0;
}