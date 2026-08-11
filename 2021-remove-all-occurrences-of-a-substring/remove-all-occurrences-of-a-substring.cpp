class Solution {
public:
    string removeOccurrences(string s, string part) {
        int idx = s.find(part);
        while(idx>=0){
            s.erase(idx,part.size());
            idx = s.find(part);
        }
        return s;
    }
};