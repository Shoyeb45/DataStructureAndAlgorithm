class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;

        vector<int> neg;

        bool is_zero = false;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    is_zero = true;
                    sum += matrix[i][j];
                } else {
                    if (matrix[i][j] < 0) 
                        cnt++;
                    
                    neg.push_back(matrix[i][j] < 0 ? -matrix[i][j] : matrix[i][j]);
                }
            }
        }


        if (is_zero) {
            for (auto x: neg) sum += x;
            return sum;
        }

        sort(neg.rbegin(), neg.rend());

        int k = neg.size() - cnt % 2;
        for (int i = 0; i < k; i++) 
            sum += neg[i];

        for (int i = k; i < neg.size(); i++) 
            sum -= neg[i];

        return sum;
    }
};