class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set{nums.begin(), nums.end()};
        int len = 0;

        for (int num : num_set) {
            if (num_set.count(num - 1)) continue;

            // int current_num = num;
            int current_streak = 1;

            while (num_set.count(num + 1)) {
            // while (num_set.count(current_num + 1)) {
            //     ++current_num;
                ++num;
                ++current_streak;
            }

            len = max(len, current_streak);
        }

        return len;
    }
};
