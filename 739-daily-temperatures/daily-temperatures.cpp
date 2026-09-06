class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        int size = t.size();
        vector<int> ans(size);
        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && t[st.top()] <= t[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = 0;
                st.push(i);
            }else{
                ans[i]=st.top()-i;
                st.push(i);
            }
        }
        return ans;
    }
};