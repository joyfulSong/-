//가장자리로 오면 0열에서 더 넘어가면 안되고(위로만), 0행에서 더 넘어가면 안됨(왼쪽으로만)
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;
int arr[21][21], d[21][21];

int DFS(int a, int b) {
	if (d[a][b] > 0) return d[a][b];
	if (a == 0 && b == 0) return arr[0][0]; //값만 돌려주면 됨. 리턴받아서 올라가므로.
	else {
		// 0행으로 오면 왼쪽으로만 이동(열이동)
		if (a == 0) return d[a][b] = DFS(a, b-1) + arr[a][b];
		//0열로 오면 위로만 이동 (행이동)
		else if (b == 0) return d[a][b] = DFS(a - 1, b) + arr[a][b]; //두 경우는 동시에 나타나지 않으므로 if-else if
		d[a][b] = min(DFS(a - 1,b), DFS(a,b - 1))+arr[a][b]; //위쪽, 왼쪽.
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << DFS(n-1,n-1);
	return 0;
}