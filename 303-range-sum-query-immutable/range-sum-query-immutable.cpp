class NumArray {
public:
 vector<int> p;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        p.resize(n+1);
        p[0] = 0;
        for(int i=0;i<n;i++){
            p[i+1] = nums[i]+p[i];
        }

        
    }
    
    int sumRange(int left, int right) {
        return p[right+1] - p[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */