
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int A, B, tmp, p1 = 0, p2 = 0, p3 = 0;
	
	cin >> A;
	vector<int> a(A);
	for (int i = 0; i < A; i++) {
		cin >> a[i];
	}

	cin >> B;
	vector<int> b(B);
	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}
	vector<int> c(A + B);

	sort(a.begin(), a.end()); //퀵 정렬. 삽입 정렬 쓰기엔 느림
	sort(b.begin(), b.end()); 
	

	while (p1 < A && p2 < B) {
		if (a[p1] < b[p2]) {
			p1++;
		}
		else if(a[p1] == b[p2]) {
			c[p3++] = a[p1++];
			p2++;
		}
		else {
			p2++;
		}
	}

	for (int i = 0; i < p3; i++) {
		cout << c[i] << " ";
	}
	return 0;
}
