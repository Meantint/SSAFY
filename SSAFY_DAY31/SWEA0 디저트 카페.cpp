#include <stdio.h>

#include <iostream>

using namespace std;

int tc, n;
int answer;
int board[20][20];
int save[40];
int saveIdx = -1;
pair<int, int> stPos;

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

// 같은 값이 있는지
bool isSame(int val)
{
    for (int i = 0; i <= saveIdx; ++i) {
        if (save[i] == val) {
            return true;
        }
    }
    return false;
}

void myDFS(int x, int y, int dir, int cnt)
{
    // printf("(%d, %d) : %d, direction : %d\n", x, y, board[x][y], dir);
    if (cnt != 0 && stPos.first == x && stPos.second == y) {
        if (dir != 3) {
            return;
        }
        // printf("x : %d, y : %d\n", x, y);
        if (answer < cnt) {
            answer = cnt;
        }
        return;
    }
    if (!isSame(board[x][y])) {
        save[++saveIdx] = board[x][y];
        ++cnt;
    }
    else {
        return;
    }

    int cx = x + dx[dir];
    int cy = y + dy[dir];
    if (isSafe(cx, cy)) {  // 뻗어나갈 수 있다면
        myDFS(cx, cy, dir, cnt);
    }
    int nextDir = dir + 1;
    if (nextDir == 4) {
        --saveIdx;
        return;
    }

    cx = x + dx[nextDir];
    cy = y + dy[nextDir];
    if (isSafe(cx, cy)) {
        myDFS(cx, cy, nextDir, cnt);
    }
    --saveIdx;
    return;
}

void solve()
{
    answer = -1;
    saveIdx = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // printf("new : (%d, %d)\n", i, j);
            stPos.first = i;
            stPos.second = j;
            myDFS(i, j, 0, 0);
        }
    }
}

int main()
{
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        scanf("%d", &n);
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