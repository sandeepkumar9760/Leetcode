class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string str = "balloon";
        unordered_map<char,int>need;
        for(char c:str){
            need[c]++;
        }
        unordered_map<char,int>have;
        for(char c : text){
            have[c]++;
        }
        int count = INT_MAX;
        for(int i=0;i<str.size();i++){
            int ans = have[str[i]]/need[str[i]];
            count = min(ans,count);
        }
        return count;

    }
};