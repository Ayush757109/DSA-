class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int diff = 0;
        int leftQ = 0;
        int rightQ = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }

        // Odd number of '?' means Alice gets the last move.
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Bob can force equality only in this exact case.
        return 2 * diff != 9 * (rightQ - leftQ);
    }
};