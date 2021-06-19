// stack
class Solution {
public:
    string removeDuplicates(string s) {
        int len = s.length();
        if (len == 1 || len == 0)
            return s;
        if(len == 2 && s[0] == s[1])
            return "";
        
        stack<char> tmp;
        string res;
        
        tmp.push(s[0]);
        for(int i = 1; i < len; ++i){
            if(!tmp.empty() && s[i] == tmp.top()){
                tmp.pop();
            } else{
                tmp.push(s[i]);
            }              
        }
        
        int sz = tmp.size();
        for(int i = 0; i < sz; ++i){
            res.insert(res.begin(), tmp.top());
            tmp.pop();
        }
            
        return res;
        
        
    }
};