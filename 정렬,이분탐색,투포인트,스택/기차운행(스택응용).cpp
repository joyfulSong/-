
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
	int n, tmp, j = 0; //j는 도착순서 기억용

	cin >> n;

	stack<int> s; //출발순서
	vector<char> str; // PO저장용


	for (int i = 0; i < n; i++) {
		cin >> tmp; //출발 순서 하나씩 받음.
		s.push(tmp);
		str.push_back('P'); // 한개씩 넣음
		while (1) {
			if (s.empty()) break; // 비교해서 다 pop해서 비면 break하고 다시 받아줌
			if (j == s.top()) {
				s.pop();
				j++;
				str.push_back('O');
			}
			else break; // j번째 순서와 s의 top이 같지 않고 stack이 차있으면 break하고 새로 받아 j와 비교.
		}
	}

	//1은 맞아서 뺴냈고, 증가된 j와 s.top을 비교하는데 서로 다르면 순서대로 갈 수 없는 것.
	if (!s.empty()) cout << "impossible";
	else {
		for (int i = 0; i < s.size(); i++) {
			cout << str[i];
		}
	}
		return 0;
} 

