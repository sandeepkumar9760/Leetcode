class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int> &a , const pair<int,int> &b) const{
            if(a.first==b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        int size = arr.size();
        for(int i=0; i<size;i++){
            int dif = abs(arr[i]-x);
            if(pq.size()!=k){
                pq.push({dif,arr[i]});
            }else{
                if(pq.top().first>dif){
                    pq.pop();
                    pq.push({dif,arr[i]});
                }else if(pq.top().first==dif){
                    if(pq.top().second>arr[i]){
                        pq.pop();
                        pq.push({dif,arr[i]});
                    }
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};