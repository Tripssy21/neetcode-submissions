class Solution {
public:
    bool isPalindrome(string s) {
        string new_s = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] > 64 & s[i] < 91)
                new_s += (char)(s[i] + 32);
            else if((s[i] > 47 && s[i] < 57) ||(s[i] > 96 && s[i] < 123))
                new_s += s[i];
            
        cout << new_s << endl;
        }
        for(int i = 0; i < new_s.length(); i++){
            if(tolower(new_s[i]) != tolower(new_s[new_s.length() - 1 - i]))
                return false;
        }
        return true;
    }
};
