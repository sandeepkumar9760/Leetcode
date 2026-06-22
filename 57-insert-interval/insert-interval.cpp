class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty() && newInterval.size()!=0){
            return {newInterval};
        }
        if(intervals.empty()) return {};
        vector<vector<int>>ans;
        bool insert = false;
        for(int i=0; i<intervals.size(); i++){
            if(insert==false && intervals[i][0]>=newInterval[0]){
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                insert = true;
            }else{
                ans.push_back(intervals[i]);
            }
        }
        if(insert==false){
            ans.push_back(newInterval);
        }
        vector<vector<int>>result;
        int start1 = ans[0][0];
        int end1 = ans[0][1];
        for(int i=1; i<ans.size(); i++){
            int start2 = ans[i][0];
            int end2 = ans[i][1];
            if(end1>=start2){
                end1 = max(end1 , ans[i][1]);
                continue;
            }else{
                result.push_back({start1,end1});
                start1 = start2;
                end1=end2;
            }
        }
        result.push_back({start1,end1});
        return result;

    }
};