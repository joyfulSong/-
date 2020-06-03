// stl 벡터 생성방법
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> a; // ( )로 사이즈 설정을 안해주면 빈벡터로 생성된다. 빈벡터이면 a[1] = 5가 불가능하다.
	a.push_back(5); // 빈벡터이더라도 이거는 가능하다.
	a.size(); // 사이즈 출력. 
	// (n)으로 n을 받아서 사이즈 설정을 동적으로 가능하다. 이 경우, 사이즈가 미리 할당되었기에 a[1] = 5가 가능하다. 

	vector<int> c[3]; // c라는 벡터가 빈벡터 객체로 3개가 생긴다.
	// c[0] c[1] c[3]
	c[0].push_back(1); // 각각의 객체에 이렇게 넣을 수 있다.
	// c[0] | 1 | 2 | 3 | 이라면 c[0][0] == 1이다.

	//pair는 가중치 인접리스트에서 사용한다.
	vector<pair<int, int>> g[3];
	g[1].push_back({ 3, 5 }); //이렇게 중괄호 사용해 initialization 가능하다.
	// g[1] | (3, 5) | (4, 7) | 이라면 g[1][0].first == 3이다.
	// pair로 들어가는 첫번째가 first, 두번째가 second이다. 
	return 0;
}

