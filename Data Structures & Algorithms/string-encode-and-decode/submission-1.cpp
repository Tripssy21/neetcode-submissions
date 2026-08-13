class Solution {
public:
    string key = "||";
    string encode(vector<string>& strs) {
        string result = "";
        for(string str : strs)
            result += (to_string(str.length()) + key + str);
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        for(int i = 0; i < s.length();){
            string length = "";
            while(s.substr(i, key.length()) != key){
                length += s[i];
                i++;
            }
            i += key.length();
            result.push_back(s.substr(i, stoi(length)));
            i += stoi(length);
        }
        return result;
    }
};
