class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int ans = INT_MIN;
        while(start<=end){
            int length = min(height[start],height[end]);
            int crr_area = (end-start) * length;
            ans = max(crr_area,ans);
            height[start]<height[end] ? start++ : end--;
        }
        return ans;
    }
};