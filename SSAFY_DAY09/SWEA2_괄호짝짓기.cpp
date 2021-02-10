#include <iostream>

using namespace std;

char stack[1000];
int top = -1;
char info[128];

int main()
{
    info[')'] = '(';
    info['>'] = '<';
    info['}'] = '{';
    info[']'] = '[';

    for (int t = 0; t < 10; ++t) {
        top = -1;
        bool isValid = true;
        int len;
        cin >> len;

        char* text = new char[len];
        cin >> text;

        for (int i = 0; text[i]; ++i) {
            // 열리는 괄호일 경우
            if (text[i] == '(' || text[i] == '[' || text[i] == '{' || text[i] == '<') {
                stack[++top] = text[i];
            }
            else if (text[i] == ')' || text[i] == ']' || text[i] == '}' || text[i] == '>') {
                if (info[text[i]] == stack[top]) {
                    --top;
                }
                else {
                    isValid = false;
                    break;
                }
            }
            if (top == -2) {
                isValid = false;
                break;
            }
        }

        if (isValid && top == -1) {
            cout << '#' << t + 1 << ' ' << 1 << '\n';
        }
        else {
            cout << '#' << t + 1 << ' ' << 0 << '\n';
        }
    }

    return 0;
}