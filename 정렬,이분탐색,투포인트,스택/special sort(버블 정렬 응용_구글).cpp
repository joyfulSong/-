// 버블정렬로 풀어도 됨. 음수면 swap한다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, tmp;
	int ch[101];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (ch[j] > 0 && ch[j + 1] < 0) { //앞에가 양수일때만 바꾸어야지, 그렇지 않으면 음수간의 숫자가 바뀐다. 
				tmp = ch[j];
				ch[j] = ch[j + 1];
				ch[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ch[i] << " ";
	}
	return 0;
}


//int main()
//{
//	int N, cnt1 = 0, cnt2 = 0;
//
//	cin >> N;
//	int num[101];
//	int a[101];
//	int b[101];
//
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//
//	for (int i = 0; i < N; i++) {
//		if (num[i] < 0) {
//			a[cnt1] = num[i];
//			cnt1++;
//		}
//		else {
//			b[cnt2] = num[i];
//			cnt2++;
//		}
//	}
//
//	// 넣고나서 cnt++이므로 전체 배열에 저장된 갯수보다 +1된 상태. < 이기때문에 cnt-1까지 출력됨.
//	for (int i = 0; i < cnt1; i++) {
//		cout << a[i] << " ";
//	}
//	for (int i = 0; i < cnt2; i++) {
//		cout << b[i] << " ";
//	}
//	return 0;
//}
