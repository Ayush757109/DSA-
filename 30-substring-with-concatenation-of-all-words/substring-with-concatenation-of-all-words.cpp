class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (totalLen > n)
            return ans;

        // Required frequency of each word.
        unordered_map<string, int> need;

        for (const string& word : words) {
            need[word]++;
        }

        // Try every possible alignment.
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int right = offset;

            // Frequency of words currently inside the window.
            unordered_map<string, int> have;

            int count = 0;  // Number of words currently in window.

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                // This word isn't part of words.
                // The current window can no longer be valid.
                if (!need.count(word)) {
                    have.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                // Add word to window.
                have[word]++;
                count++;

                // Too many copies of this word.
                // Remove words from the left until valid.
                while (have[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // We have exactly all words.
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move forward by one word so we can find
                    // overlapping answers as well.
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};