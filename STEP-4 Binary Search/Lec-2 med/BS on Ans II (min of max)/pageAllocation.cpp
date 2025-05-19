/*
Given an array nums of n integers, where nums[i] represents the 
number of pages in the i-th book, and an integer m representing 
the number of students, allocate all the books to the students so
 that each student gets at least one book, each book is allocated
  to only one student, and the allocation is contiguous.



Allocate the books to m students in such a way that the 
maximum number of pages assigned to a student is minimized.

If the allocation of books is not possible, return -1
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Function to check if it is possible to allocate books to 'm' students
    such that no student gets more than 'maxPages' pages.
*/
bool isPossible(vector<int>& nums, int m, int maxPages) {
    int students = 1;         // At least one student gets books
    int currentPages = 0;     // Pages allocated to the current student

    for (int pages : nums) {
        // If a single book has more pages than maxPages, allocation not possible
        if (pages > maxPages) return false;

        // If adding current book keeps us within the maxPages limit
        if (currentPages + pages <= maxPages) {
            currentPages += pages;
        } else {
            // Assign this book to the next student
            students++;
            currentPages = pages;

            // If number of students exceeds limit, return false
            if (students > m)
                return false; // means we need to dec students
                                // so we incrase the threshold : left=mid+1
        }
    }

    return true; // Allocation successful within limits
}

/*
    Main function to find the minimum possible maximum number of pages
    that can be assigned to any student.
*/
int allocatePages(vector<int>& nums, int m) {
    int n = nums.size();

    // If there are fewer books than students, allocation is impossible
    if (m > n) return -1;

    // Binary search range
    int left = *max_element(nums.begin(), nums.end());  // Minimum possible maxPages
    int right = accumulate(nums.begin(), nums.end(), 0); // Maximum possible maxPages (one student gets all books)
    int result = -1; // Store the best (minimum) maxPages found

    while (left <= right) {
        int mid = left + (right - left) / 2; // Try this as maxPages

        if (isPossible(nums, m, mid)) {
            result = mid;       // Valid allocation found, try smaller maxPages
            right = mid - 1;
        } else {
            left = mid + 1;     // Not possible, need to increase maxPages
        }
    }

    return result; // Final answer: minimum possible maxPages
}
/*
kaam student means zada page threshold tha
*/
int main() {
    // Number of pages in each book
    vector<int> nums = {12, 34, 67, 90};
    
    // Number of students
    int m = 2;
    
    // Function call to get minimum possible maximum pages
    int minMaxPages = allocatePages(nums, m);

    // Output the result
    cout << "Minimum possible maximum pages = " << minMaxPages << endl;

    return 0;
}
