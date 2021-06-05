class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) // corner case
            return {};        
        sort(nums.begin(),nums.end());
        vector<vector<int>> result = {};
        
        
        // hash
        for (int i=0; i<nums.size()-2; ++i)
        {
            if(i!=0 && nums[i]==nums[i-1]) // skip the same fixed number
                continue;
            unordered_map<int, int> map_;
            
            for(int j=i+1; j<=nums.size()-1; ++j)
            {
                vector<int> res_tmp = {}; 
                auto it = map_.find(-1*nums[i]-nums[j]);
                if (it!=map_.end())
                {
                    res_tmp.push_back(nums[i]);
                    res_tmp.push_back(nums[j]);
                    res_tmp.push_back(nums[it->second]);
                    sort(res_tmp.begin(), res_tmp.end());
                    result.push_back(res_tmp);                    
                    
                }
                else
                    map_[nums[j]] = j;
            }
        }
        set<vector<int>> s {result.begin(),result.end()};
        result.assign(s.begin(), s.end());
        
        return result;
        
//         //two pointer        
//         for (int i=0; i<nums.size()-2; ++i)
//         {
//             if (i!=0 && nums[i]==nums[i-1])
//                 continue;
//             int a_ptr = i+1;
//             int b_ptr = nums.size()-1;                
//             while(a_ptr < b_ptr)
//             {
//                 vector<int> res_tmp = {};                
//                 if (nums[a_ptr] + nums[b_ptr] == -1*nums[i])
//                 {
//                     res_tmp.push_back(nums[i]);
//                     res_tmp.push_back(nums[a_ptr]);
//                     res_tmp.push_back(nums[b_ptr]);
//                     result.push_back(res_tmp);
                    
                    
//                     while (a_ptr < b_ptr && nums[a_ptr] == nums[a_ptr+1])
//                         a_ptr += 1;
//                     a_ptr += 1;
                    
//                     while (a_ptr < b_ptr && nums[b_ptr] == nums[b_ptr-1])
//                         b_ptr -= 1;                 
//                     b_ptr -= 1;
//                 }
//                 else if (nums[a_ptr] + nums[b_ptr] < -1*nums[i])
//                     a_ptr += 1;
//                 else
//                     b_ptr -= 1;
//             }                 
//         }      
//         return result;   
        
        
    }
};