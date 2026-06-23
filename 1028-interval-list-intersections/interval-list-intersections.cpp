class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.empty() || secondList.empty()) return {};
        vector<vector<int>>ans;
        int i=0;
        int j=0;
        int n = firstList.size();
        int m = secondList.size();
        while(i<n && j<m){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            if(start1<start2){
                if(end1>=start2){
                    int s = max(start1,start2);
                    int e = min(end1,end2);
                    ans.push_back({s,e});
                }
            }else{
                if(end2>=start1){
                    int s = max(start1,start2);
                    int e = min(end1,end2);
                    ans.push_back({s,e});
                }
            }
            end1<end2 ? i++:j++;
        }
        return ans;
    }
};