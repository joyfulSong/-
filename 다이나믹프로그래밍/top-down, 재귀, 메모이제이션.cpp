
//재귀호출, 메모이제이션사용: top-down
// 길이 7짜리를 자르는 방법은 끝이 1개만 남을 때: 길이 6짜리 자르는 방법 + 끝이 2개남을 떼: 길이 5짜리 자르는 방법

//      d[7]
// d[6]        +       d[5]
// d[5] + d[4]      d[4] + d[3]

// d[x]를 반복적으로 구하지 않아도 되게 dy테이블에 저장해두고, 이미 앞서 값을 구해놔서 0이 아니면 값을 바로 리턴. (불필요한 가지 제거: 컷 에지)
// 그래서 탑다운 방식에 메모이제이션이 필요하다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int d[50];
// 전위 순회이므로, 
// d[4]
// d[3]        + d[2]
// d[2] + d[1]
// d[2]까지 내려오고, return 2, 부모노드인 n==3으로 올라갔다가, 우측자식노드인 dfs(1), return 1
// 2+1을 n==3인 dfs 스택으로 넘어가 3리턴, d[3] = 3 저장, n==4로 스택업 했다가 다시 dfs(2)로 내려와 이미 저장되어있으니 2리턴
// 3+2를 d[4]에 리턴, 저장.

int DFS(int n) {
	if (d[n] > 0) return d[n]; //이미 값이 있으면.
	if (n == 1 || n == 2) return n; // 1 또는 2 숫자를 바로 리턴
	else {
		d[n] = DFS(n - 1) + DFS(n - 2);
	}
 }
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << DFS(n);
	return 0;
}



