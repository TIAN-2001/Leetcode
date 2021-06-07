class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int sz = t.size();
        vector<int> res(sz,0);
        stack<int> ind;
        
        for(int i = sz-1; i >= 0; --i){
            if(ind.empty()){
                res[i] = 0;
                ind.push(i);
            } else{
                while(!ind.empty() && t[ind.top()] <= t[i]){
                    ind.pop();
                }
                if(ind.empty()){
                    res[i] = 0;
                    ind.push(i);
                } else{
                    res[i] = ind.top() - i;
                    ind.push(i);                    
                }

            }
        }
        
        return res;
    }
};

