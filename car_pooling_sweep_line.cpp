#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> events;

        for (auto& trip : trips) {
            events.push_back({trip[1], trip[0]});
            events.push_back({trip[2], -trip[0]});
        }

        sort(events.begin(), events.end());

        int current_passengers = 0;
        for (auto& event : events) {
            current_passengers += event.second;
            if (current_passengers > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };
    int capacity = 4;


    bool result = sol.carPooling(trips, capacity);
    cout << "Can complete all trips? " << (result ? "Yes" : "No") << endl;

    return 0;
}