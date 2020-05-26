
#include <iostream>
#include <vector> 
// 버블 정렬: 인접한 두수끼리만 비교. 
// i포문이 돌때 맨 뒤에 제일 큰수부터 쌓임. 
// j포문이 돌면서 i가 돌아서 생긴 맨뒷수를 뺀 만큼에 대해 검사한다.
// N-i-1 (-1은 j와 j+1에 대해 검사하기에 필요없어서)
// 시간복잡도가 가장 안좋다. 

#include <algorithm>
using namespace std;

int main()
{
	int N, tmp;
	int num[101];

	cin >> N;
	for (int i; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (num[j] > num[j + 1]) {
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << num[i] << " ";
	}
	return 0;
}

