#include <iostream>

using namespace std;

struct TreeNode {
    int node_num = 0;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int node)
    {
        node_num = node;
        leftChild = NULL;
        rightChild = NULL;
    }

    TreeNode* find(int target)
    {
        // cout << "this->node_num : " << this->node_num << '\n';
        if (this->node_num == target) {
            // cout << "find " << target << '\n';
            return this;
        }
        // 25 ~ 37 라인을 if else-if else로 만들었을 때와
        // 각각의 if로 나눴을 때의 차이점을 모르겠음(if else-if else는 에러남)
        if (this->leftChild != NULL) {
            TreeNode* t = this->leftChild->find(target);
            if (t != NULL) {
                return t;
            }
        }
        if (this->rightChild != NULL) {
            TreeNode* t = this->rightChild->find(target);
            if (t != NULL) {
                return t;
            }
        }
        return NULL;
    }

    void insert(TreeNode* cur, int val)
    {
        TreeNode* tmp = new TreeNode(val);
        if (cur->leftChild == NULL) {
            cur->leftChild = tmp;
        }
        else {
            cur->rightChild = tmp;
        }

        return;
    }

    // 전위 순회
    void preorder()
    {
        cout << this->node_num << ' ';
        if (this->leftChild != NULL) {
            this->leftChild->preorder();
        }
        if (this->rightChild != NULL) {
            this->rightChild->preorder();
        }
    }
    // 중위 순회
    void inorder()
    {
        if (this->leftChild != NULL) {
            this->leftChild->inorder();
        }
        cout << this->node_num << ' ';
        if (this->rightChild != NULL) {
            this->rightChild->inorder();
        }
    }
    // 후위 순회
    void postorder()
    {
        if (this->leftChild != NULL) {
            this->leftChild->postorder();
        }
        if (this->rightChild != NULL) {
            this->rightChild->postorder();
        }
        cout << this->node_num << ' ';
    }
    // 레벨 순회
    void levelorder()
    {
        int front = -1, rear = -1;
        TreeNode* tree_queue[1000];

        tree_queue[++rear] = this;
        while (front != rear) {
            int cp_rear = rear;
            while (front != cp_rear) {
                TreeNode* cur = tree_queue[++front];
                cout << cur->node_num << ' ';
                if (cur->leftChild != NULL) {
                    tree_queue[++rear] = cur->leftChild;
                }
                if (cur->rightChild != NULL) {
                    tree_queue[++rear] = cur->rightChild;
                }
            }
        }

        return;
    }
};

int main()
{
    // 실험
    // TreeNode* root = new TreeNode(1);
    // root->insert(root->find(1), 3);

    // cout << root->node_num << ", " << root->leftChild->node_num << '\n';
    TreeNode* root = new TreeNode(1);
    int v;
    cout << "정점의 개수를 입력하세요(root 노드는 1이라고 가정) : ";
    cin >> v;

    for (int i = 1; i < v; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        root->insert(root->find(v1), v2);
        // cout << "done\n";
    }

    cout << "\n\n";
    cout << "Preorder" << '\n';
    root->preorder();
    cout << '\n';
    cout << "Inorder" << '\n';
    root->inorder();
    cout << '\n';
    cout << "Postorder" << '\n';
    root->postorder();
    cout << '\n';
    cout << "Levelorder" << '\n';
    root->levelorder();
    cout << '\n';

    return 0;
}