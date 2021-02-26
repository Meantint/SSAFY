#include <iostream>

using namespace std;

char text[] = "abcabdabcabca";
char pattern[] = "abca";
int tSize, pSize;
int target_hash = 0;
int hash_num = 0;

// 찾은 문자열의 시작 인덱스를 출력하는 함수
void myHash()
{
    if (hash_num == target_hash) {
        cout << "Start idx : " << 0 << '\n';
    }
    int cur = 1;
    while (cur + pSize <= tSize) {
        // cout << "hash num : " << hash_num << '\n';
        int tmp = text[cur - 1];
        for (int i = 0; i < pSize; ++i) {
            tmp *= 2;
        }
        hash_num = hash_num * 2 - tmp + text[cur + pSize - 1];
        if (hash_num == target_hash) {
            cout << "Start idx : " << cur << '\n';
        }
        ++cur;
    }
}

int main()
{
    for (tSize = 0; text[tSize] != '\0'; ++tSize) {
    }
    for (pSize = 0; pattern[pSize] != '\0'; ++pSize) {
        target_hash *= 2;
        target_hash += pattern[pSize];
    }
    // 초기 설정
    for (int i = 0; i < pSize; ++i) {
        hash_num *= 2;
        hash_num += text[i];
    }

    myHash();

    return 0;
}