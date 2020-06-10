// dy[j] == j원 거슬러주는데 필요한 동전의 최소개수.
// 훨씬 큰값으로 초기화 해두고, 작은값 만나면 갱신한다.
// dy[j] = dy[j-c[i]]+1인데, 2원짜리를 사용한다면, dy[3] = dy[3-2]+1: 2원을 써서 3을 거슬러준다면, 1원거슬러주는데 필요햇던 동전수에 +1한것이다 == 1원한개 2원1개. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, cash; //동전종류, 거슬러줄 비용
	cin >> n;

	vector<int> c(n); //동전 저장용.

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	cin >> cash;
	vector<int> dy(cash + 1, 1000);

	dy[0] = 0;
	for (int i = 0; i < n; i++) { 
		for (int j = c[i]; j < cash + 1; j++) {  //아래 점화식에서 배열 인덱스값이 음수가 되는 것을 방지하도록.
			dy[j] = min(dy[j], dy[j - c[i]] + 1);
		}
	}
	cout << dy[cash];
}
//냅색 알고리즘은 동전 하나가 무한히 존재한다고 할때, 여러개의 동전에 대해 동전 한개씩으로 dy테이블을 동적으로 채워나가고 갱신하며 최소/최대값을 찾는것이다.