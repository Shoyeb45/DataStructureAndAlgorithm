class Solution {
public:
    vector<int> get_divisors(int x) {
        vector<int> a;
        a.push_back(1);

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                a.push_back(i);
                if (i != x / i) {
                    a.push_back(x / i);
                }
            }
        }
        a.push_back(x);
        return a;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (auto& x: nums) {
            auto div = get_divisors(x);
            // cout << x << " : \n"; 
            // for (auto y: div) {
            //     cout << y << " ";
            // }
            // cout << "\n";
            if (div.size() == 4) {
                ans += accumulate(div.begin(), div.end(), 0);
            }
        }    
        return ans;
    }
};