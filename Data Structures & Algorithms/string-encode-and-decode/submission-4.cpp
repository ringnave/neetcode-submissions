class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (const string& str: strs) {
            encoded += to_string(str.length());
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == '#') {
                    int len = stoi(s.substr(i, j - i));
                    string word = s.substr(j + 1, len);

                    decoded.push_back(word);

                    i = j + len;
                    break;
                }
            }

        }

        return decoded;
    }
};
