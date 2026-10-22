class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set{nums.begin(), nums.end()};
        int ans = 0;

        for (int num : nums) {
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int current_streak = 1;
                ans = max(ans, current_streak);

                while (num_set.count(current_num + 1)) {
                    ++current_num;
                    ++current_streak;

                    ans = max(ans, current_streak);
                }
            }
        }

        return ans;
    }
};
