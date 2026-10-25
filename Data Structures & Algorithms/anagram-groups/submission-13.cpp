class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> str_map;

        for (string str : strs) {
            string sorted_str{str.begin(), str.end()};
            sort(sorted_str.begin(), sorted_str.end());
            str_map[sorted_str].push_back(str);
        }

        for (const auto& [key, value] : str_map) {
            res.push_back(value);
        }

        return res;
    }
};
