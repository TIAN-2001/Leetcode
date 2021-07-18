// redo: 7:35pm - 7:52 pm (1st version done)

struct compare{
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = -1 * pow(2,31) + 1;
        
        unordered_map<int, vector<vector<int>>> graph = constrcuctGraph(times);
        
        priority_queue<vector<int>, vector<vector<int>>, compare> pq; // min heap
        pq.push({0,k});
        
        vector<int> resolved(n+1, -1);
        
        while(!pq.empty()){
            int w = pq.top()[0];
            int v = pq.top()[1];
            pq.pop();
            
            if(resolved[v] != -1){
                continue;
            }
            resolved[v] = w;
            
            for(auto tmp : graph[v]){
                int w2 = tmp[1];
                int v2 = tmp[0];
                if(resolved[v2] != -1){
                    continue;
                } else {
                    pq.push({w+w2, v2});
                }                
            }  
        }
        
        for(int i = 1; i < n+1; ++i){
            if(resolved[i] == -1){
                return -1;
            }
            if(res < resolved[i]){
                res = resolved[i];
            }
        }
        
        return res;
    }
    
private:
    unordered_map<int, vector<vector<int>>> constrcuctGraph(vector<vector<int>>& times){
        unordered_map<int, vector<vector<int>>> graph;
        for(int i = 0; i < times.size(); ++i){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u].push_back({v,w});
        }
        
        return graph;
    }
};