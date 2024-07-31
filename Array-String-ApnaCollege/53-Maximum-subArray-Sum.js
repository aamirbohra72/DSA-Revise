class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int maxSum = INT_MIN;
            int currentSum = 0;
            // int n = nums.size();
            for(int i=0; i<nums.size(); i++){
                    currentSum += nums[i];
                if(currentSum > maxSum){
                    maxSum = currentSum;
                }
                if(currentSum<0){
                    currentSum = 0;
                }
                // maxSum = max(maxSum, currentSum);
            }
            return maxSum;
            
        }
    };

    // -----------------kadanes algorithm -------------------

//     maxSum = INT_MIN, currentSum = 0
// Iterate through nums:
// i = 0, nums[0] = -2, currentSum = -2, maxSum = -2
// i = 1, nums[1] = 1, currentSum = -1, maxSum = 1
// i = 2, nums[2] = -3, currentSum = -4, reset currentSum = 0
// i = 3, nums[3] = 4, currentSum = 4, maxSum = 4
// i = 4, nums[4] = -1, currentSum = 3, maxSum = 4
// i = 5, nums[5] = 2, currentSum = 5, maxSum = 5
// i = 6, nums[6] = 1, currentSum = 6, maxSum = 6
// i = 7, nums[7] = -5, currentSum = 1, maxSum = 6
// i = 8, nums[8] = 4, currentSum = 5, maxSum = 6
// Result: maxSum = 6