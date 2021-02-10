#include <iostream>

using namespace std;

char binary[4000];
int bin_idx = -1;
int ans[600];
int ans_idx = -1;

int main()
{
    char char_arr[] = "01D06079861D79F99F";
    // char char_arr[] = "0F97A3";

    int idx = -1;
    // 16진수 한자리를 2진수 4자리로 바꿔 binary 배열에 2진수 값으로 저장하는 것을 수행하는 while문
    while (char_arr[++idx] != '\0') {
        int num = -1;
        char cur = char_arr[idx];
        if (cur >= '0' && cur <= '9') {
            num = cur - '0';
        }
        // 알파벳(일단 대문자만 받는다고 가정)
        else {
            num = (cur - 'A') + 10;
        }
        // 16진수 값 하나를 2진수 값 4개로 나눈 것을 저장하는 배열
        int hex_to_bin[4] = {0};
        // while(num != 0) 식으로 진행하면 역순이 나오기 때문에 애초에 인덱스를 뒤에서부터 시작시킴
        int htb_idx = 4;
        while (num != 0) {
            hex_to_bin[--htb_idx] = num % 2;
            num /= 2;
        }
        for (int i = 0; i < 4; ++i) {
            binary[++bin_idx] = (hex_to_bin[i] + '0');
        }
    }

    idx = -1;  // idx 재사용
    int answer = 0;
    // 연습문제 1과 동일
    while (++idx <= bin_idx) {
        answer = (answer << 1) + (binary[idx] - '0');
        if (idx % 7 == 6) {
            ans[++ans_idx] = answer;
            answer = 0;
        }
    }
    // 7자리로 끊기 전에 while문이 종료되었다면 그 값까지 ans에 넣어줘야함
    if (answer != 0) {
        ans[++ans_idx] = answer;
    }
    // 출력
    for (int i = 0; i <= ans_idx; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}