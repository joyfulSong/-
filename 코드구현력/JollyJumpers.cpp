//졸리점퍼: N개의 수열의 각 숫자 사이의 값이 1~	N-1을 구성할 때. 
// 1~N-1을 체크하는 배열을 만들어서 체크 위치가 겹치거나 여전히 0인지 본다. 

#include <iostream>
#include <vector>
#include <algorithm> // abs(절댓값)용
using namespace std;

int main()
{
	int N, pos;

	cin >> N;

	vector<int> a(N);
	vector<int> ch(N - 1); //체크용 

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < N; i++) {
		pos = abs(a[i] - a[i - 1]);
		if (pos > 0 && pos < N && ch[pos] == 0) ch[pos] = 1;
		// 만약 ch[6]을 참조하려고 하는데, 6은 N-1보다 커서 ch배열 범위 바깥이면, 논리오류가 발생.
		// 이를 방지하기 위해 pos의 범위 연산이 앞에 있으면, 앞선 연산에서 걸러지기에 ch[pos]부분까지 안넘어가서 방지해줌.
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;

}