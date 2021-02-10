#include <iostream>

using namespace std;

int cnt = 0;

struct node {
    int val;
    node* next;

    node(int v)
    {
        val = v;
        next = NULL;
    }
};

node* pq = NULL;

bool isEmpty()
{
    return cnt == 0;
}

void insert(int key)
{
    node* cur;
    node* prev;
    node* tmp = new node(key);

    if (isEmpty()) {
        pq = tmp;
    }
    else {
        prev = NULL;
        cur = pq;
        while (cur) {
            if (cur->val > tmp->val) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (prev == NULL) {
            tmp->next = pq;
            pq = tmp;
        }
        else {
            tmp->next = prev->next;
            prev->next = tmp;
        }
    }
    ++cnt;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        insert(v);
    }

    node* root = pq;
    while (root) {
        cout << root->val;
        if (!root->next) {
            root = root->next;
        }
        else {
            cout << '\n';
            root = root->next;
        }
    }
    cout << '\n';
}