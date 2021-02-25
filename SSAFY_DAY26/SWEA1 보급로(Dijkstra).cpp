#include <iostream>

using namespace std;

int n, tc;
char board[100][100];
int dijkstra_board[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// queue
int myQueue[100000][3];
int front, rear = -1;

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

void dijkstra()
{
    dijkstra_board[0][0] = 0;

    myQueue[++rear][0] = 0;
    myQueue[rear][1] = 0;
    myQueue[rear][2] = 0;
    while (front != rear) {
        int x = myQueue[++front][0];
        int y = myQueue[front][1];
        int cur_dist = myQueue[front][2];

        if (dijkstra_board[x][y] < cur_dist) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];

            // 범위 안 벗어난다면
            if (isSafe(cx, cy)) {
                int next_dist = cur_dist + (board[cx][cy] - '0');
                if (dijkstra_board[cx][cy] > next_dist) {
                    dijkstra_board[cx][cy] = next_dist;
                    myQueue[++rear][0] = cx;
                    myQueue[rear][1] = cy;
                    myQueue[rear][2] = next_dist;
                }
            }
        }
    }
}

void solve()
{
    front = rear = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dijkstra_board[i][j] = 2112345678;
        }
    }

    dijkstra();
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        solve();

        cout << '#' << t + 1 << ' ' << dijkstra_board[n - 1][n - 1] << '\n';
    }

    return 0;
}