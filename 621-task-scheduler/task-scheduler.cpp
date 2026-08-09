class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>map;
        for(int i=0;i<tasks.size();i++){
            map[tasks[i]]++;
        }
        unordered_map<char,int>free;
        priority_queue<pair<int,char>>pq;
        for(auto &it : map){
            free[it.first] = 1;
            pq.push({it.second,it.first});
        }
        int seats = 1;
        while(!pq.empty()){
            vector<pair<int,char>>vec;
            bool filled = false;
            while(!pq.empty()){
                pair<int,char>p=pq.top();
                pq.pop();
                int freq = p.first;
                char alp = p.second;
               
                if(free[p.second]<=seats){
                    seats++;
                    free[p.second] = free[p.second] + n + 1;
                    if(freq>1){
                        pq.push({freq-1,alp});
                    }
                    filled = !filled;
                    break;
                }else{
                    vec.push_back(p);
                }
            }
            for(auto &it : vec){
                pq.push(it);
            }
            if(!filled) seats++;
            vec.clear();
        }
        return seats-1;
    }
};