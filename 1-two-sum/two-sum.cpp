class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
    
    // Store value + original index
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({nums[i], i});
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i].first;

        int left = i + 1, right = n - 1;

        // Binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].first == complement) {
                return {arr[i].second, arr[mid].second};
            }
            else if (arr[mid].first < complement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return  {};
    };
    
};