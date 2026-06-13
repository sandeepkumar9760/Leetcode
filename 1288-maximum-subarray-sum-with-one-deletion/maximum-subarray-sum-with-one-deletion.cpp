class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int no_del = arr[0];
        int one_del = INT_MIN;
        int res = arr[0];
        for(int i=1; i<arr.size(); i++){
            int prevno_del = no_del;
            no_del = max(no_del+arr[i],arr[i]);
            if(one_del==INT_MIN){
                one_del = 0;
            }
            one_del = max(prevno_del , one_del + arr[i]);
            res = max(res,max(one_del,no_del));
        }
        return res;
    }
};