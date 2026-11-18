#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        solve(0, nums, current, result);
        return result;
    }

private:
    void solve(int index, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
   
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        solve(index + 1, nums, current, result);
        current.pop_back();
        solve(index + 1, nums, current, result);
    }
};
