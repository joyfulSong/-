// 배열에 알파벳 해당 갯수 저장해서 두 배열을 비교하는 해싱 기법으로 접근
// 단, 알파벳을 어떻게 숫자로 혹은 if문으로 처리해 배열에 넣느냐 에서 아이디어가 없었는데, 아스키넘버 활용
// 대문자: 65~90, 소문자: 97~121번: 대문자는 -64해서 1부터 26까지, 소문자는 -70해서 27부터 52까지.

#include <iostream>
#include <algorithm>
using namespace std;
int A[60], B[60]; // 알파벳 인덱싱, 갯수 저장용, 최대 알파벳 수는 52개

int main()
{
	char str[100]; //char형으로 받아서 하나하나씩 확인

	cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) // 대문자
		{
			A[str[i] - 64]++; // str[i]에 해당하는 인덱스 증가시킴.
		}
		else // 소문자, 조건문 필요없음
		{
			A[str[i] - 70]++;
		}
	}

	cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) // 대문자
		{
			B[str[i] - 64]++; // str[i]에 해당하는 인덱스 증가시킴.
		}
		else // 소문자, 조건문 필요없음
		{
			B[str[i] - 70]++;
		}
	}
	
	for (int i = 1; i <= 52; i++) { // A, B 각각에 저장된 인덱싱 넘버를 비교해나감
		if (A[i] != B[i]) {
			cout << "NO"; //하나라도 인덱스 넘버가 다르면 서로 아나그램이 아님, 종료
			exit(0); //이건 algorithm stl
		}
	}
	cout << "YES";
	return 0;

}