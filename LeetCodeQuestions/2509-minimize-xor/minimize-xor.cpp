class Solution {
public:
    string int_to_binary(int num2) {
        string ans;
        while (num2) {
            ans += (char)(num2 % 2 + '0');
            num2 /= 2;
        }
        return ans;
    }

    int set_bits(int num) {
        int ans = 0;
        while (num) {
            ans += num % 2;
            num /= 2;
        }
        return ans;
    }

    int minimizeXor(int num1, int num2) {
        string s = int_to_binary(num1);
        int setBits = set_bits(num2);
        // cout << s << "\n";
        // cout << "sb " << setBits << "\n";
        int ans = 0;

        for (int i = s.size() - 1; i >= 0 && setBits; i--) {
            // cout << "s[i] " << s[i] << "\n";
            if (s[i] == '1') {
                ans = (ans | (1 << i));
                // cout << "Pos : " << i << '\n';
                setBits--;
            }
        }


        for (int i = 0; i < 32 && setBits; i++) {
            int bit = (ans & (1 << i));
            if (bit == 0) {
                ans = (ans | (1 << i));
                setBits--;
            }
        }

        return ans;
    }
};