class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;
        vector<int>res(m+n);
        int idx = 0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                res[idx]=nums1[i];
                i++;
            }else{
                res[idx]=nums2[j];
                j++;
            }
            idx++;
        }
        while(i<m){
            res[idx]=nums1[i];
            idx++;
            i++;
        }
         while(j<n){
            res[idx]=nums2[j];
            j++;
            idx++;
        }
        double ans;
        int size = m+n;
        if(size%2!=0){
            int mid = size/2;
            return res[mid];
        }else{
            int mid = size/2;
            if(mid-1>=0) ans =  double (res[mid-1]+res[mid])/2;
            else ans =  res[mid];
        }
        // int mid = (m+n)/2;
        // double ans;
        // if(mid%2!=0){
        //     ans = res[mid];
        // }else{
        //     if(mid-1>=0) ans = double (res[mid-1]+res[mid])/2;
        //     else ans = res[mid];
        // }
        return ans;
    }
};