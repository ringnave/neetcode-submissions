class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        vector<vector<string>> answer;

        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            seen[sorted_str].push_back(str);
        }

        answer.reserve(seen.size());
        for (auto& [key, values]: seen) {
            answer.push_back(move(values));
        }

        return answer;
    }
};
