class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 128> last_index;
        last_index.fill(-1);
        int left{0};
        int max_len{0};

        for (int right = 0; right < s.length(); ++right) {
            char ch = s[right];

            if (last_index[ch] >= left) {
                left = last_index[ch] + 1;
            }

            last_index[ch] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
