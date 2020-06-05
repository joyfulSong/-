#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int DFS(int n) {
	if (n == 1) return 1;
	else {
		return n * DFS(n - 1);
	}
}
// 5가 들어가면 5는 5*DFS(4) return
// 4가 들어가면 4는 4*DFS(3) return
// ...
// 2가 들어가면 2는 2*DFS(1) return
// 1이 들어가면 1은 1 return

// 1을 DFS(1)이 받아 2가 되고, 그를 DFS(3)이 받아 6이되고, 6을 DFS(4)가 받아 24가 되고, 그를 DFS(5)가 받아 120.

// 마지막까지 함수호출을 쭉 하고, 마지막에 도달하면 함수의 결과물을 거꾸로 받아서 처음의 N으로 넘어간다.
int main()
{
	int n;
	cin >> n;

	cout << DFS(n);
}