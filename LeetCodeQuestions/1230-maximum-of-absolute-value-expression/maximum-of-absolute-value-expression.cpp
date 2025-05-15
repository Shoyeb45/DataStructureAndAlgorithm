class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {
        int n = a.size();

        // x -> ai + bi + i
        int xMax = INT_MIN, xMin = INT_MAX;

        // y -> ai - bi + i
        int yMax = INT_MIN, yMin = INT_MAX;
        
        // z -> ai - bi - i
        int zMax = INT_MIN, zMin = INT_MAX;
        
        // w -> ai + bi - i
        int wMax = INT_MIN, wMin = INT_MAX;

        for (int i = 0; i < n; i++) {
            int xTemp = a[i] + b[i] + i;
            int yTemp = a[i] - b[i] + i;
            int zTemp = a[i] - b[i] - i;
            int wTemp = a[i] + b[i] - i;

            xMax = max(xMax, xTemp), xMin = min(xMin, xTemp);
            yMax = max(yMax, yTemp), yMin = min(yMin, yTemp);
            zMax = max(zMax, zTemp), zMin = min(zMin, zTemp);
            wMax = max(wMax, wTemp), wMin = min(wMin, wTemp);
        }


        return max({
            xMax - xMin,
            yMax - yMin,
            zMax - zMin,
            wMax - wMin
        });
    }
};