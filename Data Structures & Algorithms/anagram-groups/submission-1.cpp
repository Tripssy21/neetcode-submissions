class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<map<char, int>, string>> vector_map;
        for (int i = 0; i < strs.size(); i++){
            map<char, int> m;
            for(char ch : strs[i])
                m[ch]++;
            
            vector_map.push_back({m, strs[i]});
        }
        // sort(vector_map.begin(), vector_map.end());
        sort(vector_map.begin(), vector_map.end());
        // for (auto &[mp, str] : vector_map) {
        // cout << "{ ";

        //     for (auto &[ch, count] : mp) {
        //         cout << ch << ":" << count << " ";
        //     }

        //     cout << "} -> " << str << endl;
        // }

        vector<vector<string>> result;
        int i = 0;
        while (i < vector_map.size()){
            vector<string> vec;
            int j = i;
            // vec.push_back(vector_map[i].second);
            while(j < vector_map.size() && vector_map[i].first == vector_map[j].first){
                vec.push_back(vector_map[j].second);
                j++;
            }
            result.push_back(vec);
            i = j;
        }
        return result;
    }
};
