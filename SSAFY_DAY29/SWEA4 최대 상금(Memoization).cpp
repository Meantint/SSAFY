#include <iostream>

using namespace std;

int tc;
int target, count;
int nSize;  // 몇 자리 수
char charNum[6];
bool memo[1000000][10];

void mySwap(char& n1, char& n2)
{
    char tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void myDFS(char text[], int c)
{
    // cout << text << '\n';
    int curNum = 0;
    for (int i = 0; i < nSize; ++i) {
        curNum *= 10;
        curNum += (text[i] - '0');
    }
    if (memo[curNum][c]) {
        return;
    }
    // 교환 횟수가 zero
    if (c == 0) {
        memo[curNum][0] = true;
        return;
    }
    int cp_c = c;
    for (; cp_c >= 0; cp_c -= 2) {
        // 이미 방문한 적 있다면 리턴
        if (memo[curNum][cp_c]) {
            return;
        }
        // 이미 방문한 적 없다면 2칸 간격 아래로 모두 true로 바꿈(2번으로 무조건 그 숫자를 만들 수 있기 때문에)
        else {
            memo[curNum][cp_c] = true;
        }
    }
    for (int i = 0; i < nSize; ++i) {
        for (int j = i + 1; j < nSize; ++j) {
            mySwap(text[i], text[j]);
            myDFS(text, c - 1);
            mySwap(text[i], text[j]);
        }
    }
}

void solve()
{
    myDFS(charNum, count);

    return;
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        for (int i = 0; i < 1000000; ++i) {
            for (int j = 0; j < 10; ++j) {
                memo[i][j] = false;
            }
        }
        nSize = 0;
        cin >> charNum >> count;
        while (charNum[nSize] != 0) {
            ++nSize;
        }

        solve();

        cout << '#' << t << ' ';
        for (int i = 999999; i >= 0; --i) {
            if (memo[i][0]) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}