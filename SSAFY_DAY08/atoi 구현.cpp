#include <iostream>

using namespace std;

int atoi(char* str, bool isHex)
{
    int real_num = 0;

    int size = 0;
    while (str[size]) {
        ++size;
    }
    int div = 10;
    if (isHex) {
        div = 16;
    }
    for (int i = 0; i < size; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            real_num = (real_num * div) + (str[i] - '0');
        }
        else if (str[i] >= 'A' && str[i] <= 'F') {
            real_num = (real_num * div) + (str[i] - 'A') + 10;
        }
        else if (str[i] >= 'a' && str[i] <= 'f') {
            real_num = (real_num * div) + (str[i] - 'a') + 10;
        }
    }
    if (str[0] == '-') {
        real_num *= -1;
    }

    return real_num;
}

int main()
{
    char str[100];
    cin >> str;

    int isHex = 0;
    cout << "16진수 숫자라면 1을, 아니면 0을 입력해주세요 : ";
    cin >> isHex;
    int num_string = atoi(str, isHex);
    cout << num_string << '\n';

    return 0;
}