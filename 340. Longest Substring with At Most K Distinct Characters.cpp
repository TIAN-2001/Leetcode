class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length() == 0)
            return 0;
        
        int left = 0;
        int right = 0;
        unordered_map<char, int> mp;
        int res = 0;
        
        while(right < s.length()){
            char c = s[right];
            mp[c] += 1;
            
            if(mp.size() <= k) {
                res = max(res, right - left + 1);
            } else {
                while(mp.size() > k){
                    char cl = s[left];
                    mp[cl] -= 1;
                    if(mp[cl] == 0){
                        mp.erase(cl);
                    }                        
                    ++left;
                }
            }
            
            ++right;
        }
        
        return res;
            
    }
};