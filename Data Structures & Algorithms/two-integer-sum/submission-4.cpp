class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        seen.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int remain = target - nums[i];

            if (seen.find(remain) != seen.end()) return {seen[remain], i};

            seen[nums[i]] = i;
        }

        return {};
    }
};
