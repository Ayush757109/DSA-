class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(int idx, string &digits, string curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for (char ch : mp[digits[idx]]) {
            solve(idx + 1, digits, curr + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        solve(0, digits, "");
        return ans;
    }
};