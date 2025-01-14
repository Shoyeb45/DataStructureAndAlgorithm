class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0), ans;

        int common = 0;

        for (int i = 0; i < n; i++) {
            if (freq[A[i]] == 0) {
                freq[A[i]] = 1;
            }
            else {
                common++;
                freq[A[i]]++;
            }
            if (freq[B[i]] == 0) {
                freq[B[i]] = 1;
            }
            else {
                common++;
                freq[B[i]]++;
            }
            ans.push_back(common);
        }
        return ans;
    }
};