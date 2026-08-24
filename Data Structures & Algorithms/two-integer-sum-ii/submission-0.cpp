class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // vector<int> result;
        int last = numbers.size() - 1;
        int first = 0;
        while (first < last){
            if(numbers[first] + numbers[last] == target)
                return {first + 1, last + 1};
            else if (numbers[first] + numbers[last] > target)   
                last--;
            else
                first++;
        }
        return {};
    }
};
