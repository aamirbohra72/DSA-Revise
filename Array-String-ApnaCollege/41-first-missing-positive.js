#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Replace non-positive numbers and numbers larger than n with n + 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }
        
        // Step 2: Place each number in its correct position
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 3: Find the first missing positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};


// -------------------------------------------

// Test Case 1
// Input: nums = [3, 4, -1, 1]

// Step-by-Step Explanation:

// Replace out-of-range elements:

// After this step, the array becomes [3, 4, -1, 1] because the elements are already within the range [1, n] where n is 4.
// Placing elements in correct positions:

// For i = 0: nums[0] = 3, place 3 at the position nums[2]. Swap nums[0] and nums[2]. Array becomes [-1, 4, 3, 1].
// For i = 0 again: nums[0] = -1, it's out of range, move to next index.
// For i = 1: nums[1] = 4, place 4 at the position nums[3]. Swap nums[1] and nums[3]. Array becomes [-1, 1, 3, 4].
// For i = 1 again: nums[1] = 1, place 1 at the position nums[0]. Swap nums[1] and nums[0]. Array becomes [1, -1, 3, 4].
// For i = 2: nums[2] = 3, it's already in the correct position.
// For i = 3: nums[3] = 4, it's already in the correct position.
// Find the missing positive integer:

// nums[0] = 1, correct.
// nums[1] = -1, incorrect (should be 2).
// Therefore, the smallest missing positive integer is 2.
// Output: 2

// Test Case 2
// Input: nums = [7, 8, 9, 11, 12]

// Step-by-Step Explanation:

// Replace out-of-range elements:

// After this step, the array becomes [7, 8, 9, 11, 12] because all elements are greater than n (which is 5), so they are effectively out-of-range.
// Placing elements in correct positions:

// For i = 0: nums[0] = 7, it's out of range, move to next index.
// For i = 1: nums[1] = 8, it's out of range, move to next index.
// For i = 2: nums[2] = 9, it's out of range, move to next index.
// For i = 3: nums[3] = 11, it's out of range, move to next index.
// For i = 4: nums[4] = 12, it's out of range, move to next index.
// Find the missing positive integer:

// nums[0] != 1, therefore the smallest missing positive integer is 1.
// Output: 1

// Test Case 3
// Input: nums = [1, 2, 0]

// Step-by-Step Explanation:

// Replace out-of-range elements:

// After this step, the array becomes [1, 2, 0] because only 0 is out of range, which can be replaced with n + 1 (i.e., 4). But it doesn't matter in this case since 0 doesn't affect placement.
// Placing elements in correct positions:

// For i = 0: nums[0] = 1, it's already in the correct position.
// For i = 1: nums[1] = 2, it's already in the correct position.
// For i = 2: nums[2] = 0, it's out of range, move to next index.
// Find the missing positive integer:

// nums[0] = 1, correct.
// nums[1] = 2, correct.
// Therefore, the smallest missing positive integer is 3.
// Output: 3

// By following these steps and using the in-place hashing technique, the algorithm efficiently finds the smallest missing positive integer in O(n) time and O(1) space.