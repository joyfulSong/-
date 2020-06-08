
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;
int n, m, dis, res = 2147000000; //도시의 피자배달거리의 최솟값 갱신 저장용. 초기값은 max로 잡아둠. 
int ch[20]; //pz인덱스번호의 조합을 저장

vector<pair<int, int>> hs; //집주소 
vector<pair<int, int>> pz; //피자집주소

void DFS(int s, int L) {
	if (L == m) {
		int sum = 0; //
		//피자집의 조합이 만들어지면 모든 집에 대해서 0부터 m-1까지의 인덱스 번호에 맞는 피자집과의 거리를 구해 최솟값만 저장한다.
		for (int i = 0; i < n; i++) {
			dis = 2147000000; //j for문에서는 dis가 계속 갱신되면서 그 집의 최소 피자배달거리를 구하지만, 새로운 집에 대해서는 또 다시 min값이 필요함.
			for (int j = 0; j < m; j++) {
				dis = min(dis,abs(pz[ch[j]].first - hs[i].first) + abs(pz[ch[j]].second - hs[i].second));
				// i번째의 집과 각 j 번째 피자집과의 거리값을 구해 최솟값을 구한다. --> 그 집의 피자배달거리
			}
			// i번째 집의 모든 피자집에 대한 거리 계산후 남은 dis를 sum에 저장한다.
			// i for문이 끝나면 최솟값들의 합이 sum가 된다. --> 이 조합의 '도시의 피자배달거리'
			sum += dis;
		}
		// 현재 조합으로 구한 도시의 피자 배달거리가 기존의 res보다 작으면 최솟값을 갱신한다.
		if (sum < res) res = sum;
	}

	else {
		for (int i = s; i < pz.size(); i++) { //m은 뽑을 갯수이고, 사용할 수 있는 갯수는 pz의 사이즈이다.
			ch[L] = i;
			DFS(i + 1, L + 1);
		}
	}
}
int main()
{
	int n, m, a;
	int a[51][51];

	cin >> n >> m;

	//내코드: 읽은 배열을 또 읽어서 1,2인지 참고할 필욘 없다.
	/*for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				hs.push_back({ i,j });
			}
			if (a[i][j] == 2) { //else if가 아니면 이 if문을 지나치게 됨.
				pz.push_back({ i,j });
			}
		}
	}*/

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> a;
			if (a == 1) {
				hs.push_back({ i,j }); //make pair로.
			}
			else if (a == 2) {
				pz.push_back({ i,j });
			}
		}
	}

	DFS(0, 0); 

	cout << res;
	return 0;
}