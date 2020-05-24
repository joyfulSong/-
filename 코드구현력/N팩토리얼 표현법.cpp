// 소인수 분해: 소수들을 제외한 수들은 2, 3, 5, 7...로 나눠 떨어지는 수이다. 
// 따라서 소수를 미리 구해놓고서 판단하려고 하지 않고, N!을 구성하는 수들을 나누는 시도를 할 때 
// j = 2 부터 시작해서 나머지가 0이 아닐때까지 나눈 뒤에, 더이상 나눠지지 않으면 j를 증가시켜 다음 수로 넘어간다. 
// 나머지가 0이 아닐때까지 나눴기 때문에, 앞선 소수의 배수로 이루어진 수들은 넘어가게 된다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, tmp, j;
	cin >> N;

	vector<int> ch(N);

	// 5! = 5 * 4 * 3 * 2 * 1을 하나씩 소인수분해한다.
	for (int i = 0; i < N; i++) {
		tmp = i; //i는 for문용이므로 건드리지 않는다. 
		j = 2;
		while (1) {
			if (tmp % j == 0) {
				// 현재의 몫이 j로 나눠떨어지면, j는 소인수, 갯수증가하자.
				tmp = tmp / j;
				ch[j]++;
			}
			else {
				// 더이상 j로 나눠지지 않으면 j를 증가시켜 다음 소수로 넘어간다. 
				j++;
			}
			if (tmp == 1) break;
		}
	}

	cout << N << "! =";
	for (int i = 0; i < N; i++) {
		if (ch[i] != 0) cout << " " << ch[i];
	}
	return 0;
}

