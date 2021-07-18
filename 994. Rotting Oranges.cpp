// 4:48 pm - 5:53 pm (think) - 6:07 pm(done, first version)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalOrg = 0;
        int rotOrg = 0;
        
        vector<vector<int>> v(m, vector<int>(n,0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0){
                    ++totalOrg;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                    v[i][j] = 1;
                    ++rotOrg;
                }
            }
        }
        
        if(totalOrg == 0){
            return 0;
        }

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        int cnt = -1;
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0; i < sz; ++i){
                pair<int, int> tmp = q.front();
                q.pop();
                int r = tmp.first;
                int c = tmp.second;
                
                for(int j = 0; j < 4; ++j){
                    int newr = r + dir[j][0];
                    int newc = c + dir[j][1];
                    
                    if(newr < m && newr >= 0 && newc < n && newc >=0 && !v[newr][newc] && grid[newr][newc] == 1){
                        q.push({newr, newc});
                        v[newr][newc] = 1;
                        grid[newr][newc] = 2;
                        ++rotOrg;
                    }
                }
            }
            
            ++cnt;                
        }
        
        if(rotOrg == totalOrg){
            return cnt;
        } else {
            return -1;
        }
    }
};