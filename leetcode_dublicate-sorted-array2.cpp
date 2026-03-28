// Example 1:

// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i=1; i<nums.size(); i++){
            if(j ==1 || nums[i] != nums[j-2]){
                nums[j++]= nums[i];
            }
        }
        return j;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = sol.removeDuplicates(nums);
    
    cout << "The new length is: " << k << endl;
    cout << "The modified array: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}