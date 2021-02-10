#include <iostream>

using namespace std;

int real_target_size;

int strlen(const char* ch_array)
{
    int idx = 0;
    while (ch_array[idx] != '\0') {
        ++idx;
    }

    return idx;
}

void strcpy(char target[], const char ip[])
{
    int target_size, input_size;
    for (target_size = 0; target[target_size]; ++target_size) {
    }
    for (input_size = 0; ip[input_size]; ++input_size) {
    }

    int total_size = target_size + input_size;
    if (real_target_size < total_size) {
        cout << "Error, 범위 초과" << '\n';

        return;
    }
    int idx = 0;
    for (idx = 0; target[idx]; ++idx) {
    }
    for (int i = 0; i < input_size; ++i) {
        target[idx + i] = ip[i];
    }
    target[total_size] = '\0';

    return;
}

int main()
{
    char ch1[10000];
    char ch2[10000];
    cin >> ch1;
    cin >> ch2;

    real_target_size = sizeof(ch1) / sizeof(ch1[0]);
    strcpy(ch1, ch2);

    cout << ch1 << '\n';

    return 0;
}