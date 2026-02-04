class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int max_area = 0;
        while(start<end){
            int heights = min(height[start],height[end]);
            int width = end-start;
            int crr_area = heights * width;
            max_area = max(max_area,crr_area);
            height[start]<height[end] ? start++ : end--;
        }
        return max_area;
    }
};