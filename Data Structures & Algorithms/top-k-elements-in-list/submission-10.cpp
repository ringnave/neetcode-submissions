class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m.reserve(nums.size());

        for (int num : nums) m[num]++;

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& [key, val] : m) {
            buckets[val].push_back(key);
        }

        vector<int> ans;
        ans.reserve(nums.size());
        for (int i = nums.size(); i >= 0; --i) {
            for (int n : buckets[i]) {
                ans.push_back(n);
                if (ans.size() == k) return ans;
            }
        }

        return {};
    }
};
