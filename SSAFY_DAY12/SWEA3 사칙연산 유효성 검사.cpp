#include <iostream>

using namespace std;

struct node {
    int d = -1;
    char ch;
    int left;
    int right;

    node()
    {
        left = -1;
        right = -1;
    }
};

int n;
node* root[1000];

bool isGood(int cur)
{
    // cout << "cur : " << cur << ", " << "root[cur]->d : " << root[cur]->d << '\n';
    int is_num = root[cur]->d;
    // 연산자
    if (is_num == -1) {
        // 연산자인데 단말 노드가 아니라면 재귀로 찾아봐야함(왼쪽 오른쪽 둘 다 있어야함)
        if (root[cur]->left != -1 && root[cur]->right != -1) {
            return (isGood(cur * 2) && isGood(cur * 2 + 1));
        }
        // 연산자인데 단말 노드이면 false임
        else {
            return false;
        }
    }
    // 숫자
    else {
        // 숫자인데 단말 노드라면
        if (root[cur]->left == -1 && root[cur]->right == -1) {
            return true;
        }
        // 숫자인데 단말 노드 아니라면 false
        else {
            return false;
        }
    }
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        int num, l, r;
        char word[10];
        cin >> n;
        // cout << n << '\n';

        for (int i = 0; i < n; ++i) {
            cin >> num >> word;
            // cout << "num : " << num << ", " << "word : " << word << '\n';
            // 숫자
            if (word[0] >= '0' && word[0] <= '9') {
                int new_num = 0;
                int idx = -1;
                while (word[++idx] != '\0') {
                    new_num = new_num * 10 + (word[idx] - '0');
                }
                root[num] = new node();
                root[num]->d = new_num;
            }
            // 연산자
            else {
                root[num] = new node();
                root[num]->ch = word[0];
            }

            if (n >= num * 2) {
                cin >> l;
                root[num]->left = l;
            }
            if (n > num * 2) {
                cin >> r;
                root[num]->right = r;
            }
        }
        cout << '#' << t + 1 << ' ' << isGood(1) << '\n';
    }

    return 0;
}