// 시간복잡도 N으로 진행, 진행된 값 now가 한개 이전값인 pre보다 크면 cnt++, pre = now 갱신, 앞으로 이동. 
// 최대증가수열 개수 저장하기 위해서 max 지정, cnt값이 더 커질 경우에 갱신. 
// 배열 필요 없음, 그때그때 받아서 비교하면 됨.
#include <iostream>

using namespace std;

int main()
{
	int N, pre, now, max = 1, cnt = 1;
	cin >> N;
	cin >> pre; 

	for (int i = 1; i < N; i++) {
		cin >> now;
		if (now >= pre) {
			cnt++;
			if (cnt > max) {
				max = cnt;
			}
		}
		else cnt = 1; //다시 카운트업 하도록.
		pre = now;
	}

	cout << max;
	return 0;
}

// 나는 배열을 썼음. 단순 비교로 항상 갱신해주면 답을 따로 저장할 배열이 필요 없음.
//#include <vector>
//int main()
//{
//	int N, cnt = 1, max = 1;
//
//	cin >> N;
//
//	vector<int> a(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> a[i];
//	}
//
//	for (int i = 1; i < N; i++) {
//		if (a[i] >= a[i - 1]) {
//			cnt++;
//			if(cnt > max){
//				max = cnt;
//				}
//		}
//		else {
//			cnt = 1;
//		}
//	}
//
//	cout << max << endl;
//
//	return 0;
//}
