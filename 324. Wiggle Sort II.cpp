class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        
        sort(sorted.begin(), sorted.end());
        
        int sz = sorted.size();
        
        int mid;
        if(sz % 2 == 0){
            mid = sz/2 - 1;    
        } else {
            mid = sz/2;
        }
        
        // put first small half in even indexes
        for(int i = mid, k = 0; i >=0; --i){
            nums[k] = sorted[i];
            k += 2;
        }
        
        // put second big half in odd indexes
        for(int i = sz-1, k = 1; i >= mid+1; --i){
            nums[k] = sorted[i];
            k += 2;
        }        
        
        
    }
};