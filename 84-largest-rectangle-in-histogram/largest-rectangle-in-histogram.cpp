class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st1;
        vector<int>ans(heights.size());
        
        for(int i=heights.size()-1; i>=0; i--){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                ans[i]=heights.size();
            }else{
                ans[i]=st1.top();
            }
            st1.push(i);
        }
        while(!st1.empty()){
            st1.pop();
        }
        vector<int>ans2(heights.size());
        
        for(int i=0; i<heights.size(); i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                ans2[i]=-1;
            }else{
                ans2[i]=st1.top();
            }
            st1.push(i);
        }
        int result = 0;
        for(int i=0; i<heights.size(); i++){
            int ans3 = (ans[i]-ans2[i]-1)*heights[i];
            result = max(result,ans3);
        }
        return result;
        
        

    }
};