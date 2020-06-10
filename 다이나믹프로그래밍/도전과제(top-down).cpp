// 탑다운은 원래 재귀를 사용한다고 하지(넓은 의미의 동적계획법, 작은문제의 답을 저장해두고 큰 문제에서 사용하므로), 동적계획법은 원래 바텀업이 동적계획법
// 마지막 계단, 돌에 도착하려면 그전에 2칸 전에 도착햇거나 1칸전에 도착햇거나. (돌다리 문제는 마지막 돌에 도착하는게 아니라, 그 다음인 n+1에 도착해야하므로 d[n+1]을 구한다.
// 돌을 딛을수 없는 위치면, 그자리는 d[x]= 0으로 저장해둔다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;
int d[50];
int DFS(int n) {
	if (d[n] > 0) return d[n]; //이미 값이 있으면
	if (n == 1 || n == 2) return n;
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



