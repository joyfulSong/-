// 나는 -1+1 = 0임을 이용했는데, 여는 괄호를 스택에 넣고, 닿는 괄호를 만나면 pop해준다.
#include <iostream>
#include <vector>
#include <stack> //stl 스택
#include <algorithm>
using namespace std;

int main()
{
	char a[30]; // string으로 하면 넣을때 "("로 해야하고, char이면 '('이다. 
	// stack의 자료형이랑 동일해야하낟.
	stack<char> s;
	int flag = 1; 
	// 여는괄호들의 짝 닫는 괄호를 모두 만나 pop이 되어 stack이 비어있는 상황에서
	// 그 다음 괄호가 또 닫는 괄호라 더이상 꺼낼 여는 괄호가없다면
	// 비정상 종료로 flag를 0처리.

	for(int i = 0; i != '\0'; i++)
		cin >> a[i];

	//a에 넣어둔 괄호를 탐색한다.
	for (int i = 0; i != '\0'; i++) {
		if (a[i] == '(')
			s.push(a[i]);
		else {
			// a에서 닫는 괄호를 만났는데 stack이 비어있다면 여는괄호와의 짝이없으므로.
			if (s.empty()) {
				cout << "NO";
				flag = 0;
				break;
			}
			else s.pop();
		}
	}

	// 모두 다 push, pop이 정상처리되어있을때
	if (s.empty() && flag == 1) cout << "YES";
	
	//위에서 no로 나오고, 바로 위 if문에서 flag가 1이 아니기에 else로 내려와 no가 또 출력될 수 있음.
	//이를 방지.
	// 여는 괄호가 더 많이 남아있는 경우. 위에서 비정상 종료가 안일어났을때만. 
	// stack이 비어있지 않고 정상종료 되었을때. 
	else if(!s.empty() && flag == 1) cout << "NO";
		return 0;
}

