#include <iostream>

using namespace std;

bool isVisited[16][16];
char board[16][16];
int queue[10000];
int front, rear;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 0;

bool isSafe(int x, int y)
{
    if (x >= 0 && x < 16 && y >= 0 && y < 16) {
        return true;
    }
    return false;
}

void solve(int x, int y)
{
    // 점 좌표를 하나의 변수로 나타냄(16 * 16 고정이기 때문에)
    queue[++rear] = x * 16 + y;

    while (front != rear) {
        int cx = queue[++front] / 16;
        int cy = queue[front] % 16;

        if (board[cx][cy] == '3') {
            answer = 1;
            return;
        }

        if (isVisited[cx][cy]) {
            continue;
        }
        isVisited[cx][cy] = true;

        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            if (isSafe(ccx, ccy) && (board[ccx][ccy] == '0' || board[ccx][ccy] == '3') && !isVisited[ccx][ccy]) {
                queue[++rear] = ccx * 16 + ccy;
            }
        }
    }

    return;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        front = -1, rear = -1;

        int test_case;
        cin >> test_case;

        for (int r = 0; r < 16; ++r) {
            for (int c = 0; c < 16; ++c) {
                cin >> board[r][c];
                isVisited[r][c] = false;
            }
        }

        answer = 0;
        board[1][1] = '0';
        solve(1, 1);

        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;
}