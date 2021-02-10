#include <iostream>

using namespace std;

int r, c;
int tc;
// 맨 앞의 0 개수와 상관없이 값을 유추할 수 있다.
int real_password[10][3] = {
    {2, 1, 1},
    {2, 2, 1},
    {1, 2, 2},
    {4, 1, 1},
    {1, 3, 2},
    {2, 3, 1},
    {1, 1, 4},
    {3, 1, 2},
    {2, 1, 3},
    {1, 1, 2},
};
char board[2000][500];

int solve(bool isVisited[][500])
{
    int answer = 0;
    // 시작 좌표 찾아내기
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            // 이미 방문했다면
            if (isVisited[i][j]) {
                continue;
            }
            // 시작 값이 0이 아닌 것을 찾았다면
            if (board[i][j] != '0') {
                int cp_i = i;
                int cp_j = j;
                // 뒤의 3개의 숫자비만 알아도 값을 유추할 수 있다.
                int comp[3] = {0};
                int comp_idx = -1;
                // 이전에 숫자가 0이었는지
                bool isZero = true;
                // 8자리 찾아서 저장해놓는 배열
                int password[8];
                int pass_idx = 0;

                // 패스워드 8개를 모두 채울 때까지 동작
                while (pass_idx < 8) {
                    int hex_to_bin[4];
                    int htb_idx = 3;

                    // board[i][j]의 값 검사
                    int num;
                    // 숫자라면
                    if (board[i][cp_j] >= '0' && board[i][cp_j] <= '9') {
                        num = board[i][cp_j] - '0';
                    }
                    // 알파벳이라면
                    else {
                        num = (board[i][cp_j] - 'A') + 10;
                    }

                    while (htb_idx >= 0) {
                        hex_to_bin[htb_idx] = num % 2;
                        num /= 2;
                        --htb_idx;
                    }
                    // cout << "hex_to_bin\n";
                    // for (int i = 0; i < 4; ++i) {
                    //     cout << hex_to_bin[i] << ' ';
                    // }
                    // cout << '\n';
                    for (int f = 0; f < 4; ++f) {
                        // cout << "cp_j : " << cp_j << '\n';
                        // cout << comp[0] << ", " << comp[1] << ", " << comp[2] << '\n';
                        // 이전 값이 0이었고 이번 값이 1이라면
                        if (isZero && hex_to_bin[f] == 1) {
                            isZero = false;
                            ++comp[++comp_idx];
                        }
                        // 이전 값이 1이었고 이번 값도 1이라면
                        else if (!isZero && hex_to_bin[f] == 1) {
                            ++comp[comp_idx];
                        }
                        // 이전 값이 0이었고 이번 값도 0이라면, 그리고 comp_idx가 -1이 아니라면
                        else if (isZero && hex_to_bin[f] == 0 && comp_idx != -1) {
                            ++comp[comp_idx];
                        }
                        // 이전 값이 1이었고 이번 값이 0이라면
                        else if (!isZero && hex_to_bin[f] == 0) {
                            // comp_idx가 2(4개 다 탐색했다면)라면, 암호의 마지막 수는 무조건 1이므로 이 케이스만 적용시켜주면됨.
                            if (comp_idx == 2) {
                                for (int rr = 0; rr < 10; ++rr) {
                                    int test[3];
                                    for (int cc = 0; cc < 3; ++cc) {
                                        if (comp[cc] % real_password[rr][cc] != 0) {
                                            test[cc] = -1 * (cc + 1);
                                        }
                                        else {
                                            test[cc] = comp[cc] / real_password[rr][cc];
                                        }
                                    }
                                    // 일치 암호라면
                                    if (test[0] == test[1] && test[1] == test[2]) {
                                        password[pass_idx] = rr;
                                        // cout << "pass_idx : " << pass_idx << ", rr : " << rr << '\n';
                                        ++pass_idx;
                                        // cout << comp[0] << ", " << comp[1] << ", " << comp[2] << '\n';
                                        comp[0] = 0;
                                        comp[1] = 0;
                                        comp[2] = 0;
                                        break;
                                    }
                                }
                                comp_idx = -1;
                                isZero = true;
                            }
                            else {
                                isZero = true;
                                ++comp[++comp_idx];
                            }
                        }
                    }
                    ++cp_j;
                }
                // --cp_j;
                while (++cp_i < r && board[cp_i][j] != '0') {
                }
                // --cp_i;
                for (int ii = i; ii < cp_i; ++ii) {
                    for (int jj = j; jj < cp_j; ++jj) {
                        isVisited[ii][jj] = true;
                    }
                }
                int sum = (password[0] + password[2] + password[4] + password[6]) * 3 + password[1] + password[3] + password[5] + password[7];
                if (sum % 10 == 0) {
                    for (int i = 0; i < 8; ++i) {
                        // cout << "password " << i << " : " << password[i] << '\n';
                        answer += password[i];
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> board[i][j];
            }
        }
        bool isVisited[2000][500] = {0};

        cout << '#' << t + 1 << ' ' << solve(isVisited) << '\n';
    }

    return 0;
}