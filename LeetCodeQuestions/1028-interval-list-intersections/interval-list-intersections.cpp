class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& a, 
        vector<vector<int>>& b
    ) {
        vector<vector<int>> ans;

        int i = 0, j = 0;

        auto is_common = [&](vector<int> int1, vector<int> int2) -> bool {
            return !(int1[1] < int2[0] || int2[1] < int1[0]);
        };

        while (i < a.size() && j < b.size()) {

            if (is_common(a[i], b[j])) {
                vector<int> new_int = {
                    max(a[i][0], b[j][0]), 
                    min(a[i][1], b[j][1])
                };
                ans.push_back(new_int);
                a[i][0] = new_int[1] + 1;
                b[j][0] = new_int[1] + 1;

                if (a[i][0] > a[i][1]) {
                    i++;
                }
                if (b[j][0] > b[j][1]) {
                    j++;
                }
            } 
            else if (b[j][0] < a[i][0]) {
                j++;
            }
            else {
                i++;
            }
        }  

        return ans;
    }
};