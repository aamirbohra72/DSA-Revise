class Solution {
    public:
    
        int kadane(vector<int>& nums){
            
            int currentsum = 0;
            int maxsum = INT_MIN;
            for(int i=0; i<nums.size(); i++){
                currentsum += nums[i];
                if(currentsum > maxsum){
                    maxsum = currentsum;
                }
                if(currentsum < 0){
                    currentsum = 0;
                }
            }
            return maxsum;
    
        }
    
        int maxSubarraySumCircular(vector<int>& nums) {
            int wrapsum;
            int nonwrapsum;
    
            nonwrapsum = kadane(nums);
    
            int totalsum = 0 ;
            for(int i=0;i<nums.size();i++){
                totalsum +=nums[i];
                nums[i] = -nums[i];
            }
            wrapsum = totalsum + kadane(nums);
    
             if (wrapsum == 0) {                // there is a catch 
                return nonwrapsum;
            }
    
            return max(wrapsum, nonwrapsum);
    
    
        
            
        }
    };


    // -----------------------------------------------------