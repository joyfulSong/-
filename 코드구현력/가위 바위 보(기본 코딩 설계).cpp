#include <iostream>

using namespace std;

int a[101], b[101];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < N; i++) { 
		//a를 기준으로 a가 이기는 경우만 따지고 / 비기는 경우 / 나머지 (b가 이기는 경우)
		if ((a[i] == 1 && b[i] == 3) ||
			(a[i] == 2 && b[i] == 1) || (a[i] == 3 && b[i] == 2)) {
			cout << "A" << '\n';
		}
		else if (a[i] == b[i]) {
			cout << "D" << '\n';
		}
		else
			cout << "B" << '\n';
	}

	return 0;

}