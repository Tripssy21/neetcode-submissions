class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for(string str : strs){
            vector<int> hash(26, 0);
            for(char ch : str)
                hash[ch - 'a']++;
            m[hash].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& [a, b] : m)
            result.push_back(b);
        return result;
    }
};
