// 헷갈림, 한번더보기
#include <iostream>

using namespace std;

struct node {
    double d = -1;
    char ch;
    int left;
    int right;

    node()
    {
        left = -1;
        right = -1;
    }
};

node* root[1000];

double cal(int cur)
{
    // 연산자
    if (root[cur]->left != -1) {
        char op = root[cur]->ch;
        if (op == '-') {
            return cal(root[cur]->left) - cal(root[cur]->right);
        }
        else if (op == '+') {
            return cal(root[cur]->left) + cal(root[cur]->right);
        }
        else if (op == '*') {
            return cal(root[cur]->left) * cal(root[cur]->right);
        }
        else {
            return cal(root[cur]->left) / cal(root[cur]->right);
        }
    }
    // 숫자
    else {
        // cout << "cur : " << cur << ", " << root[cur]->d << '\n';
        return root[cur]->d;
    }
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        int n, num, l, r;
        char word[10];
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> num >> word;
            // cout << "word : " << word << '\n';
            // 숫자인 경우
            if (word[0] >= '0' && word[0] <= '9') {
                int new_num = 0;
                int idx = -1;
                while (word[++idx] != '\0') {
                    new_num = new_num * 10 + (word[idx] - '0');
                }
                root[num] = new node();
                root[num]->d = new_num;
                // cout << "root[num]->d : " << root[num]->d << '\n';
            }
            // 연산자인 경우
            else {
                cin >> l >> r;
                root[num] = new node();
                root[num]->ch = word[0];
                root[l] = new node();
                root[r] = new node();
                root[num]->left = l;
                root[num]->right = r;
            }
        }
        // cout << "root[1]->d = " << root[1]->d << '\n';
        cout << '#' << t + 1 << ' ' << (int)cal(1) << '\n';
    }

    return 0;
}