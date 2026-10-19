class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        if (p_size > s_size)
            return {};
        vector<int> ans;
        vector<int> p_count(26, 0);
        for (int i = 0; i < p_size; i++) {
            p_count[p[i] - 'a']++;
        }
        vector<int> s_count(26, 0);
        for (int j = 0; j < p_size; j++) {
            s_count[s[j] - 'a']++;
        }
        if (s_count == p_count) {
            ans.push_back(0);
        }
        for (int high = p_size; high < s_size; high++) {
            s_count[s[high] - 'a']++;
            s_count[s[high - p_size] - 'a']--;
            if (s_count == p_count) {
                ans.push_back(high-p_size+1);
            }
        }
        return ans;
    }
};