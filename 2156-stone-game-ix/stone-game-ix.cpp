class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // Number of stones divisible by 3 is even.
        if (cnt[0] % 2 == 0) {
            // Alice needs at least one 1 and one 2.
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // Number of 0-modulo stones is odd.
        // Alice wins only if one side has more than 2 extra stones.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};