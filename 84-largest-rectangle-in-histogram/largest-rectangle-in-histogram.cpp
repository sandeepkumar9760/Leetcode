class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int>st;
        vector<int>ps(size);
        for(int i=0;i<size;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ps[i]=-1;
            }else{
                ps[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int>ns(size);
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ns[i] = size;
            }else{
                ns[i] = st.top();
            }
            st.push(i);
        }
        int res = 0;
        for(int i=0;i<size;i++){
            int crr_ans = (ns[i]-ps[i]-1)*heights[i];
            res = max(res,crr_ans);
        }
        return res;
    }
};