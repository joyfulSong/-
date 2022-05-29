// "최대 연속" 경보음 발생 초를 출력해야함. max를 통해서 하자.
#include <iostream>
using namespace std;

int main()
{
	int N, M, tmp, cnt = 0, max = -2147000000;
	cin >> N >> M; // N초, 기준값 받기

	for (int i = 0; i < N; i++) {
		cin >> tmp; // 현재 초에서의 측정값 
		if (tmp > M) // 측정값이 기준값보다 크면
		{
			cnt++;
			if (cnt > max) max = cnt;  
			//기존의 max보다 cnt가 크면 (즉 0으로 초기화 되지 않고 cnt가 연속이었다면)
			// 그 cnt를 담아준다.
		}
		else cnt = 0; //측정값이 기준값 이하이면 cnt 초기화해버림
	}
	if (max == 0) cout << "-1" << "\n"; // max는 else의 cnt를 통해 0으로 한번이라도 초기화 되므로, 한번도 기준값 초과가 되지 않아도 0인 상태.
	else cout << cnt << "\n";

	return 0;
}
