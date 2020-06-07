// 딱 마지막날까지만 해야지, 마지막날보다 크다가 조건이면 무한히 가지가 뻗어나갈 수도 있음.
// 구조체형 사용하려고 하니, +연산자가 필요함. 전역 벡터를 날짜와 비용 따로 잡자.

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int n, cost = -2147000000; // 날짜 체크용
vector<int> T, P;

// 구조체형 사용하려고 하니, +연산자가 필요함. 전역 벡터를 날짜와 비용 따로 잡자.
//struct counsler {
//	int date;
//	int cost;
//	counsler(int a, int b) {
//		date = a;
//		cost = b;
//	}
//};



void DFS(int L, int sum) {
	if (L+1 == n+1) { // 딱 마지막날까지만 해야지, 마지막날보다 크다가 조건이면 무한히 가지가 뻗어나갈 수도 있음.
		if (sum > cost) cost = sum;
	}
	else {
		//날짜를 더해봤을 때, 마지막날 다음날이 최대이면, 넘어간다. (종료시점에서 또 넘겨주므로. 예: 1일에서 4일짜리 일 끝내면 5일을 스타트지점으로 삼음)
		//크게 크게 넘어가면 위의 종료 시점을 넘겨버릴수 있으니 반드시 이 조건을 걸어준다.
		if (L + T[L] <= n + 1) DFS(L + T[L], sum + P[L]); //여기서 현재 레벨의 값을 더해서 넘김.
		DFS(L + 1, sum); //더해본 날짜가 범위를 벗어나면 단순히 한칸만 증가해서 다시 트라이.
		}
}

int main()
{
	int t, p;
	
	cin >> n;
	
	T.push_back(0); // 0번 인덱스 사용안하려고.
	P.push_back(0);
	for (int i = 1; i < n+1; i++) {
		cin >> t >> p;
		T.push_back(t);
		P.push_back(p);
	}

	DFS(1, 0);
	
	cout << cost;

	return 0;
}