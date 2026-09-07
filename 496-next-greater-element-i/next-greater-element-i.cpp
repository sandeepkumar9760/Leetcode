class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&nums1, vector<int>& nums2) {
        stack<int>st;
        int size = nums2.size();
        unordered_map<int,int>res;
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                res[nums2[i]]=-1;
                st.push(nums2[i]);
            }else{
                res[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(res[nums1[i]]);
        }
        return ans;
       
    }
};