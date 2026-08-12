class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int num : nums)
            hashMap[num]++;
        vector<pair<int, int>> vec(hashMap.begin(), hashMap.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; 
        });
        vector<int> result;
        for(int i = 0; i < k && i < vec.size(); i++){
            result.push_back(vec[i].first);
        }
        return result;
    }
};
