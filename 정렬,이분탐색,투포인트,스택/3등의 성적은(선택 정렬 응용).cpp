
#include <iostream>

using namespace std;

int main()
{
	int N, pos = 0, tmp, idx, cnt;
	
	int gr[100];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> gr[i];
	}
	
	for (int i = 0; i < N - 1; i++) { // n-1까지인건 j에서 두개씩 비교해서.
		idx = i;
		for (int j = i + 1; j < N; j++) {
			if (gr[idx] < gr[j]) idx = j;
		}
		tmp = gr[i];
		gr[i] = gr[idx];
		gr[idx] = tmp;
	}

	pos = gr[0];
	cnt = 1;
	for (int i = 1; i < N; i++) {
		if (gr[i] < pos) {
			pos = gr[i];
			cnt++;
		}
		if (cnt == 3) {
			cout << gr[i];
			break;
		}
	}
	return 0;
}