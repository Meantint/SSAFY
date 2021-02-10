#include <iostream>

using namespace std;

char* itoa(int num)
{
    bool isMinus = false;
    char num_string[100];
    int idx = 0;
    if (num < 0) {
        isMinus = true;
        num *= -1;
    }
    while (num != 0) {
        num_string[idx] = (char)((num % 10) + '0');
        ++idx;
        num /= 10;
    }
    --idx;

    int new_idx = 0;
    char* real_string = new char[100];
    if (isMinus) {
        real_string[new_idx] = '-';
        ++new_idx;
    }
    while (idx >= 0) {
        real_string[new_idx] = num_string[idx];
        ++new_idx;
        --idx;
    }

    return real_string;
}

int main()
{
    int num;
    cin >> num;

    char* string_num = itoa(num);
    cout << string_num << '\n';

    return 0;
}