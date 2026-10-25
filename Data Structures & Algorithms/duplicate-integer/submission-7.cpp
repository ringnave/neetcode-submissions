class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> seen;

        for (int num : nums) {
            auto it = seen.find(num);

            if (it == seen.end()) {
                seen[num] = true;
            } else {
                return true;
            }
        }

        return false;
    }
};