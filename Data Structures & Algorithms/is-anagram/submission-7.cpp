class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> arr;

        if (s.length() != t.length()) return false;

        for (char c : s) {
            ++arr[c - 'a'];
        }

        for (char c : t) {
            --arr[c - 'a'];
        }

        for (int n : arr) {
            if (n != 0) return false;
        }

        return true;
    }
};
