class Solution {
public:
    bool check(int mid , vector<int>&piles , int h){
        long long time_taken = 0;
        for(int i=0; i<piles.size(); i++){
            // time_taken += 0ll+(piles[i]+mid-1)/mid;
            int idx = piles[i]%mid;
            time_taken += 0ll + (piles[i]/mid);
            idx < mid && idx>0 ? time_taken++ : time_taken;
        }
        return time_taken<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(check(mid,piles,h)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};