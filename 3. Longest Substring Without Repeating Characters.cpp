// sliding window / two pointers
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if(s.length() == 0)
            return res;
        
        int left = 0;
        int right = 0;
        unordered_map<char,int> mp;
        char c;
        
        while(right < s.length()){
            c = s[right];
            mp[c] += 1;
            if(mp[c] == 1){
                res = max(res, right - left + 1);             
            } else {
                while(mp[c] > 1){
                    char cl = s[left];
                    --mp[cl];
                    ++left;
                }       
            }
            ++right;
        }
        
        return res;
        
    }
};