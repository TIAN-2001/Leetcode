class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> res(m, vector<int>(n,0));
        vector<vector<bool>> v(m, vector<bool>(n,0));
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    v[i][j] = 1;
                }
            }
        }
                
        int cost = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                pair<int, int> tmp = q.front();
                q.pop();
                int l = tmp.first;
                int r = tmp.second;
                if(mat[l][r] == 1){
                    res[l][r] = cost;
                }
                
                for(int j = 0; j < 4; ++j){
                    int newl = l + dir[j][0];
                    int newr = r + dir[j][1];
                    if(newl < m && newl >= 0 && newr < n && newr >= 0 && !v[newl][newr]){
                        q.push({newl,newr});
                        v[newl][newr] = 1;
                    }
                }
            }
            
            ++ cost;
        }
        
        return res;           
            
    }

private:
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
};