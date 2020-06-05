// 날짜를 큰수부터 스케줄링한다. 첫째날부터 큰 가격을 매겨버렸는데, 그 값이 날짜에 여유가 있었다면 그 여유를 활용해서 앞선 날짜들과 함께놓고 비교할 수 있는 것을 활용 못하기 때문이다.
// 구조체에 값과 날짜를 넣고, 날짜 순으로 내림차순 정렬한 뒤, 
// max heap 우선순위 큐를 사용해 날짜안에(2이면 3일째, 2일째 모두 들어가 있을 수 있다) 가능한 값들이 큐에 있어 그중에 max root를 pop해서 최댓값을 만든다.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

// 클래스의 은닉화, 상속이 필요 없기에 구조체를 사용한다.
struct Data { //하나의 데이터형. (메모리가 두 자료형 묶어 잡히고, 주소 1개)
	int money;
	int when;
	Data(int a, int b) {
		// 생성자 (매개변수 이름과 같다). 매개변수가 있는. (기본 생성자가 아님)
		money = a;
		when = b;
	}

	//이 구조체에 대해 비교연산자가 필요할 경우, 이와같이 오버로딩된 비교연산자를 만들어줘야한다.
	//sort에서 Data 구조체형 벡터를 정렬하는데 비교연산자가 필요하다. (sort의 파라미터로 comp가 내부적으로 들어가는데, 두 값의 선후구조를 판별할 bool값이다.)
	// 현재 갖고있는 주소의 날짜값과 비교하고자 하는 주소의 날짜값을 비교해 현재값이 크면 1을 리턴한다.
	// 이에 따라 내림차순으로 정렬된다. ( <인것은 비교연산자 오버로딩의 기본이 이렇게 설정되어있음. >이 아니라. 모양만 주시)
	bool operator < (Data& b) {
		return when > b.when;
	}
	// money는 b와 함께 움직이니 같이 정렬된다.

};

int main()
{
	int n, m, d, res = 0, max = -2147000000;

	cin >> n;

	vector<Data> T; // 구조체를 사용한다. 사용자 정의 자료형을 쓸 수 있다.
	priority_queue<int> pQ; // 값 최댓값 얻을용도.

	for (int i = 1; i <= n; i++) {
		cin >> m >> d;
		T.push_back(Data(m, d));
		if (d > max)max = d; //날짜 최댓값 갱신용
	}
	sort(T.begin(), T.end()); //내림차순 정렬

	int j = 0;
	for (int i = max; i >= 1; i--) {
		//최대 날짜부터 거꾸로 내려옴
		for (; j < n; j++) {
			//j를 for문 바깥에서 초기화하므로, j는 갱신된다. 강연갯수만큼 돌면서 날짜 안에 가능한 값들을 큐에 넣는다.
			if (T[j].when < i) break; // 날짜기준으로 내림차순 정렬된 구조체의 0번째부터 n번째 까지 돌며, 날짜가 현재 i보다 작으면 (3일째꺼 보려는데 2일것을 넣으려고 한다던지) 큐에 넣지 않는다. 3일거 비교 끝나고 다음 반복떄 넣을것.
			pQ.push(T[j].money); // 큐에 넣으면 자동으로 최대힙정렬된다.
		}
		if(!pQ.empty()){
			res += pQ.top(); //최댓값을 빼서 더한다.
			pQ.pop();
		}
	}

	cout << res;
}