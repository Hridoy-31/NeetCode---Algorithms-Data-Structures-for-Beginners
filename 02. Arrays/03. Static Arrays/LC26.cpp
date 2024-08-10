/*
LeetCode 26: Remove Duplicates from Sorted Array

Time complexity: O(n)
Space complexity: O(1)
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
