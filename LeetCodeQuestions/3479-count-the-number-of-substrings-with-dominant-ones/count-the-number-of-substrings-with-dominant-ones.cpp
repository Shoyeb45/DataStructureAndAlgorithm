class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // 1) prefix sums of ones
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (s[i] == '1');

        auto ones = [&](int l, int r) {
            if (r < l) return 0;
            return pref[r + 1] - pref[l];
        };

        // ------------------------------
        // 2) collect all zero positions
        // ------------------------------
        vector<int> zero;
        for (int i = 0; i < n; i++)
            if (s[i] == '0') zero.push_back(i);

        int Z = zero.size();
        long long ans = 0;

        // ------------------------------
        // 3) Case 1: substrings with 0 zeros (pure blocks of ones)
        // ------------------------------
        for (int i = 0; i < n; ) {
            if (s[i] == '0') { i++; continue; }

            int j = i;
            while (j < n && s[j] == '1') j++;

            long long len = j - i;
            ans += len * (len + 1) / 2;

            i = j;
        }

        // ------------------------------
        // 4) Case 2: substrings with z zeros, z <= sqrt(n)
        // ------------------------------
        int B = sqrt(n) + 2;

        for (int z = 1; z <= B && z <= Z; z++) {

            // windows of exactly z zeros:
            // zero[i], zero[i+1], ..., zero[i+z-1]
            // L ranges from (left boundary + 1) to zero[i]
            // R ranges from zero[i+z-1] to (right boundary - 1)
            for (int i = 0; i + z - 1 < Z; i++) {

                int firstZero = zero[i];
                int lastZero = zero[i + z - 1];

                int Lmin = (i == 0 ? 0 : zero[i - 1] + 1);
                int Lmax = firstZero;

                int Rmin = lastZero;
                int Rmax = (i + z - 1 == Z - 1 ? n - 1 : zero[i + z] - 1);

                if (Lmin > Lmax || Rmin > Rmax)
                    continue;

                int need = z * z;

                // two-pointer on R
                int r = Rmin;
                for (int L = Lmin; L <= Lmax; L++) {
                    // move r until substring [L..r] satisfies ones >= z^2
                    while (r <= Rmax && ones(L, r) < need) r++;
                    if (r > Rmax) break;

                    ans += (Rmax - r + 1);
                }
            }
        }

        return ans;
    }
};
