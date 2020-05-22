#include <iostream>

using namespace std;

int main()
{
	int N, num, ans_stu, res;
	cin >> N;

	for (int i = 0; i < N; i++) {
		res = 0;
		cin >> num;
		for (int i = 1; i <= num; i++) {
			res += i;
			cout << res << endl;
		}
		cin >> ans_stu;

		if (ans_stu == res) {
			cout << "YES" << "\n";
		}
		else cout << "NO" << "\n";
	}
	return 0;
}