class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const size_t len_s1 = s1.length();
        const size_t len_s2 = s2.length();

        if (len_s1 > len_s2) return false;

        array<int, 26> count_s1{};
        array<int, 26> count_s2{};

        int matches{};

        for (size_t i = 0; i < len_s1; ++i) {
            ++count_s1[s1[i] - 'a'];
            ++count_s2[s2[i] - 'a'];
        }

        for (size_t i = 0; i <26; ++i) {
            if (count_s1[i] == count_s2[i]) ++matches;
        }

        if (matches == 26) return true;

        for (size_t right = len_s1; right < len_s2; ++right) {
            size_t in_idx = s2[right] - 'a';
            size_t out_idx = s2[right - len_s1] - 'a';

            ++count_s2[in_idx];
            if (count_s2[in_idx] == count_s1[in_idx]) {
                ++matches;
            } else if (count_s2[in_idx] == count_s1[in_idx] + 1) {
                --matches;
            }

            --count_s2[out_idx];
            if (count_s2[out_idx] == count_s1[out_idx]) {
                ++matches;
            } else if (count_s2[out_idx] == count_s1[out_idx] - 1) {
                --matches;
            }

            if (matches == 26) return true;
        }

        return false;
    }
};
