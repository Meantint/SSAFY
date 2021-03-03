#include <iostream>

using namespace std;

int tc;
int dp[13];
int ticket[4];
int month[13];

// dp[i] : i까지의 최소값
void myDFS(int cur)
{
    if (cur > 12) {
        return;
    }

    if (month[cur] == 0) {
        dp[cur] = dp[cur - 1];
        myDFS(cur + 1);
    }
    else {
        int case1 = month[cur] * ticket[0];
        int case2 = ticket[1];

        int val1;
        if (case1 < case2) {
            val1 = case1 + dp[cur - 1];
        }
        else {
            val1 = case2 + dp[cur - 1];
        }

        int val2 = 2112345678;
        if (cur - 3 >= 0) {
            val2 = dp[cur - 3] + ticket[2];
        }
        if (val1 < val2) {
            dp[cur] = val1;
        }
        else {
            dp[cur] = val2;
        }

        myDFS(cur + 1);
    }
}

void solve()
{
    month[0] = 0;
    myDFS(1);

    if (dp[12] > ticket[3]) {
        dp[12] = ticket[3];
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        for (int i = 0; i <= 12; ++i) {
            dp[i] = 0;
        }
        for (int i = 0; i < 4; ++i) {
            cin >> ticket[i];
        }
        for (int i = 1; i <= 12; ++i) {
            cin >> month[i];
        }

        solve();

        cout << '#' << t << ' ' << dp[12] << '\n';
    }

    return 0;
}