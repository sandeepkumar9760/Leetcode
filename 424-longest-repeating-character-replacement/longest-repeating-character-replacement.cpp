class Solution {
public:
    int find(vector<int>ans){
        int n = ans.size();
        int element = INT_MIN;
        for(int i=0; i<ans.size(); i++){
            element = max(element,ans[i]);
        }
        return element;
    }
    int characterReplacement(string s, int k) {
        vector<int>ans(256,0);
        int res = INT_MIN;
        int low = 0;
        int high = 0;
        while(high<s.length()){
            ans[s[high]]++;
            int max_element = find(ans);
            int len = high - low + 1;
            int diff = len - max_element;
            while(diff>k){
                ans[s[low]]--;
                low++;
                max_element = find(ans);
                len = high - low  + 1;
                diff = len - max_element;
            }       
            len = high - low + 1;
            res = max(len,res);
            high++;
        }
        return res;
    }
};