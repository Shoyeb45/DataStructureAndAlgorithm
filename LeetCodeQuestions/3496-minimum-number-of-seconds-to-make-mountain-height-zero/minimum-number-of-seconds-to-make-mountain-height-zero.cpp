using ll = long long;

class Solution {
public:
    int getHeight(ll rem) {
        return (int)((-1 + sqrt(1 + 4 * rem)) / 2);
    }

    bool f(ll time, int mh, vector<int> &wt) {
        int ans = 0;
        for(auto x: wt) {
            ll rem = (2 * time) / x;
            int tempHeight = getHeight(rem);
            ans += tempHeight;
            if(ans >= mh) {
                return true;
            }
        }
        return ans >= mh;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low = 0, high = 1e18;
        ll ans = high;
        // while(f(ans, mountainHeight, workerTimes) == false) {
        //     ans *= 2;
        // }

        while(low <= high) {
            ll mid = low + (high - low) / 2;

            if(f(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};