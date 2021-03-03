#include <iostream>

using namespace std;

int tc;
int n, m;
int pos_x, pos_y;
int isBlack;
int board[8][8];
int answer_black, answer_white;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

void myCnt()
{
    answer_black = 0;
    answer_white = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) {
                ++answer_black;
            }
            else if (board[i][j] == 2) {
                ++answer_white;
            }
        }
    }
}

void solve(int x, int y)
{
    board[x][y] = isBlack;
    for (int i = 0; i < 8; ++i) {
        int cx = x + dx[i];
        int cy = y + dy[i];

        int cnt = 0;
        // 범위 안 벗어날 때만 검사
        while (isSafe(cx, cy)) {
            if (isBlack + board[cx][cy] == 3) {
                cx += dx[i];
                cy += dy[i];
                ++cnt;
            }
            // 같은 값일 때
            else if (isBlack == board[cx][cy]) {
                for (int st = 1; st <= cnt; ++st) {
                    board[x + dx[i] * st][y + dy[i] * st] = isBlack;
                }
                break;
            }
            // 빈곳이 있으면 검사할 필요 X
            else if (board[cx][cy] == 0) {
                break;
            }
        }
    }
    /*
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> n >> m;
        int mid_pos = n / 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = 0;
            }
        }
        board[mid_pos][mid_pos] = board[mid_pos - 1][mid_pos - 1] = 2;
        board[mid_pos - 1][mid_pos] = board[mid_pos][mid_pos - 1] = 1;

        for (int i = 0; i < m; ++i) {
            cin >> pos_x >> pos_y >> isBlack;
            solve(pos_x - 1, pos_y - 1);
        }
        myCnt();
        cout << '#' << t << ' ' << answer_black << ' ' << answer_white << '\n';
    }

    return 0;
}