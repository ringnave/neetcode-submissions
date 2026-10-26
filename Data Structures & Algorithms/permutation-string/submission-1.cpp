class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        array<int, 26> count1{};
        array<int, 26> count2{};
        int matches{};

        for (int i = 0; i < s1.length(); ++i) {
            ++count1[s1[i] - 'a'];
            ++count2[s2[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (count1[i] == count2[i]) ++matches;
        }

        if (matches == 26) return true;

        int len1 = s1.length();
        int len2 = s2.length();

        for (int i = len1; i < len2; ++i) {
            char in_char = s2[i];
            char out_char = s2[i - len1];

            ++count2[in_char - 'a'];
            if (count2[in_char - 'a'] == count1[in_char - 'a']) {
                ++matches;
            } else if (count2[in_char - 'a'] == count1[in_char - 'a'] + 1) {
                --matches;
            }

            --count2[out_char - 'a'];
            if (count2[out_char - 'a'] == count1[out_char - 'a']) {
                ++matches;
            } else if (count2[out_char - 'a'] == count1[out_char - 'a'] - 1) {
                --matches;
            }

            if (matches == 26) return true;
        }

        

        return false;
    }
};
