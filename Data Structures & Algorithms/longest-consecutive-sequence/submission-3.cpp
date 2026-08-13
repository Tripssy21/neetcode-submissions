class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int, int>> hashMap;
        for(int num : nums){
            if(!hashMap.contains(num))
                hashMap[num] = {num, num};
            if(!hashMap.contains(num - 1) && !hashMap.contains(num + 1))
                hashMap[num] = {num, num};
            else if(!hashMap.contains(num - 1) && hashMap.contains(num + 1)){
                hashMap[num] = {num, max(hashMap[num].second, hashMap[num + 1].second)};
                hashMap[hashMap[num + 1].second] = {num, hashMap[num].second};
            }
            else if (hashMap.contains(num - 1) && !hashMap.contains(num + 1)){
                hashMap[num] = {min(hashMap[num - 1].first, hashMap[num].first), num};
                hashMap[hashMap[num - 1].first] = {hashMap[num].first, num};
            }
            else{
                hashMap[num] = {min(hashMap[num - 1].first, hashMap[num].first), max(hashMap[num].second, hashMap[num + 1].second)}; 
                hashMap[hashMap[num - 1].first] = {hashMap[num].first, hashMap[num].second};
                hashMap[hashMap[num + 1].second] = {hashMap[num].first, hashMap[num].second};
            } 
        }
        int result = 0;
        for(auto& [a, b] : hashMap)
            result = max(result, b.second - b.first + 1);
        return result;
    }
};
