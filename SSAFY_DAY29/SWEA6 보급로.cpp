#include <iostream>

using namespace std;

int tc, n;
char board[100][100];
int memo[100][100];

// 상 우 하 좌
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

// cur = xPos * 100 + yPos
void dijkstra(int cur)
{
    int x = cur / 100;
    int y = cur % 100;

    if (x == n - 1 && y == n - 1) {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (isSafe(cx, cy)) {
            int tmp = memo[x][y] + (board[cx][cy] - '0');
            if (memo[cx][cy] > tmp) {
                memo[cx][cy] = tmp;
                dijkstra(cx * 100 + cy);
            }
        }
    }
}

void solve()
{
    int init = 0;
    for (int i = 0; i < n; ++i) {
        init += (board[i][0] - '0');
    }
    for (int j = 1; j < n; ++j) {
        init += (board[n - 1][j] - '0');
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            memo[i][j] = init;
        }
    }

    memo[0][0] = board[0][0] - '0';

    dijkstra(0);
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << memo[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        // 초기화 & input
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        solve();

        cout << '#' << t << ' ' << memo[n - 1][n - 1] << '\n';
    }

    return 0;
}