class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int size = profits.size();
        vector<pair<int,int>>choices;
        for(int i=0;i<size;i++){
            choices.push_back({capital[i],profits[i]});
        }
        sort(choices.begin(),choices.end());
        priority_queue<int>pq;
        int idx = 0;
        int res = w;
        while(k--){
            while(idx<size){
                if(choices[idx].first>res){
                    break;
                }
                pq.push(choices[idx].second);
                idx++;
            }
            if(pq.empty()){
                return res;
            }else{
                int profit = pq.top();
                res += profit;
                pq.pop();
            }
        }
        return res;
    }
};