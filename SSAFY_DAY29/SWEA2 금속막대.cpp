#include <iostream>

using namespace std;

int tc, n;
int** arr;
int* memo;
int* indirect;

void myDFS(int cur)
{
    if (memo[cur] != -1) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        // 나사가 일치한다면
        if (arr[cur][1] == arr[i][0]) {
            if (memo[i] != -1) {
                memo[cur] = memo[i] + 1;
                return;
            }
            else {
                myDFS(i);
                memo[cur] = memo[i] + 1;
                return;
            }
        }
    }
    // 하나도 일치하는 것이 없다면
    memo[cur] = 1;
}

void solve()
{
    for (int i = 0; i < n; ++i) {
        myDFS(i);
        // for (int j = 0; j < n; ++j) {
        //     cout << memo[j] << ", ";
        // }
        // cout << '\n';
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << memo[i] << '\n';
    // }

    for (int i = 0; i < n; ++i) {
        indirect[n - memo[i]] = i;
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        // 초기화 & input
        cin >> n;
        arr = new int*[n];
        memo = new int[n];
        indirect = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[2];
            memo[i] = -1;
            cin >> arr[i][0] >> arr[i][1];
        }

        solve();

        // for (int i = 0; i < n; ++i) {
        //     cout << indirect[i] << ' ';
        // }
        // cout << '\n';
        // for (int i = 0; i < n; ++i) {
        //     cout << arr[i][0] << ' ' << arr[i][1] << ' ';
        // }
        // cout << '\n';
        cout << '#' << t << ' ';
        for (int i = 0; i < n; ++i) {
            cout << arr[indirect[i]][0] << ' ' << arr[indirect[i]][1] << ' ';
        }
        cout << '\n';
    }

    return 0;
}