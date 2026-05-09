class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<long long>prefixsum(size,0);
        prefixsum[0]=nums[0];
        for(int i=1; i<size; i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        unordered_map<long long,int>m;
        int count = 0;
        for(int i=0; i<size; i++){
            if(prefixsum[i]==k) count++;
            long long val = prefixsum[i] - k ;
            if(m.find(val)!=m.end()){
                count += m[val];
            }
            m[prefixsum[i]]++;
        }
        return count;
    }
};