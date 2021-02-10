#include <iostream>

using namespace std;

const int MAX_SIZE = 100000;

struct intStack {
    int stack_size = 0;
    int repository[MAX_SIZE];

    int top()
    {
        if (stack_size == 0) {
            return -1;
        }
        return repository[stack_size - 1];
    }
    void push(int push)
    {
        repository[stack_size++] = push;
    }
    void pop()
    {
        if (stack_size != 0) {
            --stack_size;
        }
    }
};

int main()
{
    intStack st;

    cout << st.top() << '\n';
    st.push(1);
    cout << st.top() << '\n';
    st.push(2);
    st.push(3);
    cout << st.top() << '\n';
    st.pop();
    cout << st.top() << '\n';

    return 0;
}