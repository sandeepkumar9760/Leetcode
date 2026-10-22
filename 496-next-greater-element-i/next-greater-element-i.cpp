class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        for(int i=0;i<nums1.size();i++){
            map[nums1[i]] = i;
        }
        stack<int>st;
        vector<int>ans(nums1.size(),0);
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(map.find(nums2[i])!=map.end()){
                if(!st.empty()){
                    ans[map[nums2[i]]] = st.top();
                }else{
                    ans[map[nums2[i]]] = -1;
                }
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};