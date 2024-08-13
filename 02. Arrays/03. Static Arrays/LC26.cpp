/*
LeetCode 26: Remove Duplicates from Sorted Array
*/


/*
Bruteforce approach:

Time complexity: O(n log n) + O(n) = O(n log n)
    O(n log n): O(n) comes from iterating over all the elements of nums vector. 
                O(log n) comes from inserting the elements to the set. 
                    The set is implemented by balanced binary search tree.
                    Set stores only unique elements in ascending order.
    O(n): This O(n) comes from iterating over all the elements in the set to
	      put the elements back in the nums vector at right positions.

    The dominant factor between these two is O(n log n). So, the total time complexity
    of this function is O(n log n). 

Space complexity: O(n)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> result;
        for (auto element : nums) {
            result.insert(element);
        }
        int i = 0;
        for (auto& element : result) {
            nums[i] = element;
            i++;  
        }
        return result.size();
    }
};


/*
Optimal approach:

Time complexity: O(n)
Space complexity: O(1)
    O(1): Because we are modifying the nums vector in-place. So, no extra space needed.	
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueposindex = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[uniqueposindex] = nums[i];
                uniqueposindex++;
            }
        }
        return uniqueposindex;
    }
};
