// 내가 틀린 이유: 변수 하나씩 받을 때, 두자리가 들어오면 char의 경우 한개만 받게 된다. 
// string으로 받아서 숫자로 변환하자.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int c = 0, h = 0, pos; //pos는 배열에서 이동용
	char ch[101];

	cin >> ch; // string으로 입력받는다.

	// C 0 0 0 H 0 0 0
	if (ch[1] == 'H') {
		// C의 갯수는 1이라는 말
		c = 1;
		pos = 1;
		if (ch[pos + 1] == '\0') h = 1; // H 다음을 읽었더니 0이라면 H는 1이다.
		else {
			for (int i = pos + 1; ch[i] != '\0'; i++) {
				h = h * 10 + (ch[i] - 48);
			}
		}
	}
	else {
		// 숫자가 있으면 H를 만날때까지 읽어들여 숫자화한다. 
		for (int i = 1; ch[i] != 'H'; i++) {
		c = c * 10 + (ch[i] - 48); // 하나 읽어들여서 c에 저장하고 그걸 10을 곱해서 자리 올려주고 다시 일의자리값 더해주고...
		pos = i; // H전까지 이동한 i (이 for문 밖 전역변수이면 i가 증가하고 != 만나서 종료되니깐 H의 위치일텐데, for문 안에서 끝나는 상황임
		}
		if (ch[pos + 2] == '\0') h = 1; // H 다음을 읽었더니 0이라면 H는 1이다.
		else {
			for (int i = pos + 2; ch[i] != '\0'; i++) {
				h = h * 10 + (ch[i] - 48);
			}
		}
	}
	
	
	cout << c * 12 + h * 1;
	return 0;
}

