class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> answer;
        answer.reserve(2);

        for (int i = 0; i < nums.size(); i++) {
            if(seen.find(target - nums[i]) != seen.end()) {
                return {seen[target - nums[i]], i};
            } else {
                seen[nums[i]] = i;
            }
        }


    }
};
