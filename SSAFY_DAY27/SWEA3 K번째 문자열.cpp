#include <algorithm>
#include <iostream>

using namespace std;

int k, tc;
char text[410];
int tSize;

bool comp(int n1, int n2)
{
    while (n1 < tSize && n2 < tSize) {
        if (text[n1] < text[n2]) {
            return true;
        }
        else if (text[n1] == text[n2]) {
            ++n1;
            ++n2;
        }
        else {
            return false;
        }
    }
    if (n1 <= n2) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> k >> text;

        for (tSize = 0; text[tSize] != '\0'; ++tSize) {
        }

        int suffix[410];
        for (int i = 0; i < tSize; ++i) {
            suffix[i] = i;
        }
        int lcp[410] = {0};

        sort(suffix, suffix + tSize, comp);

        for (int i = 1; i < tSize; ++i) {
            int l = suffix[i - 1];
            int r = suffix[i];
            while (l < tSize && r < tSize) {
                if (text[l] == text[r]) {
                    ++lcp[i];
                    ++l;
                    ++r;
                }
                else {
                    break;
                }
            }
        }

        int cnt = 0;
        char res[410];
        for (int i = 0; i < tSize; ++i) {
            int make_cnt = tSize - suffix[i] - lcp[i];
            cnt += make_cnt;

            // 범위 안에 들었다면
            if (k <= cnt) {
                cnt -= make_cnt;
                int sub_cnt = k - cnt + lcp[i];
                for (int j = 0; j < sub_cnt; ++j) {
                    res[j] = text[suffix[i] + j];
                }
                res[sub_cnt] = '\0';

                break;
            }
        }
        cout << '#' << t << ' ';

        if (res[0] != '\0') {
            cout << res << '\n';
        }
        else {
            cout << "none" << '\n';
        }
    }

    return 0;
}