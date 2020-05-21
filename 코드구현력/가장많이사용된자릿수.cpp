#include <iostream>

using namespace std;

int ch[10]; //전역변수, 0으로 초기화됨, idx에 사용된 횟수 저장용

int main()
{
	int N, digit, max = -2147000000, res; //digit = 읽어들인 자연수, res = 답(횟수)
	char a[101]; // string형태로 읽어들이기 위함. 
	cin >> a;

	for (int i = 0; a[i] != '\0'; i++) { //종료조건, string의 마지막은 0
		digit = a[i] - 48; // char에 아스키로 저장되어 있으므로 빼준다.
		ch[digit]++; //ch에 digit에 해당하는 위치에 횟수 증가
	}

	for (int i = 0; i < 10; i++) {
		if (ch[i] >= max) { // 저장해둔 것을 0부터 돌면서 max값보다 큰 횟수나오면 max를 갱신해준다.
			max = ch[i];
			res = i;
		}
	}
	cout << res << endl;
	return 0;
}