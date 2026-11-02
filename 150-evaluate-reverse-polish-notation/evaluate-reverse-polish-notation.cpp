class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="*"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int crr_ans = first * second;
                st.push(crr_ans);
            }else if(tokens[i]=="/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int crr_ans = first / second;
                st.push(crr_ans);
            }else if(tokens[i]=="+"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int crr_ans = first + second;
                st.push(crr_ans);
            }else if(tokens[i]=="-"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int crr_ans = first - second;
                st.push(crr_ans);
            }else{
                int crr_ans = stoi(tokens[i]);
                st.push(crr_ans);
            }
        }
        return st.top();
    }
};