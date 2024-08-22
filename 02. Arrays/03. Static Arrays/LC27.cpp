/*
LeetCode 27: Remove Element
*/

/*
Bruteforce approach:

Time complexity: O(n log n)
    O(n log n) comes from the sort() operation which is implemented by a hybrid
    algorithm called Timsort in C++.
Space complexity: O(1)
    Because of the sort() operation that sorts the vector in-place, no extra space
    is needed.
*/

int removeElement(vector<int> &nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            nums[i] = INT_MAX;
        }
        else {
            count++;
        }
    }
    sort(nums.begin(), nums.end());
    return count;
}


/*
Optimal approach:

Time complexity: O(n)
Space complexity: O(1)
*/

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}