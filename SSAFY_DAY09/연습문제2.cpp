#include <iostream>

using namespace std;

char stack[1000];
int top = -1;
char text[100];

int main()
{
    char info[128];
    info[')'] = '(';
    info['>'] = '<';
    info['}'] = '{';
    info[']'] = '[';

    cin >> text;

    bool isValid = true;
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

    if (isValid) {
        cout << "이 괄호문자열은 유효합니다." << '\n';
    }
    else {
        cout << "이 괄호문자열은 유효하지 않습니다" << '\n';
    }

    return 0;
}