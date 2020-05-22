#include <iostream>

using namespace std;

int main()
{
	int N, cnt = 0, res = 0;
	cin >> N;

	int a[101];

	for (int i = 0; i < N; i++) {
		cin >> a[i]; //앉은 키 정보 저장용
	}

	for (int i = 0; i < N; i++) {
		bool flag = true; // 한명이라도 자신의 키보다 큰 사람만나면 false 되지만, 새로운 학생에 대해서는 다시 플래그 초기화
		for (int j = i + 1; j < N; j++) {
			if (a[i] <= a[j]) { //a[i]가 커야하므로 같아도 안됨. 
				flag = false;
				break;
			}
		}
		if (i != (N-1) && flag == true) res++; //마지막 수는 뒷사람이 없으므로 제외해야.
	}
	cout << res << endl;
	return 0;
}


// 선생님: 뒤에서부터 탐색하면서 진행, 앞선 수들은 뒤보다 무조건 커야 분노유발자가 된다는 것을 포인트로 잡음
// 갱신된 max보다 작은값이 앞선 배열요소에 있으면 그 요소는 분노유발자가 될 수 없다.
//int main()
//{
//	int N, cnt = 0, max;
//	cin >> N;
//
//	int a[101];
//
//	for (int i = 0; i < N; i++) {
//		cin >> a[i];
//	}
//
//	max = a[N-1]; //맨뒷수를 max로 두고 시작
//	for (int i = N - 2; i >= 0; i--) {
//		if (a[i] > max) {
//			max = a[i];
//			cnt++;
//		}
//	}
//		
//	cout << cnt << endl;
//	return 0;
//}