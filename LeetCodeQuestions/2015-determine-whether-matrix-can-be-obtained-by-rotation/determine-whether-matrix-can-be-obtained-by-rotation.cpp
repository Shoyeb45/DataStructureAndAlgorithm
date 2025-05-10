class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // ith row -> n - i - 1
        int n = mat.size();
        if (mat == target) {
            return true;
        }
        auto rotateMatrix = [&](vector<vector<int>> &mat) -> void {
            vector<vector<int>> n_mat(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    n_mat[j][n - i - 1] = mat[i][j];
                }
            }
            mat = n_mat;
        };

        for (int i = 0; i < 3; i++) {
            rotateMatrix(mat);

            if (mat == target) {
                return true;
            }
        }

        // 0 0 
        // 1 0

        // 0 0  0 0    
        // 0 1  1 0
        return false;
    }
};