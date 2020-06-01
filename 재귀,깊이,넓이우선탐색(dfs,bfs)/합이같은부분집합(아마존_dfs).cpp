// 부분집합을 만들 때 어떤 수열들을 만들어 각각의 합을 따져보는 접근이 아니라,
// DFS의 특징을 사용해서 완전탐색(사실은 방향성을 가진 무작위 순서)으로 합을 만든다.
// 숫자들로 레벨을 이루고, 레벨단위로 작업을 수행한다.

// sum에 숫자들을 더해가며 total/2까지를 종료 시점으로 둔다.
// 만약 total - sum == sum이면, 그 탐색과정에서의 부분집합은 남은 숫자들과 합이 같은 것이다. 
// 수를 더한다 / 안더한다 두가지 경우로 나누어 탐색이 진행된다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ch[11], total = 0;
bool flag = false; //한번 찾으면 더이상 함수 실행 안하도록.

void DFS(int L, int sum) {
	if (sum > total / 2) return; // 현재의 스택프레임에서 실행중인 함수에서 sum이 total의 절반보다 크면 그 함수 프로세스 종료, 아래 스택으로 넘어감.
	if (flag == true) return;
	if ((total - sum) == sum) flag = true;
	else {
			DFS(L + 1, sum + ch[L + 1]);
			DFS(L + 1, sum); // 현재 수를 안더하고 진행한다.
		}
	}

int main()
{
	int	n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ch[i];
		total += ch[i];
	}
	DFS(ch[0], 0);
	if (flag == true) cout << "YES";
	else cout << "NO";
	
	return 0;
}
 