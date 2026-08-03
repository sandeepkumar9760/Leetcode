class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        int idx = k;
        while(idx<nums.size()){
            if(pq.top()<=nums[idx]){
                pq.pop();
                pq.push(nums[idx]);
                idx++;
            }else{
                idx++;
            }
        }
        return pq.top();
    }
};