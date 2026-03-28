#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for(int x : nums1) merged.push_back(x);
        for(int x : nums2) merged.push_back(x);

        sort(merged.begin(),merged.end());
        int n= merged.size();

        if(n % 2 != 0){
            return (double) merged[n / 2];

        } else {
            return  (merged[n / 2 -1] +merged[n/2])/2.0;
        }
        
    }
};

int main() {
    Solution sol; // क्लास का ऑब्जेक्ट बनाया
    
    // टेस्ट के लिए डेटा
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    
    // फंक्शन को कॉल किया और रिजल्ट प्रिंट किया
    double result = sol.findMedianSortedArrays(v1, v2);
    cout << "Median is: " << result << endl;

    return 0;
}

