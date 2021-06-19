// time: 12:03 - 12:08 - 12:13 - 12:23
class Solution {
public:
    string removeDuplicates(string s) {
        int len = s.length();
        if (len == 1 || len == 0)
            return s;
        if(len == 2 && s[0] == s[1])
            return "";
        
        string res;
        int i = 0, j = 1;
        
        while(j < len){
            if(s[i] == s[j]){
                s[i] = 'A';
                s[j] = 'A';
                if(i > 0){
                    while(i >= 0 && s[i] == 'A')
                        --i;
                    if(i == -1){
                        i = j + 1;
                        j += 2;
                    } else                        
                        ++j;
                } else{
                    i = j + 1;
                    j += 2;
                }  
            } else {
                i = j;
                ++j;
            }
        }
        
        
        for(int i = 0; i < len; ++i){
            if(s[i] != 'A')
                res.push_back(s[i]);
        }
        
        return res;
    }
};