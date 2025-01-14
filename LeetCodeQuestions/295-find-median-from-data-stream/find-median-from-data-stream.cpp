auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
#pragma GCC optimize("O3")
#pragma GCC target("arch=znver3")

class MedianFinder {
public:
    multiset<int> m_set;
    multiset<int>::iterator mid;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if (m_set.empty()) {
            m_set.insert(num);
            mid = m_set.begin();
            return;
        }
        m_set.insert(num);

        if (m_set.size() % 2 == 0) {
            if (num < *mid) {
                mid--;
            }
        }
        else {  
            if (num >= *mid) {
                mid++;
            }
        }
    }
    
    double findMedian() {
        if ((m_set.size() & 1) == 1) {
            return (double)*mid;
        }
        double a1 = *mid;
        auto temp = mid;
        temp++;
        double a2 = *temp;
        return (a1 + a2) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */