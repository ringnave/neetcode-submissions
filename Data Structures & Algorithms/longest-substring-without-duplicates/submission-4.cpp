class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 128> last_index;
        last_index.fill(-1);
        int max_len{};
        int left{};

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];

            if (last_index[c] >= left) {
                left = last_index[c] + 1;
            }

            last_index[c] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
