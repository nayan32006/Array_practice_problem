#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // 1. एरे को सॉर्ट करें
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // i के लिए डुप्लीकेट्स छोड़ें
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // j के लिए डुप्लीकेट्स छोड़ें
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Two Pointers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Integer overflow से बचने के लिए long long का उपयोग
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // डुप्लीकेट्स छोड़ने के लिए left और right को बढ़ाएं
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Unique Quadruplets are:" << endl;
    for (auto quad : result) {
        cout << "[ ";
        for (int x : quad) cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}