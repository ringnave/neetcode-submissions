class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> a;

        for (const int& num : nums) m[num]++;

        vector<pair<int, int>> n(m.begin(), m.end());

        sort(n.begin(), n.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        a.reserve(n.size());
        for (int i=0; i<k; i++) {
            a.push_back(n[i].first);
        }

        return a;
    }
};
