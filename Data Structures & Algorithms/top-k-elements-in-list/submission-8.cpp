class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> m;
        m.reserve(nums.size());

        for (int num : nums) m[num]++;

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& [k, v] : m) buckets[v].push_back(k);

        vector<int> answer;
        answer.reserve(k);

        for (size_t i = nums.size(); i > 0; i--) {
            if (buckets[i].empty()) continue;
            for (int b : buckets[i]) {
                answer.push_back(b);
                if (answer.size() == k) return answer;
            }
        }

        return {};
    }
};
