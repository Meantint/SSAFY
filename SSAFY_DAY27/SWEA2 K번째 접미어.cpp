#include <iostream>

using namespace std;

int tc, k;
int tSize;
int indirect[401];
char text[401];

bool mySort(int real_i, int real_j)
{
    while (real_i < tSize && real_j < tSize) {
        // 바꿀 필요 없음
        if (text[real_i] < text[real_j]) {
            return false;
        }
        // 바꿀 필요 있음
        else if (text[real_i] > text[real_j]) {
            return true;
        }
        // 같은 경우
        else {
            ++real_i;
            ++real_j;
        }
    }
    // while문 안에서 안 끝난 경우 다시 한 번 더 체크
    if (real_i > real_j) {
        return true;
    }
    else {
        return false;
    }
}

void solve()
{
    for (int i = 0; i < tSize; ++i) {
        for (int j = i + 1; j < tSize; ++j) {
            if (mySort(indirect[i], indirect[j])) {
                int tmp = indirect[i];
                indirect[i] = indirect[j];
                indirect[j] = tmp;
            }
        }
    }
    int start = indirect[k];
    for (int i = start; i < tSize - 1; ++i) {
        cout << text[i];
    }
    cout << '\n';

    return;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        // 초기화
        for (int i = 0; i < 401; ++i) {
            indirect[i] = i;
        }
        // 입력
        cin >> k >> text;
        for (tSize = 0; text[tSize] != '\0'; ++tSize) {
        }
        text[tSize] = '$';
        tSize += 1;

        int* suffix = new int[tSize];
        for (int i = 0; i < tSize; ++i) {
            suffix[i] = i;
        }

        cout << '#' << t + 1 << ' ';
        solve();
    }

    return 0;
}