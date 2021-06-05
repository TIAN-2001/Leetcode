class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            if(i == 0 || nums[j] != nums[i-1]){
                nums[i] = nums[j];
                ++i;
                ++j;
            } else{
                ++j;
            }
        }
        
        return i;
    }
};