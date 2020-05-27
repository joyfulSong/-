//inversion 배열의 큰 수 부터 돌린다. 제일 큰 수 앞에는 더 큰 수가 없으므로, 그대로 os에 넣는다. 
// N부터 돌때, is에 저장된 수만큼을 자신 앞으로 밀어서 넣고, 자기 위치에 해당 번째 수(7번째면 7)을 넣는다.
// 자신 앞으로 들어올 수는 자신보다 작은 수 이므로, 뒤의 수만 생각한다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, i, pos;
	
	cin >> N;
	vector<int> is(N);
	vector<int> os(N);
	for (int i = 0; i < N; i++) {
		cin >> is[i];
	}

	os[N - 1] = is[N - 1]; // 맨 뒤, 가장 큰 수 넣어주기
	for (i = N - 2; i >= 0; i--) {
		pos = i;
			for (int j = 1; j <= is[i]; j++) { //저장된 수만큼 앞으로 끌고오기
				os[pos] = os[pos + 1];
				pos++;
			}
		}
	os[pos] = i;
	}

	for (int k = 0; k < N; k++) {
		cout << os[k] << " ";
	}
    return 0; 
}

