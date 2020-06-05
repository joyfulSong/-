//5C3이면 4C2(5포함, 나머지 2명만 뽑기) + 4C3(5포함X, 3명뽑기) 의 점화식 이용.
// nCr이 1이 될때 (n==r or r == 0)까지 조합을 쪼개어나가고, 다 쪼개면 1부터 스택프레임의 DFS에 넘겨주어 더해가며 bottom까지 내려가 값을 구한다.
//          5C3
//      4C2   + 4C3
//    3C1 + 3C2
//2C0 + 2C1
//   1C0 + 1C1
//     1   1

//그런데 앞서 2C0을 구했다면 다음에 또 2C0을 만나면 쪼개가며 구하지 말고 배열에 저장되어있는 것을 꺼내 쓰면되니, 메모이제이션.
//3C2이면 d[3][2]에 값을 저장 (이차원 배열, n,r에 해당하는 위치에 값 마킹)
//DFS가 d[n][r]을 리턴하는데, 이미 있다면 (d[n][r] >0) 바로 리턴.

//배열에 더해져서 저장되므로 출력시 DFS(n,r)해주면 타고 넘어오며 더해진 값이 리턴됨.
#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int d[21][21]; //0초기화

int DFS(int a, int b)
{
	if (d[a][b] > 0) return d[a][b];
	if (b == 0 || a == b) return 1;
	else {
		return d[a][b] = DFS(a - 1, b - 1) + DFS(a - 1, b);
	}
}
int main()
{
	int n, r;
	cin >> n >> r;

	cout << DFS(n, r);


	
}