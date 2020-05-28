//조건에 부합하는 답을 찾고, 그 답이 최적인지 범위를 좁히며 찾는 '결정알고리즘'에 이분검색이 응용됨
//배열 내의 값을 모두 더한 1~45 안에 답이 있으므로 그 안에서 답을 찾는다.
//mid(곡의 길이, 답후보)에 곡들을 담을 수 있는지 본다.  가능하면 답으로 저장하고, 
//가능한 답보다 작은 답들이 최적 후보이므로, 배열을 축소해 검색한다. (lt, rt조정)

//count함수에서 곡들을 담아본다. for문에서 다음 곡을 담아보고 넘치면, cnt 증가, sum을 새로 시작한다. 
// 안넘으면 계속 담는다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//함수에서 써줄거라 전역
int n; 
int a[1001];

// mid의 저장용량으로 m개로 담을 수 있는지 확인, 담은 갯수(사용한 dvd 갯수) 리턴
int Count(int s) {
	int i, cnt, sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + a[i] < s) sum += a[i]; //안넘으면
		else { //넘으면: sum + a[i] > s
			// 반례: s가 1이면, if문을 모두 다 통과하고 계속 else로 cnt가 증가하며 9개가 된다.
			// main의 Count(mid) <= m에서 true 이므로 res = 1로 출력이 되는데, 
			// 저장용량이 1이면 최대길이 9분을 넣지못하게 된다. 
			// 따라서 main의 if문에 조건을 추가한다.
			cnt++;
			sum = a[i]; 
		}
	}
	return cnt;
}
int main()
{
	int m, lt = 0, rt = 0, mid, res, max = -2147000000; //rt는 입력받을 때 더해나감, res가 답저장용
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		rt += a[i];
		if (a[i] > max) max = a[i];
	}

	while (lt <= rt) {
		mid = (lt + rt) / 2;
		// mid >= max: mid는 최대 노래 길이 이상이어야 노래 한곡을 담을 수 있는데, 최대 노래길이보다 작은 값이 답으로 출력되는 반례.
		if (mid >= max && Count(mid) <= m) { //m보다 작은 갯수에도 담기는 거면 저장용량이 크다는말. 범위를 mid보다 좁혀야함.
			res = mid;
			rt = mid - 1;
		}
		else // 담아본 dvd 갯수가 m보다 크면 저장용량이 부족하다는 말. 늘려야 하므로 mid우측을 답의 후보로 생각.
			lt = mid + 1;
	}
	cout << res;
	return 0;
}

