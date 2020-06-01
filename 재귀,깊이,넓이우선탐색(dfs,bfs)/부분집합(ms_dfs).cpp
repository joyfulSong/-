// 트리에는 레벨이 있다. 
// 3이면 부분집합의 갯수가 2의 3승, 8개이다. 
//       1
//    2      2
//  3   3   3   3
// E E E E E E E E

// 왼쪽 노드로 이동시에는 N을 부분집합에 포함한다.
// 오른쪽 노드로 이동시에는 포함하지 않는다.
// 포함 불포함은 CH배열에 1을 넣거나 0을 넣는다. 
// 종료 시점에 도달하면 CH배열을 출력한다.
#include <iostream>
#include <vector>
// ms 인터뷰
#include <stack>
#include <algorithm>
using namespace std;

int n, ch[11];
void L(int a) {
	
	if (a > n) {
		for (int i = 0; i < n; i++) {
			cout << ch[i] << " ";
		}
		cout << "\n";
	}
	else {
		ch[a] = 1; //현재값 체크하고
		L(a + 1); // 왼쪽노드 생성
		ch[a] = 0;
		L(a + 1); //오른쪽 노드 생성
	}
}
int main()
{
	cin >> n;

	L(1);
	return 0;
} 

