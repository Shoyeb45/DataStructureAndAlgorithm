class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& c) {
        sort(c.rbegin(), c.rend());

        long long sum = accumulate(apple.begin(), apple.end(), 0LL);

        long long req = 0;
        for (int i = 0; i < c.size(); i++) {
            req += c[i];
            if (req >= sum) 
                return i + 1;
        } 
        
        return c.size(); 
    }
};