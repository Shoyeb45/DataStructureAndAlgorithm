class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int k = 0;
        int j = n - 1;
        for (int i = 0; i < j; i++) {
            if (nums[i] == val) {
                // k++;
                while (j != i && nums[j] == val) {
                    j--;
                    // k++;
                }
                swap(nums[i], nums[j]);
                // j--;
            }
        } 
        for (int i = 0; i < n; i++)
            k += (nums[i] == val);
            // cout << nums[i] << " ";
        cout << "\n" << k << "\n";
        return n - k;
    }
};