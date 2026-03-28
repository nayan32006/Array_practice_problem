#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // 1. चौड़ाई निकालें
            int width = right - left;
            
            // 2. ऊँचाई निकालें (जो छोटा खंभा है)
            int h = min(height[left], height[right]);
            
            // 3. एरिया कैलकुलेट करें और मैक्सिमम सेव करें
            int current_area = width * h;
            max_water = max(max_water, current_area);
            
            // 4. छोटे खंभे को हिलाएं
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Maximum water container can store: " << sol.maxArea(height) << endl;
    
    return 0;
}