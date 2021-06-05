class Solution {
public:    
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        if(iv.size() == 0)
            return vector<vector<int>> {{}};
        
        sort(iv.begin(), iv.end(), [](vector<int> a, vector<int> b){return a[0]< b[0];});

        vector<vector<int>> res;
        int sz = iv.size();
        res.push_back(iv[0]);
        
        for(int i = 1; i < sz; ++i){
            if(res.back()[1] < iv[i][0])
                res.push_back({iv[i][0], iv[i][1]});
            else
                res.back()[1] = max(iv[i][1], res.back()[1]);
        }

        
        return res;
    }
    

    
};