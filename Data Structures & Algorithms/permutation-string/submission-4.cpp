class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const size_t len1 = s1.length();
        const size_t len2 = s2.length();

        if (len1 > len2) return false;

        array<int, 26> count1{};
        array<int, 26> count2{};

        for (size_t i = 0; i < len1; ++i) {
            ++count1[s1[i] - 'a'];
            ++count2[s2[i] - 'a'];
        }

        int matches{};

        for (size_t i = 0; i < 26; ++i) {
            if (count1[i] == count2[i]) ++matches;
        }

        if (matches == 26) return true;

        for (size_t i = len1; i < len2; ++i) {
            size_t in_idx = s2[i] - 'a';
            size_t out_idx = s2[i - len1] - 'a';

            ++count2[in_idx];
            if (count2[in_idx] == count1[in_idx]) {
                ++matches;
            } else if (count2[in_idx] == count1[in_idx] + 1) {
                --matches;
            }

            --count2[out_idx];
            if (count2[out_idx] == count1[out_idx]) {
                ++matches;
            } else if (count2[out_idx] == count1[out_idx] - 1) {
                --matches;
            }

            if (matches == 26) return true;
        }

        return false;
    }
};
