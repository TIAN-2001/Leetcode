class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        
        for(int i = 0; i < s.length(); ++i){
            if(!p.empty() && check(p.top(), s[i])){
                p.pop();
            } else {
                p.push(s[i]);
            }
        }
        
        
        if(p.empty())
            return true;
        else
            return false;
    }
    
private:
    bool check(char a, char b){
        if((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')){
            return true;
        } else {
            return false;
        }
    }
};