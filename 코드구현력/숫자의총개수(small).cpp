// AA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int main()
{
    //freopen("input.txt", "rt", stdin); //채점할때는 주석처리하고 컴파일 후에 복붙하길.
    int n, tmp, cnt = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        tmp = i;
        while (tmp > 0) {
            tmp = tmp / 10;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}


