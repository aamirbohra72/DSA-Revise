class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<pair<int,int>>twoSumIndex;
    
            for(int i=0; i<nums.size(); i++){
                  twoSumIndex.push_back({nums[i], i});
            }
    
            sort(twoSumIndex.begin(), twoSumIndex.end());
    
            int low = 0 ;
            // int n = nums.size();
            int high = nums.size() - 1;
            
            while(low < high){
                int sum = twoSumIndex[low].first + twoSumIndex[high].first;
                if(sum == target){
                    return {twoSumIndex[low].second , twoSumIndex[high].second};
                }else if(sum < target){
                    low++;
                }else{
                    high--;
                }
            }
            return {};        //return an empty vector if no solution is found;
            
        }
    };

    // -----------------------------------

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 