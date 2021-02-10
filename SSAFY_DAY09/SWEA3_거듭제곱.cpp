#include <iostream>

using namespace std;

int solve(int target_num, int cnt)
{
    if (cnt == 1) {
        return target_num;
    }
    else {
        return target_num * solve(target_num, cnt - 1);
    }
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        int test_case;
        cin >> test_case;

        int n, m;
        cin >> n >> m;

        cout << '#' << test_case << ' ' << solve(n, m) << '\n';
    }
}