#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // Initializing with a large value, but divided by 2 to prevent potential overflow 
        // when calculating abs(current_sum - target)
        int closet_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < (int)nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                if (abs(current_sum - target) < abs(closet_sum - target)) {
                    closet_sum = current_sum;
                }
                
                if (current_sum < target) {
                    left++;
                } else if (current_sum > target) {
                    right--;
                } else {
                    // Found exact match
                    return current_sum;
                }
            }
        }
        return closet_sum;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    
    int result = sol.threeSumClosest(nums, target);
    
    cout << "The closest sum to " << target << " is: " << result << endl;

    return 0;
}