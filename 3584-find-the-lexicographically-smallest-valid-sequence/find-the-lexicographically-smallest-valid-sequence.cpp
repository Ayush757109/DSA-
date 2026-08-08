class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp0[i] = maximum suffix of word2 that can be matched
        // exactly using word1[i...]
        vector<int> dp0(n + 1, 0);

        // dp1[i] = maximum suffix of word2 that can be matched
        // using word1[i...] with at most ONE mismatch
        vector<int> dp1(n + 1, 0);

        // Build suffix DP from right to left
        for (int i = n - 1; i >= 0; --i) {

            // -------- Exact matching --------
            int k = dp0[i + 1];

            if (k < m && word1[i] == word2[m - k - 1])
                dp0[i] = k + 1;
            else
                dp0[i] = k;

            // -------- At most one mismatch --------
            k = dp1[i + 1];

            // Don't use word1[i]
            dp1[i] = k;

            // Match word1[i] exactly
            if (k < m && word1[i] == word2[m - k - 1]) {
                dp1[i] = max(dp1[i], k + 1);
            }

            // Use word1[i] as the one mismatch
            int exact = dp0[i + 1];

            if (exact < m) {
                dp1[i] = max(dp1[i], exact + 1);
            }
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        // Greedily choose the smallest possible index
        for (int j = 0; j < m; ++j) {

            bool found = false;
            int remaining = m - j - 1;

            for (int i = pos; i < n; ++i) {

                if (word1[i] == word2[j]) {
                    // Current character matches.
                    // We can preserve the mismatch for later.
                    bool possible;

                    if (usedMismatch)
                        possible = (dp0[i + 1] >= remaining);
                    else
                        possible = (dp1[i + 1] >= remaining);

                    if (possible) {
                        ans.push_back(i);
                        pos = i + 1;
                        found = true;
                        break;
                    }
                }
                else {
                    // Use our one allowed mismatch here.
                    if (!usedMismatch && dp0[i + 1] >= remaining) {
                        ans.push_back(i);
                        pos = i + 1;
                        usedMismatch = true;
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                return {};
        }

        return ans;
    }
};