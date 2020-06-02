//                   d(1,8)                   8개비교 *1  = 8
//          d(1,4)             d(5,8)         4개비교 *2  = 8
//    d(1,2)    d(3,4)   d(5,6)    d(7,8)     2개비교 *4  = 8
//d(1,1)  d(2,2)                              
// 레벨은 logn만큼 존재 (log2(8) = 3) 하므로 n개가 총 logn만큼 필요 --> 시간복잡도는 n*logn만큼이다. 

#include <iostream>
#include <vector>
#include <stack> 
#include <algorithm>
using namespace std;

int D[10], tmp[10]; //수열 저장용, 임시저장용

void divide(int lt, int rt) {
	int mid;
	if (lt < rt) {
		//lt와 rt가 서로 역전되면 안됨
		mid = (lt + rt) / 2; 
		//이분 검색처럼 mid를 만들어 총 포인터 세개로 진행
		//소수점은 버림. 예) 1+2/2  이면 mid는 1이 됨.

		//분할
		divide(lt, mid); 
		divide(mid + 1, rt);
		
		// 후위 순회. 왼쪽 오른쪽 자식에 대한 함수 호출끝나면 부모 노드의 역할 수행. 
		//정복
		int p1 = lt; //범위 시작 (lt~mid) 
		int p2 = mid + 1; // 범위끝 (mid+1~rt)
		int p3 = lt; //tm 저장 인덱스 기억용
		while (p1 <= mid && p2 <= rt) {
			// p1이 mid를 오버하면 왼쪽 배열 다 돈것, p2가 rt를 오버하면 오른쪽 범위 다 돈것, 하나라도 다 돌면 종료
			// 남은 쪽을 넣는다: 남았다 = p1 혹은 p2가 아직 mid 혹은 rt까지 도달 못했다.
			if (D[p1] < D[p2]) tmp[p3++] = D[p1++];
			else tmp[p3++] = D[p2++];
			//p1, p2 인덱스의 값을 비교해 작은것을 tmp에 "넣고 포인터 증가"
		}
		//d(1,2)에서 d[1]을 넣고, 남은 p2~rt(: d(1,2)에서 2이다.)가 들어간다. d[2]
		while (p1 <= mid)tmp[p3++] = D[p1++];
		while (p2 <= rt)tmp[p3++] = D[p2++];

		// tmp에 넣었는데, D배열을 다시 정렬해줘야하므로 tmp에 있는 순서 그대로 D에 복사해 넣는다.
		for (int i = lt; i <= rt; i++) {
			// D(1,2)면 1부터 2 인덱스까지.
			D[i] = tmp[i];
		}

	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n+1; i++) {
		cin >> D[i];
	}
	divide(1, n); //맨 왼쪽인 lt, 맨 오른쪽인 rt 넘겨준다. 

	for (int i = 1; i <= n; i++) {
		cout << D[i] << " ";
	}
	return 0;
}

