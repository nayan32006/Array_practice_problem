#include <iostream>
#include <set>

using namespace std;

class MyCalendar {
private:
    // Set to store intervals as pairs: {start, end}
    // Set automatically sorts elements based on the 'start' time
    set<pair<int, int>> bookings;

public:
    MyCalendar() {
        // Constructor
    }
    
    bool book(int start, int end) {
        // Step 1: upper_bound find karo jiska start time current 'start' se bada ya equal ho
        auto it = bookings.upper_bound({start, end});

        // Step 2: Check karo ki kya aane wala interval agle interval ke sath overlap karta hai
        if (it != bookings.end()) {
            // it->first matlab next interval ka start time
            if (it->first < end) {
                return false; // Overlap detected with the next interval!
            }
        }

        // Step 3: Check karo ki kya pichle interval ke sath overlap karta hai
        if (it != bookings.begin()) {
            auto prev_it = prev(it);
            // prev_it->second matlab pichle interval ka end time
            if (prev_it->second > start) {
                return false; // Overlap detected with the previous interval!
            }
        }

        // Step 4: Koi overlap nahi hai, toh interval insert kar do
        bookings.insert({start, end});
        return true;
    }
};

int main() {
    MyCalendar myCalendar;
    
    cout << "book(10, 20): " << (myCalendar.book(10, 20) ? "True" : "False") << " (Expected: True)" << endl;
    cout << "book(15, 25): " << (myCalendar.book(15, 25) ? "True" : "False") << " (Expected: False - Overlap)" << endl;
    cout << "book(20, 30): " << (myCalendar.book(20, 30) ? "True" : "False") << " (Expected: True)" << endl;

    return 0;
}