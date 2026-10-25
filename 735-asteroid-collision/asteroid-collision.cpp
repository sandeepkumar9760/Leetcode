class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        for(auto x : ast){
            bool alive = true;

            while(alive && x<0 && !st.empty() && st.top()>0){
                if(st.top()==abs(x)){
                    st.pop();
                    alive = false;
                }else if(st.top()<abs(x)){
                    st.pop();
                }else{
                    alive = false;
                }
            }
            if(alive){
                st.push(x);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};