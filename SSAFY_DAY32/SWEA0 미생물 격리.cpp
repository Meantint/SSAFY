#include <stdio.h>

#include <iostream>

#define PII pair<int, int>

using namespace std;

int tc, n, m, k, answer;
PII board[100][100];
PII newBoard[100][100];
int sum[100][100];
int pIdx = -1;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void myInit()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum[i][j] = 0;
            newBoard[i][j].first = 0;
            newBoard[i][j].second = -1;
        }
    }
}

void boardInit()
{
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            board[r][c].first = 0;
            board[r][c].second = -1;
        }
    }
}

void simul()
{
    int curTime = 0;
    while (curTime != m) {
        myInit();
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                PII tmp = board[r][c];
                if (tmp.first != 0) {
                    int cx = r + dx[tmp.second - 1];
                    int cy = c + dy[tmp.second - 1];

                    if (cx == 0 || cx == n - 1 || cy == 0 || cy == n - 1) {
                        sum[cx][cy] += tmp.first / 2;
                        if (tmp.second < 3) {
                            newBoard[cx][cy].second = 3 - tmp.second;
                        }
                        else {
                            newBoard[cx][cy].second = 7 - tmp.second;
                        }
                    }
                    else {
                        if (newBoard[cx][cy].first < tmp.first) {
                            newBoard[cx][cy].first = tmp.first;
                            newBoard[cx][cy].second = tmp.second;
                        }
                        sum[cx][cy] += tmp.first;
                    }
                }
            }
        }
        boardInit();
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                board[r][c].second = newBoard[r][c].second;
                board[r][c].first = sum[r][c];
            }
        }
        ++curTime;
    }
}

void solve()
{
    answer = 0;

    simul();

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            answer += board[r][c].first;
        }
    }
}

int main()
{
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        scanf("%d %d %d", &n, &m, &k);
        boardInit();
        for (int i = 0; i < k; ++i) {
            pair<PII, PII> pos;
            scanf("%d %d %d %d", &pos.first.first, &pos.first.second, &pos.second.first, &pos.second.second);
            board[pos.first.first][pos.first.second].first = pos.second.first;
            board[pos.first.first][pos.first.second].second = pos.second.second;
        }

        solve();

        printf("#%d %d\n", t, answer);
    }
}