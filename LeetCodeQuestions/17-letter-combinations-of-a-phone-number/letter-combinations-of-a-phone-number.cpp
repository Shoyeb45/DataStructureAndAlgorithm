class Solution {
public:
    void letterComb(int index, vector<string> &ans, string &digits, string &temp, vector<string> &mapping) {
        if (index >= digits.size()) {
            if (!temp.empty()) {
                ans.push_back(temp);
            }
            return;
        }

        int number = digits[index] - '0';
        for (char ch : mapping[number]) {
            temp += ch;
            letterComb(index + 1, ans, digits, temp, mapping);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> a(10), ans;
        a[2] = "abc", a[3] = "def", a[4] = "ghi", a[5] = "jkl", a[6] = "mno", a[7] = "pqrs", a[8] = "tuv", a[9] = "wxyz";
        string temp = "";
    
        letterComb(0, ans, digits, temp, a);
        return ans;
    }
};