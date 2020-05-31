// k진수로 나타낸다는 것은 숫자를 k로 나눈 나머지를 저장하는 것이다.
// 10진수도 11이 10+1인것처럼, 11을 10으로 나눌 수있고 나머지 1이남고, 몫인 1을 다시 10으로 나눈 나머지 1이 저장되는 것이다. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int stack[100], top = -1; // 최대 수 1000이 들어와도 2진수로 잘게 표현해도 100개는 안나옴. 여유있게 잡음. 
// top은 스택에서의 위치 가리키는 용도. -1로 초기화

void push(int x) {
	stack[++top] = x; // top 선증가, 후 x대입
}

int pop() {
	return stack[top--]; // 먼저 top위치의 값 리턴 후 top한칸 아래로.
}
int main()
{
	int n, k;
	
	cin >> n >> k;
	char str[20] = "0123456789ABCDEF"; // 16진수출력용. 5, 8진수는 각각 5와 8에서 자리수가 바뀌니 숫자로만 출력되지만, 
	//16진수는 10의자리가 발생하는 10부터는 문자로 처리해줘야하기에. 
	while (n > 0) {
		push(n % k);
		n = n / k;
	}

	while (top != -1) {
		// 감소시켜가며 top이 -1되면 출력중단
		cout << str[pop()]; //c언어와 다르게 바로 char형으로 출력됨.
		// str내에서 출력하는 것은 16의 경우 1, 15가 출력되는데 16진수로 15는F이기 때문이다. 
	}

	return 0;
}

// stack<int> s;
// s.push(n%k);
// s. empty(); 스택이 비어있으면 1 리턴, 비어있지 않으면 0리턴
// !s.empty()로 해서, 다 빼내서 비게되면 1되어서 !으로 0되니 while종료
// 스택의 맨 윗자료 참조: s.top(); 이걸로 str[s.top()]
// s.pop();