class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zero_count = 0;
        for(int num: nums){
            if(num)
                prod *= num;
            if(!num)
                zero_count++;
        }
        vector<int> result;
        for(int num: nums){
            if(zero_count > 1)
                result.push_back(0);
            else if (zero_count){
                if(!num)
                    result.push_back(prod);
                else
                    result.push_back(0);
            }
            else
                result.push_back(prod / num);
        }
        return result;
    }
};
