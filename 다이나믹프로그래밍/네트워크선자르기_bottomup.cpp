//bottom up; 작은문제의 해를 구해서 확장시켜 최종해를 구하기
//길이 7짜리를 바로 구한다고 생각하는게 아니라, 길이 1짜리를 1개로 자르기 --> 1
//                                           길이 2짜리를 1개 --> 1 [1+1], 2개 --> 1[2]
//                                           길이 3짜리: 끝에가 1개 남으면 앞에 두개짜리를 나누는 방식--> D[2]+1, 끝에 2개 남으면 앞이 1짜리인 경우로 생각 --> D[1] + 1
// 1또는 2로만 자를 수 있으므로, 끝에는 1개 또는 2개만 남게된다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;
int d[50];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	d[1] = 1; d[2] = 2;
	for (int i = 3; i < n + 1; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n];
	return 0;
}
	

	
