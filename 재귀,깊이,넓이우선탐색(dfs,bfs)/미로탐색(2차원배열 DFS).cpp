
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[8][8], ch[8][8], cnt = 0;
int dx[4] = { -1, 0, 1, 0 }; // 9시 12시 3시 6시
int dy[4] = { 0,1,0,-1 };

void DFS(int a, int b) {
	int aa, bb; // 격자판에서 상하좌우로 이동하는 위치 저장용
	if (ch[7][7] == 1) {
		cnt++;
	}
	else {
		for (int i = 0; i < 4; i++) {
			aa = a + dx[i];
			bb = b + dy[i];
			if (aa < 1 || aa > 7 || bb < 1 || bb>7) continue; //격자판 바깥.
				if (map[aa][bb] == 0 && ch[aa][bb] == 0) {
					ch[aa][bb] = 1;
					DFS(aa, bb);
					ch[aa][bb] = 0;
				}
			}
		}
	}

int main()
{
	for (int i = 1; i < 8; i++) {
		for (int j = 1; j < 8; j++) {
			cin >> map[i][j];
		}
	}

	ch[1][1] = 1;
	DFS(1,1);
	cout << cnt;
	return 0;
}

