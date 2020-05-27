// 포인트를 사용해, 두 배열을 쪼개서 넣는다. 병합정렬 연습
#include <iostream>
#include <vector> 

#include <algorithm>
using namespace std;

int main()
{
	int A, B, p1 = 0, p2 = 0, p3 = 0; 
	int a[101];
	int b[101];
	int c[300];

	cin >> A;
	for (int i = 0; i < A; i++) {
		cin >> a[i];
	}

	cin >> B;
	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}

	while (p1 < A && p2 < B) {//한쪽이 먼저 다 넣어지면, 남은 쪽거는 큰 수들이므로 그대로 대입하면 된다.
		if (a[p1] < b[p2]) {
			c[p3++] = a[p1++]; // 선 대입 후 증가.
		}
		else
			c[p3++] = b[p2++];
	}

	// 남은쪽의 배열을 그대로 집어넣는다.
	while (p1 < A) c[p3++] = a[p1++];
	while (p2 < B) c[p3++] = b[p2++];
	
	for (int i = 0; i < p3; i++) {
		cout << c[i] << " ";
	}

	return 0;
}

