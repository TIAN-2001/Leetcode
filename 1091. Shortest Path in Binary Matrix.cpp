// 4:57 pm -> 4:59 pm(think) -> 5:07（1st version of code, done）
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0] != 0 || grid[m-1][n-1] != 0)
            return -1;
                   
        vector<vector<bool>> v(m, vector<bool>(n,0));
        queue<pair<int, int>> q;
        
        q.push({0,0});
        v[0][0] = 1;
        
        int cost = 1;
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,1}, {-1,-1}, {1,1}, {1,-1}};
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0; i < sz; ++i){
                pair<int, int>tmp = q.front();
                q.pop();
                int r = tmp.first;
                int c = tmp.second;
                
                if(r == m-1 && c == n-1){
                    return cost;
                }
                
                for(int j = 0; j < 8; ++j){
                    int newr = r + dir[j][0];
                    int newc = c + dir[j][1];
                    if(newr < m && newr >= 0 && newc < n && newc >= 0 && !v[newr][newc] && grid[newr][newc] == 0){
                        v[newr][newc] = 1;
                        q.push({newr, newc});
                    }
                }
            }
            
            ++cost;
        }
        
        return -1; // if we do not return above, then no answer, return -1, another usual trick
    }
};