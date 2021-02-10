#include <iostream>

using namespace std;

int ans_idx = -1;
int ans[10];

int main()
{
    char x[] = "0000000111100000011000000111100110000110000111100111100111111001100111";

    int idx = -1;
    int answer = 0;
    while (x[++idx] != '\0') {
        answer = (answer << 1) + (x[idx] - '0');
        if (idx % 7 == 6) {
            ans[++ans_idx] = answer;
            answer = 0;
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}