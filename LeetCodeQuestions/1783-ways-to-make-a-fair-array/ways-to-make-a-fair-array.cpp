class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        // 1 2 3 4 1 8 3 4 5 
        // 0 1 2 3 4 5 6 7 8
        // 1   4   5   8   13
        //   2   6   14   18   
        // 8 3 4 5 
        int n = nums.size();
        vector<vector<int>> pref_sum(2, vector<int> (n, 0));
        vector<vector<int>> suff_sum(2, vector<int> (n, 0));

        pref_sum[0][0] = nums[0];
        if (n % 2 == 0) {
            suff_sum[1][n - 1] = nums[n - 1];
        }
        else {
            suff_sum[0][n - 1] = nums[n - 1];
        }
        for (int i = 1; i < n; i++) {
            pref_sum[0][i] = pref_sum[0][i - 1];
            pref_sum[1][i] = pref_sum[1][i - 1];
            pref_sum[i % 2][i] += nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            suff_sum[0][i] = suff_sum[0][i + 1];
            suff_sum[1][i] = suff_sum[1][i + 1];
            suff_sum[i % 2][i] += nums[i];
        }


        int ans = 0;
        for (int i = 0; i < n; i++) {
            // cout << "i : " << i << "\n";

            int left_even_sum, left_odd_sum;
            int right_even_sum, right_odd_sum;
            
            if (i % 2 == 0) {
                left_even_sum = pref_sum[0][i] - nums[i];
                left_odd_sum = pref_sum[1][i];
                
                right_even_sum = suff_sum[1][i];
                right_odd_sum = suff_sum[0][i] - nums[i];

            }
            else {
                left_even_sum = pref_sum[0][i];
                left_odd_sum = pref_sum[1][i] - nums[i];

                right_even_sum = suff_sum[1][i] - nums[i];
                right_odd_sum = suff_sum[0][i];
            }

            // cout << "les : " <<  left_even_sum << "\nres : " << right_even_sum << "\nlos: " << left_odd_sum << "\nros: " <<  right_odd_sum << "\n";
            if (left_even_sum + right_even_sum == left_odd_sum + right_odd_sum) {
                ans++;
            }
        }

        return ans;
    }
};