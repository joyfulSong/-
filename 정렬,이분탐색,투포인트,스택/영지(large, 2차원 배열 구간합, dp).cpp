// 2차원 배열 구간합, 제한시간 1초, 다이나믹 프로그래밍
// dp 배열에 [i][j]까지의 누적값을 저장한다. 
// 예: dp[2][3]에는 [1][1] [1][2] [1][3]
//                  [2][1] [2][2] [2][3] 까지의 모든 값이 더해져있다.
// [i][j]에는 [1][1]부터의 값이 모두 다 저장되어 있으므로, 일정범위의 누적값을 구하려면 앞선, 필요없는 범위의 누적값을 빼주는 식으로 접근한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[701][701], dy[701][701];

int main()
{
	int H, W, h, w, tmp, max = 2147000000;
	// tmp는 h*w범위의 값 저장용, max는 최대 크기 갱신용

	cin >> H >> W;

	for (int i = 1; i < H + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			cin >> a[i][j];
			dy[i][j] = dy[i - 1][j] + dy[i][j - 1] - dy[i - 1][j - 1] + a[i][j];
			// 같은행 한칸이전 + 같은열 한칸이전 - 두번더해진 대각선 왼쪽위 한칸의 값 + 원래 이 위치에 있는 값
		}
	}

	for (int i = h; i < H + 1; i++) {
		for (int j = w; j < W; j++) {
			// h*w칸만큼의 누적값은 h*w에 해당하는 위치인 오른쪽 아래 꼭짓점에 저장되어 있으니 거기서 출발해야함. 그전을 시작위치로 삼아봤자 h*w만큼의 값이 저장되어있지 않음
			tmp = dy[i][j] - dy[i][j - w] - dy[i - h][j] + dy[i - h][j - w];
			// ij까지 누적된 값에서 11~i,j-w까지 누적된 값 빼고, 11~i-h,j까지 누적된 값 빼주면 교집합 범위인 11~i-h,j-w가 두번빠졌으니 더한다.
		}
		if (tmp > max) max = tmp;
	}

	cout << max;
		return 0;
} 

