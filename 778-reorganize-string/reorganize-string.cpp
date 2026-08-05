class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,char>&a , const pair<int,char>&b)const{
            if(a.first==b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp>pq;
        for(auto &it: map){
            pq.push({it.second,it.first});
        }
        string str = "";
        int idx = 0;
        while(!pq.empty()){
            int freq = pq.top().first;
            char alph = pq.top().second;
            pq.pop();
            if(str.size()==0 || str[idx-1]!=alph){
                str+=alph;
                idx++;
                freq--;
            }else{
                if(pq.empty()) return "";
                str += pq.top().second;
                idx++;
                int freq = pq.top().first;
                char alph = pq.top().second;
                pq.pop();
                freq--;
                if(freq>0){
                    pq.push({freq,alph});
                }
            }
            if(freq>0){
                pq.push({freq,alph});
            }
            
        }
        return str;
    }
};