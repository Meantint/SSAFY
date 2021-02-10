#include <iostream>

using namespace std;

char stack[110];
int top = -1;

char* solve(char text[], int len)
{
    for (int i = 0; i < len; ++i) {
        if (top != -1 && stack[top] == text[i]) {
            --top;
        }
        else {
            stack[++top] = text[i];
        }
    }
    stack[++top] = '\0';

    return stack;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        top = -1;
        int len;
        char text[110];
        cin >> len >> text;

        cout << '#' << t + 1 << ' ' << solve(text, len) << '\n';
    }

    return 0;
}