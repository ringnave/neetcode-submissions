class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (const int& num : nums) {
            if (seen.find(num) == seen.end()) seen[num]++;
            else return true;
        }
        return false;
    }
};