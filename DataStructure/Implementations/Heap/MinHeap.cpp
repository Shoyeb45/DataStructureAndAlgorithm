#include<bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> data;
    MinHeap() { }

    bool empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }

    void push(int val) {
        data.push_back(val);
        int idx = data.size() - 1;

        while(idx >= 0 && idx < data.size() && data[idx] < data[parent(idx)]) {
            swap(data[idx], data[parent(idx)]);
            idx = parent(idx);
        }
    }
    int front() {
        if(data.empty()) {
            throw underflow_error("No element is present");
        }
        return data[0];
    }

    int pop() {
        if(data.empty()) {
            throw underflow_error("No element is present");
        }
        int root = data[0];
        data[0] = data.back();
        data.pop_back();

        int idx = 0;
        int curr = data[0];
        while(true) {
            int curr = data[idx], left, right;
            left = (leftChild(idx) < data.size()) ? data[leftChild(idx)]: INT_MAX;
            right = (rightChild(idx) < data.size()) ? data[rightChild(idx)]: INT_MAX;

            if(curr <= left && curr <= right) {
                return root;
            }

            if(left < curr && left < right) {
                swap(data[idx], data[leftChild(idx)]);
                idx = leftChild(idx);
                continue;
            }

            if(right < curr && right < left) {
                swap(data[idx], data[rightChild(idx)]);
                idx = rightChild(idx);
                continue;
            }
        }
    }
    void display() {
        for(auto x: data) {
            cout << x << " ";
        }
        cout << endl;
    }
private:
    int leftChild(int idx) {
        return 2 * idx + 1;
    }

    int rightChild(int idx) {
        return 2 * idx + 2;
    }

    int parent(int idx) {
        return (idx - 1) / 2;
    }
};

int main() {
    MinHeap mn;
    mn.push(2);
    mn.push(10);
    mn.push(34);
    mn.push(8);
    mn.push(5);
    mn.push(1);
    mn.display();

    mn.pop();
    mn.display();
    return 0;
}
