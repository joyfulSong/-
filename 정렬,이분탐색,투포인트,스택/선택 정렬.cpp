// 선택정렬: i, j로 이중포문을 돈다.
// i와 j를 비교해 작은 값을 찾아 위치를 저장해가며, 가장 작은 값으로 반복문이 마무리 되면
// 가장 작은 수의 위치와 i를 바꿔주어 앞부터 작은 숫자로 채워간다. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, idx, tmp; //idx는 인덱스 저장용, tmp는 swap용
	int arr[100];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		idx = i;
		for (int j = i+1; j < N; j++) {
			if (arr[j] < arr[idx]) idx = j;
		}
		tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}
	
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
