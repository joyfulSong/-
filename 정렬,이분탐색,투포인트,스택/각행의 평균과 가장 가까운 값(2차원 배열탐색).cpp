// 이차원 배열 탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전역으로 안잡으면 0으로 초기화가 안되어서 아래서 += 할때 쓰레기값에 더해짐.
int a[9][9];
int avg[9][2]; //1열: 각 행의 평균값, 2열:평균과 가까운 값 저장용
//선생님: 저장 안하고 매행 계산 끝날때마다 출력함. 

int main()
{
	int diff = 2147000000, sim = 0; // diff는 최대로 잡아두고 갱신, sim에는 평균과 가까운수 저장

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
			avg[i][0] += a[i][j];
		}
		// 실수 나누기 정수 = 실수. (더 넓은 자료형으로 결과 반환.) 
		// 정수 나누기 정수될수도 있으니 실수받기 위해 실수로 나눠주자.
		avg[i][0] = (avg[i][0] / 9.0) + 0.5; // 한행의 값을 다 더한 뒤에 9로 나눈값에 0.5 더해 소수 첫째자리에서 반올림
		// int형에 넣으니 캐스팅 필요 없음.
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (abs(avg[i][0] - a[i][j]) < diff){
				diff = abs(avg[i][0] - a[i][j]);
				sim = a[i][j];
			}
			else if (abs(avg[i][0] - a[i][j]) == diff && a[i][j] > sim) {
				sim = a[i][j];
			}
		}
		avg[i][1] = sim; //최종적으로 남은 가장 비슷한 값
	}

	for (int i = 0; i < 9; i++) {
		cout << avg[i][0] << " " << avg[i][1] << '\n';
	}
	return 0;
}

 