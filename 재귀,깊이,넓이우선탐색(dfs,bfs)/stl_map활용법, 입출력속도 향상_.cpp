//map은 문자열(string)이나 알파벳 카운팅시에 쓰는 stl이다.
// 벡터 유용하게 쓰는 나무재태크(삼성 기출) 다뤄보기
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //ios::sync_with_stdio로 해도 ios_base한테 상속받았기 때문에 괜찮다.
	//cin, cout의 동기화 해제. 속도를 scanf printf와 비슷하게 맞춰줌
	//단, 이거 쓰려면 c스타일과 c++스타일을 혼용해서 쓰면 안됨.
	// 기본적으로 c와 c++에 쓰이는 입출력용의 버퍼를 둘 다 쓰게 되는데, 이를 통해 c++용의 버퍼만 쓰겠다는 것이다.
	//cin.tie(NULL); cin과 cout의 버퍼를 묶어둔 것을 해제해줘서 더 빠르게 해준다.
	map<char, int> ch; //맵 자료구조. 키값 value값.
	//맵 자료구조는 접근하기 위한 반복자가 필요함 (배열처럼 접근 x)
	map<char, int>::iterator it; //포인터처럼 생각해도 됨.
	char a[100]; // 단어 저장, char 배열 대신에 string 써도 됨.
	cin >> a;
	for (int i = 0; a[i] != '\0'; i++) {
		// 공백만나면 종료하도록
		ch[a[i]]++;
		// ch라는 맵 자료형은 이진트리를 만들면서 키값과 value갑을 가진 노드를 만들고, 같은 키가 들어오면 value를 증가시킨다. 새로운 키가 들어오면 노드를 또 만든다.
		// key: a
		//   v: 1  -- > 2
		// key: b    key: c
		//   v: 1      v: 1 --> 2
	}
	// ch.begin() : 자료구조의 처음에 저장된 것을 가리킴.
	// ch.end(): 마지막자료의 뒷편, 빈공간을 가리킴. 그 공간에서 멈추는것.
	// 반복자 쓸 때 키값은 기본적으로 오름차순으로 정렬되도록 접근해서 출력. (a,b,c,d...)
		for(it=ch.begin(); it!=ch.end(); it++){
			cout << it->first << " " << it->second << "\n"; //first는 키값, second는 value값
	}
	
	return 0;
}

//string이면
#include <string>
map<string, int> ch; // iterator도 이렇게
int n; cin >> n;
char a[100];
for (int i = 1; i <= n; i++) {
	cin >> a;
	ch[a]++;
}
// n개의 단어를 받는데, 같은 키값(단어)로 들어오면 증가시킴.

//만약 가장 많이 등장한 단어 갯수와 출력을 하려면
int max = 0;
string res;
for (it = ch.begin(); it != ch.end(); it++) {
	if (it->second > max) {
		max = it->second; // max보다 큰 value값 만나면 갱신
		res = it->first; // 그 단어 저장.
	}
}