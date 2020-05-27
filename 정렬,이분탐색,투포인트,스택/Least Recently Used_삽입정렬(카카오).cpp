
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int S, N, num, tmp;

	cin >> S >> N;
	
	vector<int> ch(S);
	
	for (int i = 0; i < N; i++) {
		tmp = -1;// 0으로 초기화 하면, 배열 맨앞도 0이므로 겹침. -1로하자.
		cin >> num;
		for (int j= 0; j < S; j++) { 
			// 캐쉬에 있는지 확인
			if (num == ch[j]) {
				tmp = j;
			}
		}
		//있으면 찾은 위치 한칸 앞에거부터 찾은위치로 밀어 넣으면서 맨앞칸 만든다.
		if (tmp != -1) {
			for (int j = tmp - 1; j >= 0; j--) {
				ch[j + 1] = ch[j];
			}
		}
		// 없으면 전부 한칸 씩 뒤로. 
		else {
			for (int j = S - 2; j >= 0; j--) {
				ch[j + 1] = ch[j];
			}
		}
		ch[0] = num;
	}
	
	for (int i = 0; i < S; i++)
	{
		cout << ch[i] << " ";
	}

	return 0;
}