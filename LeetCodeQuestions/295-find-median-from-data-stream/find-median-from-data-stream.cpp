auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
#pragma GCC optimize("O3")
#pragma GCC target("arch=znver3")

class MedianFinder {
public:
    priority_queue<int> min_heap;
    priority_queue<int, vector<int>, greater<int>> max_heap;
    MedianFinder() {
    }
    
    void addNum(int num) {  
        if (max_heap.empty()) {
            max_heap.push(num);
            return;
        }

        int top = max_heap.top();
        if (num < top) {
            min_heap.push(num);
        }
        else {
            max_heap.push(num);
        }
        balance();
    }
    
    void balance() {
        while (abs((int)(max_heap.size() - min_heap.size())) > 1) {
            if (max_heap.size() > min_heap.size()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    } 


    double findMedian() {
        if (((max_heap.size() + min_heap.size()) & 1) == 1) {
            if (max_heap.size() > min_heap.size()) {
                return (double)max_heap.top();
            } 
            return (double)min_heap.top();
        }    

        return (1.0 * max_heap.top() + 1.0 * min_heap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */