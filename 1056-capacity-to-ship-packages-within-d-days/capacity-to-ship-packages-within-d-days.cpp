class Solution {
public:
    int solve(vector<int>&weights , int days , int mid){
        int crr_days = 1;
        int crr_weight = 0;
        for(int i=0;i<weights.size();i++){
            if(crr_weight+weights[i]<=mid){
                crr_weight += weights[i];
            }else{
                crr_days++;
                crr_weight = weights[i];
            }

        }
        return crr_days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int size = weights.size();
        int start = *max_element(weights.begin(),weights.end());
        int end = 0;
        for(int i=0;i<size;i++){
            end+=weights[i];
        }
        if(days==1) return end;
        while(start<=end){
            int mid = start + (end-start)/2;
            int crr_days = solve(weights,days,mid);
            if(crr_days<=days){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return start;
    }
};