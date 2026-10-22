class Solution {
public:

    string encode(vector<string>& strs) {
        string e{""};

        for (const string& str : strs) {
            int len = str.length();
            e += to_string(len);
            e += '#';
            e += str;
        }

        return e;
    }

    vector<string> decode(string s) {
        vector<string> d;
        int i = 0;

        while (i < s.length()) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);

            d.push_back(word);

            i = j + len + 1;
        }

        return d;
    }
};
