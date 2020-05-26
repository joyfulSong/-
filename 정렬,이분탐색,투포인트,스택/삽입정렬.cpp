// 삽입 정렬, 대기업 손코딩 유형문제로 자주 나옴.
// i for문이 돌때 tmp에 배열한개를 넣고, j for문에서 0부터 i-1까지 돌며 tmp보다 큰 수를 만나면 뒤로 한칸씩 밀어준다.
// (한칸 뒤로 밀어주면 현재 tmp에 넣어둔 i번째에 들어가는 것이다.)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, tmp, j;
	int ch[101];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch[i];
	}

	for (int i = 1; i < N; i++) { //j가 i-1이므로 1부터 시작한다. 
		tmp = ch[i];
		for (j = i - 1; j >= 0; j--) {
			if (ch[j] > tmp) {
				ch[j + 1] = ch[j];
			}
			else
				break;
		}
		ch[j + 1] = tmp;//j가 끝난 지점은 ch[j] < tmp인 곳이므로 (break한번도 안했으면 -1), 그 다음지점인 j+1에 넣는다.
	}

	for (int i = 0; i < N; i++) {
		cout << ch[i] << " ";
	}
	return 0;
}
