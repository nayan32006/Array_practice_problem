#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int maxLen = 0;

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int uniqueCount = 0;
            int countAtLeastK = 0;

            while (right < n) {
                int rightIdx = s[right] - 'a';
                if (freq[rightIdx] == 0) uniqueCount++;
                freq[rightIdx]++;
                if (freq[rightIdx] == k) countAtLeastK++;
                right++;

                while (uniqueCount > targetUnique) {
                    int leftIdx = s[left] - 'a';
                    if (freq[leftIdx] == k) countAtLeastK--;
                    freq[leftIdx]--;
                    if (freq[leftIdx] == 0) uniqueCount--;
                    left++;
                }

                if (uniqueCount == targetUnique && uniqueCount == countAtLeastK) {
                    maxLen = max(maxLen, right - left);
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s1 = "aaabb";
    int k1 = 3;
    cout << sol.longestSubstring(s1, k1) << endl;

    string s2 = "ababbc";
    int k2 = 2;
    cout << sol.longestSubstring(s2, k2) << endl;

    return 0;
}