#include <iostream>

using namespace std;

int tc, row, col;
bool answer;

int queue[3000];
int dir[3000];
int queue_val[3000];
bool isVisited[20][20][4][16];

int front, rear;

// 상하좌우 순
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve(char board[][20])
{
    // 초기 포지션 (0, 0)
    queue[++rear] = 0 * 20 + 0;
    // 초기 값
    queue_val[rear] = 0;
    // 초기 방향 오른쪽
    dir[rear] = 3;

    while (rear < 3000 && front != rear) {
        int x = queue[++front] / 20;
        int y = queue[front] % 20;
        int cur_dir = dir[front];
        int cur_val = queue_val[front];

        if (isVisited[x][y][cur_dir][cur_val]) {
            continue;
        }
        isVisited[x][y][cur_dir][cur_val] = true;

        char val = board[x][y];
        if (val == '<' || val == '>' || val == 'v' || val == '^') {
            if (val == '^') {
                dir[++rear] = 0;
            }
            else if (val == 'v') {
                dir[++rear] = 1;
            }
            else if (val == '<') {
                dir[++rear] = 2;
            }
            else if (val == '>') {
                dir[++rear] = 3;
            }
            queue_val[rear] = cur_val;
        }
        else if (val == '_') {
            if (cur_val == 0) {
                dir[++rear] = 3;
            }
            else {
                dir[++rear] = 2;
            }
            queue_val[rear] = cur_val;
        }
        else if (val == '|') {
            if (cur_val == 0) {
                dir[++rear] = 1;
            }
            else {
                dir[++rear] = 0;
            }
            queue_val[rear] = cur_val;
        }
        else if (val >= '0' && val <= '9') {
            dir[++rear] = cur_dir;
            queue_val[rear] = val - '0';
        }
        else if (val == '@') {
            answer = true;
            return;
        }
        else if (val == '+') {
            dir[++rear] = cur_dir;
            queue_val[rear] = (cur_val + 17) % 16;
        }
        else if (val == '-') {
            dir[++rear] = cur_dir;
            queue_val[rear] = (cur_val + 15) % 16;
        }
        else if (val == '?') {
            for (int i = 0; i < 4; ++i) {
                dir[++rear] = i;
                queue[rear] = ((x + dx[dir[rear]] + row) % row) * 20 + (y + dy[dir[rear]] + col) % col;
                queue_val[rear] = cur_val;
            }
            continue;
        }
        // '.'
        else {
            dir[++rear] = cur_dir;
            queue_val[rear] = cur_val;
        }
        queue[rear] = ((x + dx[dir[rear]] + row) % row) * 20 + (y + dy[dir[rear]] + col) % col;
    }

    return;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        // 초기화
        for (int r = 0; r < 20; ++r) {
            for (int c = 0; c < 20; ++c) {
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 16; ++j) {
                        isVisited[r][c][i][j] = false;
                    }
                }
            }
        }
        answer = false;
        front = -1, rear = -1;
        cin >> row >> col;

        char board[20][20];
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                cin >> board[r][c];
            }
        }
        solve(board);

        if (answer) {
            cout << '#' << t + 1 << ' ' << "YES" << '\n';
        }
        else {
            cout << '#' << t + 1 << ' ' << "NO" << '\n';
        }
    }

    return 0;
}