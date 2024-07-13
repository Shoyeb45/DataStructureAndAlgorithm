#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
#define no_of_stacks 3

class ThreeStacks {
    private: 
        int size_stack;
        vector<int> sizes;
        vector<int> values;

    public:
        ThreeStacks(int size_of_stack) {
            size_stack = size_of_stack;
            values.resize(no_of_stacks * size_stack, 0);
            sizes.resize(3, 0);
        }

    // Push in stack 
    void push(int val, int num_stack) {
        if(isFull(sizes[num_stack])) {
            throw out_of_range("Stack is full.");
        }
        values[top_index(num_stack)] = val;
        sizes[num_stack]++;
    }

    // Pop in stack
    void pop(int num_stack) {
        if(this->isEmpty(num_stack)) {
            throw out_of_range("Stack is empty.");
        }
        sizes[num_stack]--;
    }

    // Get top element of stack
    int top(int num_stack) {
        if(this->isEmpty(num_stack)) {
            throw out_of_range("Stack is empty.");
        }
        return values[top_index(num_stack) - 1];
    }

    // Check if stack is full or not
    bool isFull(int num_stack) {
        if(num_stack < 0 || num_stack > 2) {
            throw out_of_range("Invalid Stack number");
        }
        return sizes[num_stack] == size_stack;
    }

    // Check if stack is empty or not
    bool isEmpty(int num_stack) {
        if(num_stack < 0 || num_stack >= 3) {
            throw out_of_range("Invalid Stack number");
        }
        return sizes[num_stack] == 0;
    }

    private:
    int top_index(int num_stack) {
        if(num_stack < 0 || num_stack >= 3) {
            throw out_of_range("Invalid Stack number");
        }
        return (num_stack * no_of_stacks) + sizes[num_stack];
    }
};
int main() {
    // Creating new object
    ThreeStacks a(3);
    a.push(10, 0);
    a.push(-10, 2);
    a.push(12, 2);
    a.push(1, 1);
    a.push(4, 0);
    a.push(-69, 0);
    cout << "0: " << a.top(0) << '\n';
    a.push(13, 2);
    a.pop(2);
    cout << "2: " << a.top(2) << '\n';
    cout << "1: " << a.top(1) << '\n';
    
    return 0;
}
