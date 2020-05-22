#include <iostream>

using namespace std;

int main()
{
	int N, num, ans_stu, res;
	cin >> N;

	for (int i = 0; i < N; i++) {
		res = 0;
		cin >> num; //구할 대상 수
		for (int i = 1; i <= num; i++) { //1부터 자기자신까지의 합 구하기
			res += i;
			cout << res << endl;
		}
		cin >> ans_stu; //학생의 답 받기

		if (ans_stu == res) { //학생 답과 비교 
			cout << "YES" << "\n";
		}
		else cout << "NO" << "\n";
	}
	return 0;
}