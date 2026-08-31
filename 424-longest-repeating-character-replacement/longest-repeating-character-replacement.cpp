class Solution {
public:
    int find(vector<int>map){
        int element = 0;
        for(int i=0;i<map.size();i++){
            element = max(element,map[i]);
        }
        return element;
    }
    int characterReplacement(string s, int k) {
        int max_freq = 0;
        vector<int>map(26,0);
        int low = 0;
        int high = 0;
        while(high<s.size()){
            map[s[high]-'A']++;
            int freq = find(map);
            int length = high - low + 1;
            while(length-freq>k){
                map[s[low]-'A']--;
                freq = find(map);
                low++;
                length = high - low + 1;
            }
            max_freq = max(max_freq,length);
            high++;
        }
        return max_freq;
    }
};