#include <stdio.h>

#include <iostream>

using namespace std;

int tc, n, k, answer = -1;
int maxVal;
int board[8][8];
bool isVisited[8][8];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

int myDFS(int x, int y, bool isPos)
{
    int res = 1;
    int mid_res = 0;
    for (int i = 0; i < 4; ++i) {
        // printf("board cur (%d, %d, %d) -> %d\n", x, y, isPos, board[x][y]);
        // printf("i : %d\n", i);
        int cx = x + dx[i];
        int cy = y + dy[i];

        // 범위 안전 & 방문하지 않은 곳
        if (isSafe(cx, cy) && !isVisited[cx][cy]) {
            int tmp;
            if (board[x][y] > board[cx][cy]) {
                isVisited[cx][cy] = true;
                tmp = myDFS(cx, cy, isPos);
                isVisited[cx][cy] = false;
                if (mid_res < tmp) {
                    mid_res = tmp;
                }
            }
            else {
                if (isPos && board[x][y] > board[cx][cy] - k) {
                    isPos = false;
                    int sav = board[cx][cy];
                    board[cx][cy] = board[x][y] - 1;
                    // printf("board change (%d, %d, %d)\n", cx, cy, board[cx][cy]);

                    isVisited[cx][cy] = true;
                    tmp = myDFS(cx, cy, isPos);
                    isVisited[cx][cy] = false;

                    if (mid_res < tmp) {
                        mid_res = tmp;
                    }
                    board[cx][cy] = sav;
                    isPos = true;
                }
            }
        }
    }
    res += mid_res;

    return res;
}

void solve()
{
    answer = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            isVisited[i][j] = false;
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (board[r][c] == maxVal) {
                isVisited[r][c] = true;
                int tmp = myDFS(r, c, true);
                isVisited[r][c] = false;
                if (answer < tmp) {
                    answer = tmp;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        maxVal = -1;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &board[i][j]);

                if (maxVal < board[i][j]) {
                    maxVal = board[i][j];
                }
            }
        }

        solve();

        printf("#%d %d\n", t, answer);
    }

    return 0;
}