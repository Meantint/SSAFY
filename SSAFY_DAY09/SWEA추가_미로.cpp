#include <iostream>

using namespace std;

bool isVisited[16][16];
char board[16][16];

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
    if (board[x][y] == '3') {
        answer = 1;
        return;
    }

    isVisited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (isSafe(cx, cy) && (board[cx][cy] == '0' || board[cx][cy] == '3') && !isVisited[cx][cy]) {
            solve(cx, cy);
        }
    }

    isVisited[x][y] = false;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
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