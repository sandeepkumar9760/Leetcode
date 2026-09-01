class NumArray {
private:
    vector<int>prefix_sum;
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        prefix_sum.resize(size+1,0);
        for(int i=0; i<size; i++){
            prefix_sum[i+1] = prefix_sum[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right+1]-prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */