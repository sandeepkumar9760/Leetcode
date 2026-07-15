class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()==1) return 0;
        int start = 0;
        int end = arr.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if((mid-1>=0 && mid+1<arr.size() && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) || (mid-1<0 && mid+1<arr.size() && arr[mid]>arr[mid+1]) || (mid+1>=arr.size() && arr[mid]>arr[mid-1])){
                return mid;
            }else if(mid+1<arr.size() && arr[mid]<arr[mid+1]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
};