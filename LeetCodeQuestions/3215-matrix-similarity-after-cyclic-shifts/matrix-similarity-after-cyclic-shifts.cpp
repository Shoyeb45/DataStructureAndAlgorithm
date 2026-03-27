class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        k = k % n;
        vector a = mat;

        // 1 2 3 4
        for (int i = 0; i < mat.size(); i++) {
            vector<int> b = mat[i];
            if (i % 2 == 0) {
                // left shift - pos: (i - k + n) % n
                    for (int j = 0; j < n; j++) {
                        mat[i][j] = b[(j + k) % n];
                    }
            } else {
                // right shift
                for (int j = 0; j < n; j++) {
                    mat[i][j] = b[(j - k + n) % n];
                }
            }
        }
        return a == mat;
    }
};