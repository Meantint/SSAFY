#include <iostream>

using namespace std;

char targetText[10000];
char findText[100];
int fSize, tSize;

// 같은 문자열이라면 그 문자열의 첫번째 인덱스를 반환한다.
int myKMP(int pi[])
{
    int fIdx = 0, tIdx = 0;

    while (tIdx < tSize) {
        cout << "tIdx : " << tIdx << ", fIdx : " << fIdx << '\n';

        if (findText[fIdx] == targetText[tIdx]) {
            ++fIdx;
            ++tIdx;

            if (fIdx == fSize) {
                return tIdx - fIdx;
            }
        }
        else {
            tIdx = (tIdx - fIdx) + (fIdx - pi[fIdx]);
            fIdx = 0;
        }
    }

    return -1;
}

int* myPi()
{
    int* pi = new int[fSize];
    pi[0] = -1;
    pi[1] = 0;

    int left, right;
    left = 0, right = 1;

    while (right < fSize) {
        if (right == fSize - 1) {
            return pi;
        }

        if (findText[left] != findText[right]) {
            if (left != 0 && findText[0] == findText[right]) {
                pi[right + 1] = 1;
                left = 0;
            }
            else {
                pi[right + 1] = 0;
            }
            ++right;
        }
        else {
            pi[right + 1] = pi[right] + 1;
            ++left;
            ++right;
        }
    }
}

int main()
{
    cin >> targetText;
    cin >> findText;
    for (tSize = 0; targetText[tSize] != '\0'; ++tSize) {
    }
    for (fSize = 0; findText[fSize] != '\0'; ++fSize) {
    }

    int* pi = myPi();
    for (int i = 0; i < fSize; ++i) {
        cout << pi[i] << ' ';
    }
    cout << '\n';
    cout << myKMP(pi) << '\n';

    return 0;
}