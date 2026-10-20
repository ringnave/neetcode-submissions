class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.length() != t.length()) return false;

        array<int, 26> count{};

        for (char c : s) {
            count[c - 'a']++;
        }

        for (char c : t) {
            if (--count[c - 'a'] < 0) return false;
        }

        return true;
    }
};
