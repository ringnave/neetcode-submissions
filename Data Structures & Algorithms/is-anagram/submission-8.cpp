class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        array<int, 26> arr{};

        for (char c : s) {
            ++arr[c - 'a'];
        }

        for (char c : t) {
            if (--arr[c - 'a'] < 0) return false;
        }

        return true;
    }
};
