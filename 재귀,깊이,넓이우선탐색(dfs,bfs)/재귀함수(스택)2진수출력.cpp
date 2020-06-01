//함수는 호출이 되면 스택에 자신의 호출정보를 기록한다: 스택프레임
// Bit(5) -- 매개변수 5, 복귀해야할 주소 -- Bit의 20번라인
// Bit(11) -- 매개변수 11, 복귀해야할 주소 -- main의 28번라인
// main() -- 지역, 매개변수, 복귀해야할 주소(끝난 라인으로 돌아감). 

// 스택프레임에 더이상 저장할 수 없으면 stack overflow.

// Bit(0) --> return 
// Bit(1) --> 1 %  2 -- 1
// Bit(2) --> 2 %  2 -- 0
// Bit(5) --> 5 %  2 -- 1
// Bit(11) --> 11 %2 -- 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Bit(int n) { //자신이 return하는 값이 없으므로 void임. 
	if (n == 0) return; //void면 return; 함수 종료. int면 return 0;
	else {
		Bit(n / 2);
		cout << n % 2;//갖고있다가 출력한다. 
	}
}
int main()
{
	int n;
	cin >> n;
	Bit(n);

	return 0;
}

