class Solution {
public:
    string key = "||";
    string encode(vector<string>& strs) {
        string result = "";
        for(string str : strs)
            result += (str + key);
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        for(int i = 0; i < s.length(); i++){
            string str = "";
            while(s.substr(i, 2) != key){
                str += s[i];
                i++;
            }
            if(i < s.length() - 1)
                i++;
            result.push_back(str);
        }
        return result;
    }
};
