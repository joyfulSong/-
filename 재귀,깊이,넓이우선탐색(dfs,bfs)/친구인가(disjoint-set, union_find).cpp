// A, B에 공통원소가 존재하면 한 집합으로 여기며, 
// 어떤 두 원소가 서로 같은집합내에 존재하는지, 혹은 교집합(공통원소)가 없는 서로소 집합에 속하는지를 확인할 때
// disjoint set방법으로 푼다. 

// set을 만들 때 트리형태로 표현하게 되는데, unf배열을 사용해 각 원소가 속하는 집합이 어디인지를 저장한다.
// 예) unf |1||2||... 이면 1노드는 집합1에 속하고, 2노드는 집합 2에 속한다. 

// find 함수는 어떤 노드가 속한 집합 번호를 리턴한다. 
// union 함수는 친구노드인 두 노드 각각이 속한 집합이 다르면 unf[a] = b로 b집합이라고 갱신하며 루트노드를 집합번호로 저장한다.

// find 함수에서 자신의 v==unf[v], 인덱스와 배열값이 같아야 최종 return인데, 다른 경우에 재귀호출로 연결된 노드를 타고 올라가 루트번호를 리턴한다. 
// union 함수에서 unf[a] = b로 노드간을 연결했으니, find(unf[v])로 저장된 배열값(연결된 노드)로 올라가 v==unf[v]일때, 즉 루트값을 리턴한다.
// 이 리턴값으로 집합 간을 구분한다.

//1열로 트리를 연결해 find(a)호출시 계속 타고 넘어가기엔 시간이 많이 소모되므로, "경로압축"을 한다: unf[v] = find(unf[v])로.
//예: f(1) -- unf[1] = f(2) -- unf[2] = f(3) -- unf[3] = f(4) -- 4 로 4를 리턴받으며 모두 4로 저장된다. 
//   4
// / | \
// 1 2  3 으로 경로가 압축되는 것이며, 재귀 호출이 줄어든다. 

#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int unf[1001];

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]); // v 인덱스에 저장된 배열값 노드로 타고 넘어간다. 
	// 집합을 구성하며 연결된 루트노드에 대해 경로가 압축된다.
}

int Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b; // 루트 노드가 갱신됨. (예: a는 3으로 리턴받고, b는 단일집합이라 8이면, a가 속해있던 집합의 루트노드가 8이 됨.)
}

int main()
{
	int n, m, a, b;
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		unf[i] = i; //최초로 각 노드별로 집합번호를 초기화함 (자기자신으로)
	}

	for (int i = 1; i < m; i++) {
		cin >> a >> b;
		Union(a, b); //노드간을 연결. Union 함수내에서 Find를 사용해 이 노드번호에 대한 루트노드를 반환하고 친구관계인 두 노드를 연결
	}

	//m 번째일때.
	cin >> a >> b;
	a = Find(a);
	b = Find(b);
	if (a == b) cout << "YES";
	else cout << "NO";

	return 0;
}