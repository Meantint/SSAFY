#include <iostream>

using namespace std;

int r, c;
int tc;
int real_password[10] = {13, 25, 19, 61, 35, 49, 47, 59, 55, 11};

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        char board[50][100];
        int answer = 0;

        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> board[i][j];
            }
        }

        bool find = false;  // 찾으면 true
        int sav_r = -1, sav_c = -1;
        // 시작 좌표 찾아내기
        for (int i = r - 1; i >= 0; --i) {
            for (int j = c - 1; j >= 0; --j) {
                // 마지막 자리 1을 찾았다면 읽어낸다.
                if (board[i][j] == '1') {
                    sav_r = i;
                    sav_c = j - 55;
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        int password[8];
        int pass_idx = -1;
        int val = 0;
        for (int i = 0; i < 56; ++i) {
            val = (val << 1) + (board[sav_r][sav_c + i] - '0');
            // 7개를 읽었다면
            if (i % 7 == 6) {
                // cout << "val : " << val << '\n';
                for (int f = 0; f < 10; ++f) {
                    if (real_password[f] == val) {
                        password[++pass_idx] = f;
                        val = 0;
                        break;
                    }
                }
            }
        }
        // for (int i = 0; i < 8; ++i) {
        //     cout << "password " << i << " : " << password[i] << '\n';
        // }
        int sum = (password[0] + password[2] + password[4] + password[6]) * 3 + password[1] + password[3] + password[5] + password[7];
        if (sum % 10 == 0) {
            for (int i = 0; i < 8; ++i) {
                answer += password[i];
            }
        }
        else {
            answer = 0;
        }

        cout << '#' << t + 1 << ' ' << answer << '\n';
    }

    return 0;
}