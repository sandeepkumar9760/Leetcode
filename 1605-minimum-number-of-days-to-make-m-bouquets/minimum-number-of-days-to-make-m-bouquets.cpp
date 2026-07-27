class Solution {
public:
    bool is_possible(int m , int k , int mid , vector<int>&bloomday){
        int bouq = 0;
        int flower = 0;
        for(int i=0;i<bloomday.size();i++){
            if(bloomday[i]<=mid){
                flower++;
            }else{
                flower = 0;
            }
            if(flower==k){
                bouq++;
                flower = 0;
            }
            if(bouq>=m){
                return true;
            }
        }
        return false;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m * k;
        if(total>bloomDay.size()) return -1;
        int start = *min_element(bloomDay.begin() , bloomDay.end());
        int end = *max_element(bloomDay.begin() , bloomDay.end());
        int days = INT_MAX;
        while(start<=end){
            int mid = start  + (end-start)/2;
            if(is_possible(m ,k, mid, bloomDay)){
                days = mid;
                end = mid - 1;
            }else{
                start = mid+1;
            }
        }
        return days;

    }
};