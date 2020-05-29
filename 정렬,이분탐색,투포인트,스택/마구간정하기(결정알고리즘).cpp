// 이분탐색 응용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 함수에서도 써야해서

int setHorse(int len, vector<int> a) {
	int cnt = 1, p = a[0];
	// 맨 앞에 말 한마리 넣고, 좌표이동하면서, 이동된 좌표와 포인트와의 거리가 현재의 정답후보인 len보다 작거나 같으면 말을 넣을 수 있으므로 cnt증가, 포인트 이동.
	for(int i = 1; i < n; i++){
		if (a[i] - p >= len) {
			cnt++;
			p = a[i];
		}
	}
	return cnt;
}

int main()
{
	int	c, lt = 0, rt, mid, res;
	vector<int> a; //int *a = new int[n+1]

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	rt = a.back();

	while (lt <= rt) {
		mid = (rt + lt) / 2;

		if (setHorse(mid, a) >= c) {
			// c보다 말을 더 놨으면 너무 mid가 작다는것. 하지만 c의 말을 배정가능하니 답은 되니 저장.
			res = mid;
			lt = mid + 1;
		}

		//mid값으로 말을 배정해본 결과 c보다 작으면 mid가 너무 커서 말을 다 못놓았단 말.
		else { // (setHorse(mid, a) < c)
			//mid 줄인다.
			rt = mid - 1;
		}
	}
	cout << res;
	// delete[] a; 동적할당이면.


	return 0;
}
