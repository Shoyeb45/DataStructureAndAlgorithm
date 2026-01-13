class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double left = 0, right = 1e9;

        while (right - left > 1e-6) {
            double mid = (left + right) / 2;

            double up = 0, down = 0;

            for (auto& p : squares) {
                double y = p[1];
                double side = p[2];
                double top = y + side;

                if (top <= mid) {
                    down += side * side;
                }
                else if (y >= mid) {
                    up += side * side;
                }
                else {
                    double h_down = mid - y;
                    double h_up = top - mid;

                    down += side * h_down;
                    up += side * h_up;
                }
            }

            if (down >= up)
                right = mid;
            else
                left = mid;
        }

        return left;
    }
};
