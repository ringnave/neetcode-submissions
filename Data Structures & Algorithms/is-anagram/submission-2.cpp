class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sl;
        unordered_map<char, int> tl;
        for (char c : s) {
            if (sl.find(c) != sl.end()) {
                sl[c]++;
            } else {
                sl[c] = 1;
            }
        }
        for (char c : t) {
            if (tl.find(c) != tl.end()) {
                tl[c]++;
            } else {
                tl[c] = 1;
            }
        }
        for (const auto& [f, s] : sl) {
            if (tl[f] != s) return false;
        }
        for (const auto& [f, s] : tl) {
            if (sl[f] != s) return false;
        }
        return true;
    }
};
