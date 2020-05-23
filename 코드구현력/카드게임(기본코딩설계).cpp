#include <iostream>

using namespace std;

int main()
{
	int Anum = 0, Bnum = 0;
	char flag = 'D';

	int A[10], B[10];
	
	for (int i = 0; i < 10; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < 10; i++) {
		//cin >> A[i] >> B[i]; 한줄씩 들어오기 때문에 먼저 입력을 받아야한다.
		if (A[i] > B[i]) {
			flag = 'A';
			Anum += 3;
		}
		else if (A[i] < B[i]) {
			flag = 'B';
			Bnum += 3;
		}
		else {
			Anum++, Bnum++;
		}
	}

	cout << Anum << " " << Bnum << "\n";

	if (Anum > Bnum) {
		cout << "A";
	}
	else if (Anum == Bnum && flag == 'D') {
		cout << "D";
	}
	else if (Anum == Bnum && flag != 'D') {
		cout << flag;
	}
	else {
		cout << "B";
	}

	return 0;
}