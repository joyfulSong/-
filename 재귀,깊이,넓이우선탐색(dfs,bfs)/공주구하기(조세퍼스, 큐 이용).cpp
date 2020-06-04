#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, x;
	queue<int> q;

	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		if (q.size() == 2) { // 사실, 두개가 남았을때 따로 이렇게 처리 안해줘도, 두개끼리 m-1번까지 넣고 빼고를 반복하며 채우고, m번째만 남게 된다.
			q.pop();
		}
		else {
			for (int i = 1; i < m; i++) {
				x = q.front(); // q.push(q.front())
				q.pop();
				q.push(x);
			}
			// 맨앞이 원래배열에서 m인곳
			q.pop();
		}
	}
	cout << q.front();
}