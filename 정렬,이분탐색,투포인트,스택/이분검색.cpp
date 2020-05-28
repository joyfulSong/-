//이분 검색은 선 정렬(오름차순), 후 검색
// 배열의 양끝을 가리키는 lt, rt 포인트를 만들고, 가운데 (lt+rt)/2를 가리키는 mid를 만들어
// 찾고자 하는 key값과 mid를 비교해 
// mid > key이면 현재의 mid위치의 왼쪽에 있는 배열만 참조하면 되므로 mid-1을 rt로 두고 탐색
// mid < key이면 mid위치 오른쪽에 답이 있으므로 mid+1를 lt로 둔다.
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	int n, lt, rt, mid, key;

	cin >> n >> key;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; // cin >> tmp; a.push_back(tmp);
	}
	sort(a.begin(), a.end()); // 선 정렬, 얘네는 포인터 역할이라 참조하면 인덱스 내 저장된 값 가져옴.

	lt = 0;
	rt = n - 1;

	while (lt <= rt) { // lt와 rt는 왼쪽, 오른쪽의 위치에 놓여야 하는데 자료가 발견되지 않으면 교차가 되는 것을 방지하기 위해

		mid = (lt + rt) / 2; //정수형이므로 배열의 크기가 짝수개이면 소수점 없애고 내림한 값이 들어감

		if (mid == key) cout << mid + 1;
		else if (mid > key) {
			rt = mid - 1;
		}
		else { //mid < key
			lt = mid + 1;
		}
	}


	return 0;
}


