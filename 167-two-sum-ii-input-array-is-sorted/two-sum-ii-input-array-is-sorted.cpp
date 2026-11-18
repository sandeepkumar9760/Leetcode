class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>map;
        for(int i=0;i<numbers.size();i++){
            int find = target-numbers[i];
            if(map.find(find)!=map.end()){
                return {map[find],i+1};
            }
            map[numbers[i]]=i+1;
        }
        return {-1,-1};
    }
};