#include <iostream>

using namespace std;

int tc, n;
int spIdx = -1;
int savePos[20][2];  // (x_len, y_len);
int dp[20][20];
int indirect[20];
int memo[20];
int board[100][100];

void myDFS(int cur)
{
    if (memo[cur] != -1) {
        return;
    }
    for (int i = 0; i <= spIdx; ++i) {
        // 나사가 일치한다면
        if (savePos[cur][1] == savePos[i][0]) {
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

bool isPos(int x, int y)
{
    if (x == 0 && y == 0) {
        return true;
    }
    else if (x == 0 && y != 0) {
        if (board[x][y - 1] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else if (x != 0 && y == 0) {
        if (board[x - 1][y] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if (board[x - 1][y] != 0 || board[x][y - 1] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
}

void mySearch(int x, int y)
{
    int r, c;
    for (r = x; board[r][y] != 0; ++r) {
    }
    for (c = y; board[x][c] != 0; ++c) {
    }
    // cout << "r : " << r << ", c : " << c << '\n';
    savePos[++spIdx][0] = r - x;
    savePos[spIdx][1] = c - y;

    return;
}

int solve()
{
    // 다 탐색한다.
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (board[r][c] != 0 && isPos(r, c)) {
                // savePos에 넣어준다.
                mySearch(r, c);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        myDFS(i);
    }

    for (int i = 0; i <= spIdx; ++i) {
        indirect[spIdx - memo[i] + 1] = i;
    }
    for (int i = 0; i <= spIdx; ++i) {
        for (int j = 0; j <= spIdx; ++j) {
            dp[i][j] = 2112345678;
        }
    }
    for (int i = 0; i <= spIdx; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= spIdx; ++i) {
        for (int st = 0; st <= spIdx; ++st) {
            if (st + i > spIdx) {
                continue;
            }
            for (int k = 0; k < i; ++k) {
                int tmp = dp[st][st + k] + dp[st + k + 1][st + i] + (savePos[indirect[st]][0] * savePos[indirect[st + k]][1] * savePos[indirect[st + i]][1]);
                if (dp[st][st + i] > tmp) {
                    dp[st][st + i] = tmp;
                }
            }
        }
    }
    // for (int i = 0; i <= spIdx; ++i) {
    //     for (int j = 0; j <= spIdx; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    return dp[0][spIdx];
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        // 초기화 && input
        spIdx = -1;
        cin >> n;
        for (int i = 0; i < 20; ++i) {
            memo[i] = -1;
            savePos[i][0] = savePos[i][1] = 0;
            // indirect[i] = i;
        }
        for (int r = 0; r < 100; ++r) {
            for (int c = 0; c < 100; ++c) {
                board[r][c] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }

        cout << '#' << t << ' ' << solve() << '\n';
    }

    return 0;
}