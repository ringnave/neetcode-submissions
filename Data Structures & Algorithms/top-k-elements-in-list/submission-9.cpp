class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m.reserve(nums.size());

        for (int num : nums) m[num]++;

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& [key, val] : m) buckets[val].push_back(key);
        
        vector<int> answer;
        answer.reserve(k);

        for (size_t i = nums.size(); i >= 0; i--) {
            if (buckets[i].empty()) continue;
            
            for (int num : buckets[i]) {
                answer.push_back(num);

                if (answer.size() == k) return answer;
            }
        }

        return {};
    }
};
