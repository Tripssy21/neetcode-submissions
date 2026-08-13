class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> hashSet;
        for(int num: nums)
            hashSet.insert(num);

        int result = 0;
        for(int num : hashSet){
            if(hashSet.contains(num + 1))
                continue;
            int count = 1;
            while(hashSet.contains(num - count))
                count++;
            result = max(result, count);
        }
        return result;
    }
};
