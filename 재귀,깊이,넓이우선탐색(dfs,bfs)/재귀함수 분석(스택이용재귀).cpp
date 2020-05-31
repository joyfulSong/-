//재귀함수는 함수 내에서 자신을 다시 호출하는 것이다.
// 재귀함수는 스택 자료구조를 사용해 함수를 호출한다.

//함수 호출은 stack의 바닥부터 저장된다. 따라서 스택 맨 상단은 현재 실행중인 함수를 나타낸다.
// 각 스택에는 현재 함수 내에 몇번째 라인까지 실행했는지가 저장된다. 그래서 호출이 종료되면 그 끝난 지점에서부터 다시 진행할 수 있도록한다.

// recurr(1) --23line
// recurr(2) - 23line
// recurr(3) - 23line
//--bottom--

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recurr(int x) {
	if (x == 0) return; //return하면 stack에서 빠져나가며, 가장 최근에 저장해두었던 x부터 꺼낸다.
	else {
		//무한루프에 빠지지 않게 종료 조건을 설정해줘야 한다.
		// x>0으로 조건을 두고 0되서 종료되게 해도 되지만
		//초보자면 '종료 시점'을 두고 return을 하게 설정해두자.
		recurr(x - 1);
		cout << x;
	}
}
int main()
{
	int	n;
	cin >> n;
	recurr(n);
	return 0;
}
