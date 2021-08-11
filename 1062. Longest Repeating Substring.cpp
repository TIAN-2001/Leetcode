class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int l = 0;
        int r = s.length()-1;
        
        while(l < r){
            int mid = l + (r-l+1)/2;
            if(isValid(s, mid)){
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        
        return l;
        
    }
    
private:
    bool isValid(string s, int length){
        unordered_set<string> sett;
        for(int i = 0; i < s.length() - length + 1;++i){
            // int j = i + length - 1;
            string tmp = s.substr(i,length);
            if(sett.find(tmp) != sett.end()){
                return true;
            }
            sett.insert(tmp);
        }
        
        return false;        
    }
};