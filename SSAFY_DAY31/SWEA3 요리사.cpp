#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int tc, n, answer;
int team1[8], team2[8];
int board[16][16];

void myCal()
{
    int newSize = n / 2;
    int t1Val = 0;
    int t2Val = 0;

    // FOR(i, newSize)
    // {
    //     cout << team1[i] << ' ';
    // }
    // cout << '\n';
    // FOR(i, newSize)
    // {
    //     cout << team2[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            t1Val += board[team1[i]][team1[j]];
            t2Val += board[team2[i]][team2[j]];
        }
    }

    int res = t1Val - t2Val;
    // cout << "res : " << res << '\n';
    if (res < 0) {
        res *= -1;
    }
    if (answer > res) {
        answer = res;
    }
}

void myDFS(int cur, int t1Idx, int t2Idx)
{
    if (cur == n) {
        myCal();

        return;
    }

    if (t1Idx != n / 2) {
        team1[t1Idx] = cur;
        myDFS(cur + 1, t1Idx + 1, t2Idx);
    }
    if (t2Idx != n / 2) {
        team2[t2Idx] = cur;
        myDFS(cur + 1, t1Idx, t2Idx + 1);
    }
}

void solve()
{
    answer = 2112345678;
    team1[0] = 0;
    myDFS(1, 1, 0);
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }

        solve();

        cout << '#' << t << ' ' << answer << '\n';
    }

    return 0;
}