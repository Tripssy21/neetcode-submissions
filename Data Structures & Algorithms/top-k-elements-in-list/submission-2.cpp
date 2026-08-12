class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int num : nums)
            hashMap[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, freq] : hashMap) {
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (const int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
