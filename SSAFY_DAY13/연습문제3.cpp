#include <iostream>

using namespace std;

int ans_idx = -1;
int ans[1000];
int pattern[10] = {13, 19, 59, 49, 35, 55, 11, 61, 25, 47};
char bin[4];

void make_bin(char c)
{
    // 숫자 변환
    int num;
    if (c >= '0' && c <= '9') {
        num = c - '0';
    }
    else {
        num = c - 'A' + 10;
    }

    int idx = 4;
    while (idx--) {
        bin[idx] = (num % 2) + '0';
        num /= 2;
    }

    return;
}

int getNum(char* htb, int st)
{
    int num = 0;
    for (int i = 0; i < 6; ++i) {
        num = (num << 1) + htb[st + i] - '0';
    }
    for (int i = 0; i < 10; ++i) {
        if (pattern[i] == num) {
            return i;
        }
    }

    return -1;
}

int main()
{
    char text[] = "0269FAC9A0";
    // char text[] = "0DEC";

    int size = -1;
    while (text[++size] != '\0') {
    }

    char* hex_to_bin = new char[(size + 1) * 4];
    int htb_idx = -1;

    for (int i = 0; i < size; ++i) {
        make_bin(text[i]);
        for (int j = 0; j < 4; ++j) {
            hex_to_bin[++htb_idx] = bin[j];
        }
    }
    ++htb_idx;
    for (int i = 0; i < htb_idx; ++i) {
        cout << hex_to_bin[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < htb_idx; ++i) {
        if (i + 5 < htb_idx && getNum(hex_to_bin, i) != -1) {
            while (i + 5 < htb_idx) {
                ans[++ans_idx] = getNum(hex_to_bin, i);
                i += 6;
            }
        }
    }
    for (int i = 0; i < ans_idx; ++i) {
        cout << ans[i] << ", ";
    }
    cout << ans[ans_idx] << '\n';

    return 0;
}