class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> seen;
        seen.reserve(numbers.size());

        for (int i = 0; i < numbers.size(); ++i) {
            int remain = target - numbers[i];
            auto it = seen.find(remain);

            if (it != seen.end()) {
                return {it->second + 1, i + 1};
            }

            seen[numbers[i]] = i;
        }

        return {};
    }
};
