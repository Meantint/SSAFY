#include <iostream>

using namespace std;

int tc;
int num_cnt[10];
int tSize;
string test_num;
string name[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

void solve(string text)
{
    for (int i = 0; i < 10; ++i) {
        if (text == name[i]) {
            ++num_cnt[i];
            break;
        }
    }
    return;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        // 초기화
        for (int i = 0; i < 10; ++i) {
            num_cnt[i] = 0;
        }

        cin >> test_num >> tSize;
        for (int i = 0; i < tSize; ++i) {
            string s;
            cin >> s;
            solve(s);
        }

        cout << test_num << '\n';
        for (int i = 0; i < 10; ++i) {
            int nSize = num_cnt[i];
            for (int j = 0; j < nSize; ++j) {
                cout << name[i] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}