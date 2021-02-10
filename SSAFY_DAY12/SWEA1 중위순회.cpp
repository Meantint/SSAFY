#include <iostream>

using namespace std;

int n, num, l, r;
char* root;
char ch;

void inorder(int cur)
{
    if (cur * 2 <= n) {
        inorder(cur * 2);
    }
    cout << root[cur];
    if (cur * 2 + 1 <= n) {
        inorder(cur * 2 + 1);
    }
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        cin >> n;
        root = new char[n + 1];

        for (int i = 0; i < n; ++i) {
            l = r = -1;
            cin >> num >> ch;
            root[num] = ch;

            if (n >= num * 2) {
                cin >> l;
            }
            if (n > num * 2) {
                cin >> r;
            }
        }
        cout << '#' << t + 1 << ' ';
        inorder(1);
        cout << '\n';
    }

    return 0;
}