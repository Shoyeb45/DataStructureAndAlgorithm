class Solution {
public:
    int countTrapezoids(vector<vector<int>>& p) {
        int n = p.size();
        // count number of squares then rhombus, then rectangle, then isoceles trapeziod, then right trepezoid
        
        map<int, map<int, int>> mp_nc, mp_c;
        // mp_nc -> non collinear
        // mp_c -> collinear

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = p[j][0] - p[i][0], dy = p[j][1] - p[i][1];

                if (dx < 0 || (dx == 0 && dy < 0)) 
                    dx = -dx, dy = -dy;
                
                int g = gcd(dx, abs(dy));

                int n_x = dx / g;
                int n_y = dy / g;

                int constant = n_x * p[i][1] - n_y * p[i][0];

                // this encodes our normalised slopes
                int key1 = (n_x << 12) | (n_y + 2000);
                // this encodes slopes
                int key2 = (dx << 12) | (dy + 2000);

                mp_nc[key1][constant]++;
                mp_c[key2][constant]++;
            }
        }

        return count(mp_nc) - count(mp_c) / 2; 
    }

    int count(map<int, map<int, int>> &mp) {
        int ans = 0;

        for (auto& [_, mp_in]: mp) {
            int sum = 0;
            for (auto& [_, val]: mp_in) 
                sum += val;
            
            for (auto& [_, val]: mp_in) {
                ans += val * (sum -= val);
            }
        }
        return ans;
    }
};