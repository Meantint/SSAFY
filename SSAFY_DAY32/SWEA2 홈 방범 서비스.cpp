#include <stdio.h>

#include <iostream>

using namespace std;

int tc, n, m, answer;
int areaCost[23];
int board[20][20];

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

int rangeCnt(int x, int y, int k)
{
    int cnt = 0;
    for (int i = -k + 1; i < k; ++i) {
        for (int j = -k + 1; j < k; ++j) {
            int ci = i;
            int cj = j;
            if (ci < 0) {
                ci *= -1;
            }
            if (cj < 0) {
                cj *= -1;
            }

            if (ci + cj < k && isSafe(x + i, y + j) && board[x + i][y + j] == 1) {
                ++cnt;
            }
        }
    }

    return cnt;
}

void solve()
{
    answer = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 1; k <= n + 1; ++k) {
                int homeCnt = rangeCnt(i, j, k);
                if (areaCost[k] <= homeCnt * m) {
                    // cout << "(x, y, k) : (" << i << ", " << j << ", " << k << ")"
                    //      << ", homecnt : " << homeCnt << '\n';
                    if (answer < homeCnt) {
                        answer = homeCnt;
                    }
                }
            }
            // cout << '\n';
        }
    }
}

int main()
{
    for (int i = 1; i < 23; ++i) {
        areaCost[i] = (i * i) + (i - 1) * (i - 1);
    }
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &board[i][j]);
            }
        }

        solve();

        printf("#%d %d\n", t, answer);
    }

    return 0;
}