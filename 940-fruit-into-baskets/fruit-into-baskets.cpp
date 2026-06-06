class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int res = 0;
        unordered_map<int,int>map;
        for(int high=0; high<fruits.size(); high++){
            map[fruits[high]]++;
            res += 1;
            if(map.size()>2){
                res -= 1;
                map[fruits[low]]--;
                if(map[fruits[low]]==0){
                    map.erase(fruits[low]);
                }
                low++;
            }

        }
        return res;
    }
};