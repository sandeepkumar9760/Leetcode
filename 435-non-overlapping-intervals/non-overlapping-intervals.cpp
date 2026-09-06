class Solution {
public:
    static bool compare(const vector<int>& a , const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int count = 0;
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if(end1<=start2){
                count++;
                start1 = start2;
                end1 = end2;
            }
        }
        return intervals.size()-count-1;
    }
};