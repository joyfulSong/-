//원형으로 보여도, 1차원 배열 사용해주고 도는 지점을 처음으로 돌리는 인덱스를 사용해주면 된다.
// 배열에서 실제로 내보내지 않아도, 1, 0으로 체크해준다. 
#include <iostream>
// 시뮬레이션
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, pos = 0, bp = 0, cnt = 0;
	// pos는 배열을 도는 용도
	// bp는 나간 왕자의 수를 카운트 하는 용도
	// cnt는 배열에서 k가 되는지 확인하는 용도

	cin >> n >> k;

	vector<int> prince(n + 1); // 1부터 돌거라서.

	while (true) {
		pos++; //1부터 시작. 
		if (pos > n) pos = 1; // 8까지 돌고 9되면 바로 1로 바꿈
		if (prince[pos] == 0) {
			// 0인지점만 돈다. 1인곳은 나간것으로 생각
			cnt++; 
			if (cnt == k) {
				prince[pos] = 1; //k번째가 되면 1로 바꿔준다.
				bp++;
				cnt = 0;
			}
		}
		if (bp == n - 1) break; 
	}

	for (int i = 1; i < n + 1; i++) {
		if (prince[i] == 0) cout << prince[i];
	}
	return 0;
}

