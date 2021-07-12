class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n,0);
        stack<int> s;
        int sz = logs.size();
        int id;
        int t;
        int prev = 0;
        char action[6];
        
        for(auto log : logs){
            sscanf(log.c_str(), "%d:%[a-z]:%d", &id, action, &t);
            //知道要用prev之后还是不会写下面的Logic，拿例子过一遍就写出来了。
            //考虑到所有情况，充要条件。
            if(action[0] == 's'){ 
                if(!s.empty()){
                    res[s.top()] += t - prev;
                }
                s.push(id);
                prev = t;
            } else {
                res[s.top()] += t - prev + 1;
                s.pop();
                prev = t + 1;
            }
        }
        
        return res;
        
    }
};