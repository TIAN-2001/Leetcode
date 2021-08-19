class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0;
        int r = row*col-1;
        
        while(l < r){
            int mid = l + (r-l+1)/2;
            if(isValid(mid, row, col, cells)){
                l = mid;
                // printf("true\n");
            } else {
                r = mid - 1;
                // printf("false\n");
            }
        }
        
        return l+1;
    }
    
private:
    bool isValid(int mid,int row, int col, vector<vector<int>>& cells){
        vector<vector<int>> graph(row+1, vector<int>(col+1,0));
        for(int i = 0; i <= mid; ++i){
            int waterRow = cells[i][0];
            int waterCol = cells[i][1];
            graph[waterRow][waterCol] = 1;
        }
        
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            
        queue<pair<int,int>> q;
        vector<vector<int>> v(row+1, vector<int>(col+1,0));
        
        for(int i = 1; i <= col; ++i){
            if(graph[1][i] == 0){
                q.push({1,i});
                v[1][i] = 1;
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0; i < sz; ++i){
                pair<int,int> tmp = q.front();
                q.pop();
                if(tmp.first == row){
                    return true;
                }
                
                int curRow = tmp.first;
                int curCol = tmp.second;
                
                for(int j = 0; j < 4; ++j){
                    int newRow = curRow + dir[j][0];
                    int newCol = curCol + dir[j][1];
                    if(newRow <= row && newRow >= 1 && newCol <= col && newCol >= 1 && v[newRow][newCol] == 0 && graph[newRow][newCol] == 0){
                        q.push({newRow, newCol});
                        v[newRow][newCol] = 1;
                    }
                }
            }
        }
        
        return false;
    }
};









