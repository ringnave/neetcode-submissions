class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int a[26]{0};
        for (char c : s) {
            a[c - 'a']++;
        }
        for (char c : t) {
            a[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) return false;
        }

        return true;
    }
};
