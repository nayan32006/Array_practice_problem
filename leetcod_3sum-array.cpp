// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// code::::----


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end()) ;
        vector<vector<int>> res;
        int n= nums.size();


        for(int i=0; i<n - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int j= i+1 ,k=j-1 ;

            while(j < k){
                int sum= nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j <k && nums[j] == nums[j-1])
                         j++;

                } else if(sum < 0){
                    j++;
                }else {
                    k--;
                }
            }
        }
        return res;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    // The function returns a vector of vectors, not an int
    vector<vector<int>> result = sol.threeSum(nums);
    
    cout << "Unique triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i == triplet.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    
    return 0;
}

