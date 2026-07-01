class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(char c : magazine){
            map[c]++;
        }
        unordered_map<char,int>map2;
        for(char c:ransomNote){
            map2[c]++;
        }
        // bool result = false;
        for(int i=0;i<ransomNote.size(); i++){
            if(map2[ransomNote[i]]<=map[ransomNote[i]]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};