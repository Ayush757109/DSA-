class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // For each row, store which seats from 2 to 9 are reserved.
        unordered_map<int, int> reserved;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                reserved[row] |= (1 << col);
            }
        }

        // A completely empty row can fit 2 groups.
        int ans = (n - reserved.size()) * 2;

        for (auto &[row, mask] : reserved) {
            // Possible blocks:
            // 2,3,4,5
            // 4,5,6,7
            // 6,7,8,9

            bool left  = !(mask & ((1 << 2) | (1 << 3) |
                                   (1 << 4) | (1 << 5)));

            bool middle = !(mask & ((1 << 4) | (1 << 5) |
                                    (1 << 6) | (1 << 7)));

            bool right = !(mask & ((1 << 6) | (1 << 7) |
                                   (1 << 8) | (1 << 9)));

            if (left && right) {
                // Can place two groups.
                ans += 2;
            } else if (left || middle || right) {
                // Can place exactly one group.
                ans += 1;
            }
        }

        return ans;
    }
};