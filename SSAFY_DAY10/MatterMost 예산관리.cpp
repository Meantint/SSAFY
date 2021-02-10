#include <iostream>

using namespace std;

int answer = 0;
int* money;
int B, len;

void solve(int start, int cur)
{
    // cout << start << ", " << cur << '\n';
    if (cur > B) {
        return;
    }
    if (answer < cur) {
        answer = cur;
    }
    for (int i = start; i < len; ++i) {
        solve(i + 1, cur + money[i]);
    }
}

int main()
{
    cin >> B >> len;

    money = new int[len];
    for (int i = 0; i < len; ++i) {
        cin >> money[i];
    }

    solve(0, 0);
    cout << answer << '\n';

    return 0;
}