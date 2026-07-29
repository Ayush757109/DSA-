class Solution {
public:
    static const int CAP = 1000001;

    long long combCap(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            __int128 cur = (__int128)res * (n - r + i);
            cur /= i;
            if (cur > CAP) res = CAP;
            else res = (long long)cur;
        }
        return res;\
    }

    long long countWays(vector<int> &cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long res = 1;
        for (int x : cnt) {
            if (x == 0) continue;
            res *= combCap(rem, x);
            if (res > CAP) return CAP;
            rem -= x;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2) mid = char('a' + i);
        }

        if (countWays(half) < k) return "";

        int len = s.size() / 2;
        string left;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};