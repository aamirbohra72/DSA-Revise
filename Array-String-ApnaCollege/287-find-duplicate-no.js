

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            // Phase 1: Finding the intersection point of the two runners.
            int slow = nums[0];
            int fast = nums[0];
            
            do {
                slow = nums[slow];
                fast = nums[nums[fast]];
            } while (slow != fast);
            
            // Phase 2: Finding the entrance to the cycle.
            slow = nums[0];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            
            return slow;
        }
    };
    
    
// -------------------------Not understand--------------------------------
// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3    