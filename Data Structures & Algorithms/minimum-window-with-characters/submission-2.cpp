class Solution {
public:
    string minWindow(string s, string t) {
        const size_t len_s = s.length();
        const size_t len_t = t.length();

        if (len_s < len_t) return "";

        array<int, 128> target_freq{};

        for (char c : t) {
            ++target_freq[c];
        }

        int required_chars{};

        for (size_t i = 0; i < 128; ++i) {
            if (target_freq[i] > 0) ++required_chars;
        }

        size_t min_len = numeric_limits<size_t>::max();
        int satisfied_chars{};
        array<int, 128> window_freq{};
        size_t left{};
        size_t start_idx{};

        for (size_t right = 0; right < len_s; ++right) {
            char in_char = s[right];

            ++window_freq[in_char];

            if (target_freq[in_char] > 0 && target_freq[in_char] == window_freq[in_char]) {
                ++satisfied_chars;
            }

            while (satisfied_chars == required_chars) {
                size_t cur_len = right - left + 1;
                char out_char = s[left];

                if (cur_len < min_len) {
                    min_len = cur_len;
                    start_idx = left;
                }

                if (target_freq[out_char] > 0 && target_freq[out_char] == window_freq[out_char]) {
                    --satisfied_chars;
                }

                --window_freq[out_char];
                ++left;
            }
        }

        return (min_len == numeric_limits<size_t>::max()) ? "" : s.substr(start_idx, min_len);
    }
};
