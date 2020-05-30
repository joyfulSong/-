
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int H, W, h, w, res = 0, max = -2147000000;
	cin >> H >> W;
	int a[50][50];

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
		}
	}

	cin >> h >> w;

	// i, j는 영지의 왼쪽위 꼭지점으로, 한칸 씩 이동하는게 맞음. 
	int i = 0, j = 0;
	for(i = 0; i < H-h+1; i++) {
		for(j = 0; j < W-w+1; j++) {
			for (int k = i; k < h+i; k++) { //영지내의 점수위한 k,l은 시작점이 i,j이다. 
				for (int l = j; l < w+j; l++) {
					res += a[k][l];
				}
			}
			if (res > max) max = res;
		}
	}

	cout << res;
		return 0;
}

