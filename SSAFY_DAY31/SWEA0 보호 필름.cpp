#include <stdio.h>

#include <iostream>

using namespace std;

int tc, n, m, k;
int cnt;
int answer;
int board[13][20];
int rowInfo[13];

bool isPass()
{
    for (int c = 0; c < m; ++c) {
        bool tmp = false;
        int prev = board[0][c];
        if (rowInfo[0] != -1) {
            prev = rowInfo[0];
        }
        int cnt = 1;
        for (int r = 1; r < n; ++r) {
            int cur = board[r][c];
            if (rowInfo[r] != -1) {
                cur = rowInfo[r];
            }

            if (prev == cur) {
                ++cnt;
            }
            else {
                prev = cur;
                cnt = 1;
            }
            if (cnt == k) {
                tmp = true;
                break;
            }
        }
        if (!tmp) {
            return false;
        }
    }

    return true;
}

void myDFS(int cur, int num)
{
    // 패스 가능하다면
    if (isPass()) {
        if (answer > cnt) {
            // printf("answer change : %d -> %d\n", answer, cnt);
            answer = cnt;
        }
        return;
    }

    // printf("cur : %d, num : %d, cnt : %d\n", cur, num, cnt);
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         if (rowInfo[i] != -1) {
    //             printf("%d ", rowInfo[i]);
    //         }
    //         else {
    //             printf("%d ", board[i][j]);
    //         }
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    // 현재 답보다 큰 탐색을 하고 있다면 종료
    if (answer < cnt) {
        return;
    }

    bool isSame = true;
    for (int i = 0; i < m; ++i) {
        if (board[cur][i] != num) {
            isSame = false;
            break;
        }
    }

    if (!isSame) {
        rowInfo[cur] = num;
        ++cnt;
    }
    for (int i = cur + 1; i <= n; ++i) {
        myDFS(i, 0);
        myDFS(i, 1);
    }
    if (!isSame) {
        --cnt;
        rowInfo[cur] = -1;
    }
}

void solve()
{
    answer = 2112345678;
    cnt = 0;
    for (int i = 0; i < 13; ++i) {
        rowInfo[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        myDFS(i, 0);
        myDFS(i, 1);
    }
}

int main()
{
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> board[i][j];
            }
        }

        solve();

        printf("#%d %d\n", t, answer);
    }

    return 0;
}