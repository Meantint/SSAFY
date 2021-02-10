#include <iostream>

using namespace std;

int tc, n;
int isVisited[1000][1000];
int board[1000][1000];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

int solve(int x, int y)
{
    for (int i = 0; i < 4; ++i) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (isSafe(cx, cy)) {
            if (isVisited[cx][cy] != -1 && board[x][y] + 1 == board[cx][cy]) {
                isVisited[x][y] = isVisited[cx][cy] + 1;
                break;
            }
            else if (isVisited[cx][cy] == -1 && board[x][y] + 1 == board[cx][cy]) {
                isVisited[x][y] = solve(cx, cy) + 1;
            }
        }
    }
    if (isVisited[x][y] == -1) {
        isVisited[x][y] = 1;
    }
    return isVisited[x][y];
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
                isVisited[i][j] = -1;
            }
        }
        int answer = 0, max_num = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isVisited[i][j] == -1) {
                    int comp = solve(i, j);
                    if (max_num < comp) {
                        answer = board[i][j];
                        max_num = comp;
                    }
                    else if (max_num == comp && answer > board[i][j]) {
                        answer = board[i][j];
                    }
                }
            }
        }
        cout << '#' << t + 1 << ' ' << answer << ' ' << max_num << '\n';
    }

    return 0;
}