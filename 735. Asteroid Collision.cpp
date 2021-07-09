class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int sz = ast.size();
        stack<int> s;
        
        for(int i = 0; i < sz; ++i){
            if(s.empty()){
                s.push(ast[i]);
            } else if(s.top() < 0) {
                s.push(ast[i]);
            } else if(ast[i] > 0){
                s.push(ast[i]);
            } else if(ast[i] < 0 && -1*ast[i] < s.top()){
                continue;
            } else if(ast[i] < 0 && -1*ast[i] == s.top()){
                s.pop();
            } else { //ast[i] < 0 && -1*ast[i] > s.top()
                while(!s.empty() && s.top()>0 && -1*ast[i] > s.top()){
                    s.pop();
                }
                if(s.empty() || s.top()<0){
                    s.push(ast[i]);
                } else if(-1*ast[i] == s.top()){
                    s.pop();
                } else {
                    continue;
                }
            }
        }
        
        
        vector<int> res;
        int sz2 = s.size();
        for(int i = 0; i < sz2; ++i){
            res.insert(res.begin(),s.top());
            s.pop();
        }
        
        return res;
    }
};