#include <iostream>

using namespace std;

int tc, n;
double board[16][16];
double isVisited[16][(1 << 16)];

void solve(int x, int memo)
{
    if (x == n) {
        return;
    }
    for (int c = 0; c < n; ++c) {
        // 아직 방문하지 않았다면
        if ((memo & (1 << c)) == 0) {
            int new_memo = (memo | (1 << c));

            double comp = isVisited[x - 1][memo] * board[x][c];
            // 이전에 방문한 적이 있다면
            if (isVisited[x][new_memo] != -1.00) {
                if (isVisited[x][new_memo] < comp) {
                    isVisited[x][new_memo] = comp;
                }
                else {
                    continue;
                }
            }
            // 한 번도 방문한 적이 없다면
            else if (isVisited[x][new_memo] == -1.00) {
                isVisited[x][new_memo] = comp;
            }

            solve(x + 1, new_memo);
        }
    }

    return;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        cin >> n;
        // 초기화
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                isVisited[i][j] = -1.00;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
                board[i][j] /= 100.0;
            }
        }
        for (int c = 0; c < n; ++c) {
            int memo = (1 << c);
            isVisited[0][memo] = board[0][c];
            solve(1, memo);
        }

        int full = (1 << n) - 1;

        cout << fixed;
        cout.precision(6);
        cout << '#' << t + 1 << ' ' << isVisited[n - 1][full] * 100.0 << '\n';
    }

    return 0;
}