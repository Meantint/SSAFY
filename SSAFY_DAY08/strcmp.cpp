#include <iostream>

using namespace std;

// 왼쪽 문자가 사전순으로 앞서면 -1, 같으면 0, 오른쪽 문자가 사전순으로 앞서면 1 리턴
int strcmp(const char* ch1, const char* ch2)
{
    int idx = 0;
    while (ch1[idx] != '\0' && ch2[idx] != '\0') {
        // idx 위치의 문자가 같다면 계속 탐색
        if (ch1[idx] == ch2[idx]) {
            ++idx;
            continue;
        }
        // 왼쪽 문자가 사전순으로 앞서면
        if (ch1[idx] < ch2[idx]) {
            return -1;
        }
        // 오른쪽 문자가 사전순으로 앞서면
        else {
            return 1;
        }
    }
    // while을 나오기전에 다른게 있다면 함수가 종료되기 때문에
    // 여기까지 온 것은 무조건 길이가 다른 경우
    // 만약 ch2의 길이가 더 길다면 ch1이 사전순으로 앞선다.
    if (ch1[idx] == '\0') {
        return -1;
    }
    // 만약 ch1의 길이가 더 길다면 ch2가 사전순으로 앞선다.
    else if (ch2[idx] == '\0') {
        return 1;
    }
    // 두 문자열의 길이가 같다면 같은 문자이므로 0 리턴
    return 0;
}

int main()
{
    char str1[100000];
    char str2[100000];
    cin >> str1;
    cin >> str2;

    int result_value = strcmp(str1, str2);
    if (result_value < 0) {
        cout << "다른 문자(먼저 입력한 문자(" << str1 << ")가 사전순으로 앞섬)" << '\n';
    }
    else if (result_value == 0) {
        cout << "같은 문자" << '\n';
    }
    // result_value > 0
    else {
        cout << "다른 문자(나중에 입력한 문자(" << str2 << ")가 사전순으로 앞섬)" << '\n';
    }

    return 0;
}