#include <iostream>

using namespace std;

int strlen(const char* ch_array)
{
    int idx = 0;
    while (ch_array[idx] != '\0') {
        ++idx;
    }

    return idx;
}

int main()
{
    char ch_array[100000];
    cin >> ch_array;

    cout << "입력한 문자의 길이는 " << strlen(ch_array) << " 입니다." << '\n';
}