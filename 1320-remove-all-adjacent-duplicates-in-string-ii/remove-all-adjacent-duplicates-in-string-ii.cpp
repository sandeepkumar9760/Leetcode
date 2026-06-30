class Solution {
public:
    string removeDuplicates(string s, int k) {
        int count = 0;
        stack<pair<char,int>>st;
        for(int i=0; i<s.size(); i++){
            if(st.empty()){
                st.push({s[i],1});
                continue;
            };
            if(!st.empty() && st.top().first!=s[i]){
                st.push({s[i],1});
                continue;
            };
            if(!st.empty() && st.top().first==s[i]){
                if(st.top().second==k-1){
                    st.pop();
                }else{
                    st.top().second++;
                }
            }

        }
        string str;
        while(!st.empty()){
            str.append(st.top().second,st.top().first);
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};