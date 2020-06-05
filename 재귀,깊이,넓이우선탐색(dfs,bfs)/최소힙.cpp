// 최쇱은 부모노드의 값이 자식노드의 값보다 작게되어 루트에 최솟값이 저장된다.
// 최대힙을 최소힙구조로 바꾸려면, 큰수가 부모노드쪽으로 위치하게 되니 -를 붙이면 가장 작은 값이 위에 위치한다.
// 꺼낼때 -1을 붙인다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int a;
	priority_queue<int> pQ;

	while (true) {
		cin >> a;
		
		if (a == -1) break;
		if (a == 0) {
			if (pQ.empty() == 1) cout << "-1";
			else {
				cout << -pQ.top();
				pQ.pop();
			}
		}
		else {
			pQ.push(-a);
		}
	}
}