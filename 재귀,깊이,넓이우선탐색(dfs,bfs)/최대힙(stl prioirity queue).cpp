// stl priority queue가 max heap 자료구조를 사용한다.
// 부모가 왼,오른쪽 자식보다 크게 들어가 루트에 최댓값이 들어있게 된다.
// 값을 입력받을 때 레벨순으로 채워나가며, 부모와 비교해 작으면 그대로 넣고, 크면 부모자리와 스위칭한다. (루트노드까지 이 검사를 진행.)
// prioirity queue에서 참조한다, pop한다는것은 루트값을 꺼낸다는것
// 루트가 빠지면 맨 아래 오른쪽 자식 노드가 올라가고(upheap), 스위칭(downheap) 다시 max heap자료구조로 정렬된다.
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

		if (a == -1)break;
		if (a == 0) {
			if (pQ.empty == 0) cout << "-1";
			else {
				cout << pQ.top();
				pQ.pop();
			}
		}
		else {
			pQ.push(a);
		}
	}
	return 0;
}