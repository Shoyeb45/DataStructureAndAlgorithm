class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int freq[(int)(1e6 + 2)];
        memset(freq, 0, sizeof freq);

        for (auto x : intervals) {
            freq[x[0]]++;
            cout << x[1] + 1 << "\n"; 
            freq[x[1] + 1]--;
        }

        for (int i = 1; i <= (int)1e6 + 1; i++) {
            freq[i] += freq[i - 1]; 
        }
        return *max_element(freq, freq + (int)1e6 + 2);
    }
};