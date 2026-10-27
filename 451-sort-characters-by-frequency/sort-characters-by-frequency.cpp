class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>map;
        for(auto &ch : s){
            map[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &it : map){
            pq.push({it.second,it.first});
        }

        string str = "";
        while(!pq.empty()){
            int size = pq.top().first;
            for(int i=0;i<size;i++){
                str+=pq.top().second;
            }
            pq.pop();
        }
        return str;
    }
};