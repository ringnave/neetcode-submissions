class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int max_val = 1;
        for (int num : s) {
            if (s.count(num - 1)) continue;

            int current_num = num;
            int current_streak = 1;

            while (s.count(current_num + 1)) {
                ++current_num;
                ++current_streak;
            }

            max_val = max(max_val, current_streak);
        }

        return max_val;
    }
};
