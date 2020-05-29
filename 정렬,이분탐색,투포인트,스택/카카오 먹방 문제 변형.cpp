// 시뮬레이션
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, pos = 0, cnt = 0, tot = 0;
	// 작업 갯수, 정전되는 시간(k초 초과), 마지막 작업에서 맨앞으로 돌리는 용도, 0이 된곳 제외하고 초단위 세기위해
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i];
	}

	cin >> k;
	if (k >= tot) {
		cout << "-1"; // 정전 시간보다 작업시간이 작으면 모든 작업이 완료되었으므로. 
		return 0; // main 종료.
	}

	while(true) {
			if (pos >= n) pos = 0; //벡터가 0부터 시작해서. 
			if (a[pos] != 0) {
				a[pos]--;
				// pos++; pos가 이 if문 아래에 있으면 0인 지점에서 지나가지 못함.
				cnt++;
				if (cnt == k) break;
			}
			pos++;
		}

	//pos를 하나씩 증가시키며 남아있는 곳 찾아서 위치 출력.
		while (true) {
			pos++;
			if (pos >= n) pos = 0;
			if (a[pos] != 0) cout << pos;
		}
		return 0;
}

