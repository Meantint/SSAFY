#include <iostream>

using namespace std;

int n, tc;
char board[100][100];
int cost_board[100][100];
bool isVisited[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer;

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

void dfs(int x, int y)
{
    if (x == n - 1 && y == n - 1) {
        if (answer > cost_board[x][y]) {
            answer = cost_board[x][y];
        }
        return;
    }
    isVisited[x][y] = true;
    // 도착하기 전에 이미 비용이 정답보다 크다면 탐색 중단한다.
    if (answer <= cost_board[x][y]) {
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        // 범위 점검
        if (!isSafe(cx, cy)) {
            continue;
        }
        if (!isVisited[cx][cy] || cost_board[cx][cy] > cost_board[x][y] + (board[cx][cy] - '0')) {
            cost_board[cx][cy] = cost_board[x][y] + (board[cx][cy] - '0');
            isVisited[cx][cy] = true;
            dfs(cx, cy);
        }
    }
}

void solve()
{
    // 초기화
    answer = 2112345678;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cost_board[i][j] = 2112345678;
        }
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            isVisited[i][j] = false;
        }
    }

    cost_board[0][0] = 0;
    dfs(0, 0);
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

        cout << '#' << t + 1 << ' ' << answer << '\n';
    }

    return 0;
}