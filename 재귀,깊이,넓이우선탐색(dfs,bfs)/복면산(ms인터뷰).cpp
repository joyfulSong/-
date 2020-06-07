// 이 복면산을 어떻게 푸는지는 모르겠다만, 수열 걍 보고 해 
// 0 1 2 3 4 5 6 7
// D E M N O R S Y
// SEND와 MORE를 더했을 때 MONEY가 출력되도록 해야함.
//각 알파벳을 대응되는 숫자로 바꿔주고,
//알파벳과 대응되는 숫자에 대한 수열을 만들 때 DFS를 이용해 채워준다. 

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;
int a[8], ch[8];

int send() {
	return 1000 * a[6] + 100 * a[1] + 10 * a[3] + 1 * a[0];
}
int more() {
	return 1000 * a[2] + 100 * a[4] + 10 * a[5] + 1 * a[1];
}
int money() {
	return 10000 * a[2] + 1000 * a[4] + 100 * a[3] + 10 * a[1] + 1*a[7];
}
void DFS(int L) {
	if (L == 8) {
		if (send() + more() == money()) {
			if (a[2] == 0 || a[6] == 0) return; //숫자의 맨 앞자리가 0이면 안됨.
			else {
				cout << "  " << a[6] << " " << a[1] << " " << a[3] << " " << a[0] << endl;
				cout << "+ " << a[2] << " " << a[4] << " " << a[5] << " " << a[1] << endl;
				cout << "---------" << endl;
				cout << a[2] << " " << a[4] << " " << a[3] << " " << a[1] << " " << a[7];
			}
		}
	}
	else {
		ch[L] = 1;
		DFS(L + 1);
		ch[L] = 0; //출력 후 다 0으로 풀어준다.
	}
}
int main()
{
	DFS(0);
	return 0;
}