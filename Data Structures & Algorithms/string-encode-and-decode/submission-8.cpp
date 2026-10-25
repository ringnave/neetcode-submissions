class Solution {
public:

    string encode(vector<string>& strs) {
        string e{};

        for (string str : strs) {
            int n = str.length();
            e += to_string(n);
            e += '#';
            e += str;
        }

        return e;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i{};

        while (i < s.length()) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);

            res.push_back(word);

            i = j + len + 1;
        }

        return res;
    }
};
