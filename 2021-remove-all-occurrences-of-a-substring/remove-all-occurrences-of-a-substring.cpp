class Solution {
public:
    string removeOccurrences(string s, string part) {
        int index = s.find(part);
        while(index>=0 && index<s.length()){
            s.erase(index , part.length());
            index = s.find(part);
        }
        return s;
    }
};