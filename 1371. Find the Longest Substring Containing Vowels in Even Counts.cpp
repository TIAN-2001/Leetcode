// state: a e i o u
//        0 1 0 0 0 // 1 means odd, 0 means even or vice versa
// two preString has to share the same state then the substring (PreString2 - 
//     Prestring1) will be the string we want. 
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0;
        int state = 0;
        
        unordered_map<int, int> seen; // key: state, val: the first index we find this state
        
        // similar to putting {0,1} in LC 560. Subarray Sum Equals K at beginning
        // val = -1 is for convenience of calculating length. key = 0 means a "".
        seen[0] = -1; 
        
        unordered_map<char, int> vowel = {{'a',1}, {'e',2}, {'i',4}, {'o',8}, {'u',16}};
        
        for(int i = 0; i < s.length(); ++i){
            char ch = s[i];
            auto itv = vowel.find(ch);
            if(itv != vowel.end()){
                state ^= itv -> second;
            }
            auto its = seen.find(state);
            if(its != seen.end()) {
                res = max(res, i - its->second);
            } else {
                seen[state] = i;
            }            
        }
        
        return res;
        
    }
};