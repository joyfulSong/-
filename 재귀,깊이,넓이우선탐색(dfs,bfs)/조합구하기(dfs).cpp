//조합: n개 원소중 r개 뽑기 (외우기)
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;
int n, r;
int ch[20];

void DFS(int s, int L) {
	//0,0부터 출발해 ch배열에 경우의 수를 저장한다. r개를 모두 선택하면 종료
	if (L == r) {
		for (int i = 0; i < r; i++) {
			cout << ch[i] << " ";
		}
		cout << endl;
	}
	else {
		// 0부터 돌기때문에 n보다 작다.
		for (int i = s; i < n; i++) {
			ch[L] = i; //레벨 0부터 ch에 경우의 수 넣기. (L==r 될때까지 다 돌고나서 맨 바텀 스택인 L=0으로 돌아오므로 i=1이 되고, ch[0] = 1이 들어간다. 
			// s로 들어온 값에 대해 ch에 저장해 처리하고 그 다음수를 넘겨줌. 현재 수를 제외한 다음수부터 for문이 돌기에 중복이 되지 않게 경우의 수를 생성가능.
			// 스택 프레임에는 현재의 for문 범위와 돌기를 끝낸 i가 저장되어있어 그 다음수부터 돌 수 있게 됨.
			DFS(i + 1, L + 1);
		}
	}
}
int main()
{
	cin >> n >> r;
	DFS(0, 0);

	return 0;
}