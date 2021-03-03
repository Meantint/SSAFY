#include <iostream>

using namespace std;

int tc, n;
int compPos[2];
int homePos[2];
int** otherPos;

int dp[(1 << 10)][10];

int calDist(int prev[], int cur[])
{
    int xDist = prev[0] - cur[0];
    int yDist = prev[1] - cur[1];
    if (xDist < 0) {
        xDist *= -1;
    }
    if (yDist < 0) {
        yDist *= -1;
    }

    return xDist + yDist;
}

void myDFS(int prev, int cur, int info)
{
    // 이미 방문한 곳이라면
    if ((info & (1 << cur)) != 0) {
        return;
    }
    int new_info = (info | (1 << cur));
    // 이전 지점이 회사인 경우
    if (prev == -1) {
        int tmp = calDist(compPos, otherPos[cur]);
        if (dp[new_info][cur] > tmp) {
            dp[new_info][cur] = tmp;
        }
    }
    // 회사가 아닌 경우
    else {
        int tmp = calDist(otherPos[prev], otherPos[cur]);
        if (dp[new_info][cur] > dp[info][prev] + tmp) {
            dp[new_info][cur] = dp[info][prev] + tmp;
        }
    }
    prev = cur;

    // 모두 방문했다면
    if (new_info == (1 << n) - 1) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        myDFS(prev, i, new_info);
    }
}

void solve(int test)
{
    for (int i = 0; i < n; ++i) {
        myDFS(-1, i, 0);
    }
    // for (int j = 0; j < n; ++j) {
    //     cout << dp[(1 << n) - 1][j] << ' ';
    // }
    // cout << '\n';

    int res = 2112345678;
    for (int i = 0; i < n; ++i) {
        int tmp = dp[(1 << n) - 1][i] + calDist(otherPos[i], homePos);
        if (res > tmp) {
            res = tmp;
        }
    }
    cout << '#' << test << ' ' << res << '\n';
    // cout << '\n';
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        // input & 초기화
        cin >> n;
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 2112345678;
            }
        }
        cin >> compPos[0] >> compPos[1] >> homePos[0] >> homePos[1];
        otherPos = new int*[n];
        for (int i = 0; i < n; ++i) {
            otherPos[i] = new int[2];
            cin >> otherPos[i][0] >> otherPos[i][1];
        }

        solve(t);
    }

    return 0;
}