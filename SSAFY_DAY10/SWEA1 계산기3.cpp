#include <iostream>

using namespace std;

char stack[1000];
int top = -1;
char postfix[1000];
int idx = -1;
int cal[1000];
int cal_idx = -1;

int cal_postfix(char text[], int len)
{
    for (int i = 0; i < len; ++i) {
        char cur = text[i];
        // 피연산자
        if (cur >= '0' && cur <= '9') {
            cal[++cal_idx] = cur - '0';
        }
        // 연산자
        else {
            int n1 = cal[cal_idx--];
            int n2 = cal[cal_idx--];

            if (cur == '+') {
                cal[++cal_idx] = n1 + n2;
            }
            else if (cur == '*') {
                cal[++cal_idx] = n1 * n2;
            }
        }
    }

    return cal[0];
}

int solve(char text[], int len)
{
    for (int i = 0; i < len; ++i) {
        char cur = text[i];
        if (cur >= '0' && cur <= '9') {
            postfix[++idx] = cur;
        }
        else if (cur == '(') {
            stack[++top] = '(';
        }
        else if (cur == '+') {
            if (top == -1) {
                stack[++top] = cur;
            }
            while (top != -1 && (stack[top] == '+' || stack[top] == '*')) {
                postfix[++idx] = stack[top--];
            }
            stack[++top] = cur;
        }
        else if (cur == '*') {
            if (top == -1) {
                stack[++top] = cur;
            }
            while (top != -1 && stack[top] == '*') {
                postfix[++idx] = stack[top--];
            }
            stack[++top] = cur;
        }
        else if (cur == ')') {
            while (stack[top] != '(') {
                postfix[++idx] = stack[top--];
            }
            --top;
        }
    }

    return cal_postfix(postfix, idx + 1);
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        idx = -1;
        top = -1;
        cal_idx = -1;
        int len;
        char text[1000];
        cin >> len >> text;

        cout << '#' << t + 1 << ' ' << solve(text, len) << '\n';
    }

    return 0;
}