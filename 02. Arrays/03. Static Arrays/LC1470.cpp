/*
LeetCode 1470 : Shuffle the Array
*/


/*
Bruteforce approach:

Time complexity: O(n)
Space complexity: O(n)
*/

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> result(2 * n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        result[j] = nums[i];
        j += 2;
    }
    j = 1;
    for (int i = n; i < 2 * n; i++) {
        result[j] = nums[i];
        j += 2;
    }
    return result;
}


/*
Optimal approach: (Bit Manipulation)

Time complexity : O(n)
Space complexity: O(1)
*/

vector<int> shuffle(vector<int>& nums, int n) {

    // Packing two elements into one.
    for (int i=0; i<n; i++) {
        // Left-shift nums[i] to 10 bits for making room for the element which will be the adjacent y-value.
        // Left-shift by 10 bits means that multiplying with (2^10).
        // Why 10 bits ? Because the constraints specifies that the largest value can be 1000 (10^3).
        // Now, (2^10) or 10 bits can hold maximum value 1024. So, we are creating space of 10 bits beside
        // the x-value to store the adjacent y-value. By this way we make x-value and y-value as a packet
        // in a single element. 
        nums[i] = nums[i] << 10;
        // This bitwise OR operator puts the appropriate y-value in the created space from the above line 
        // with the x-value.
        nums[i] = nums[i] | nums[i+n];
    }
    
    // Unpacking and rearranging
    int index = 2*n - 1;
    for (int i=n-1; i>=0; i--) {
        // The lower 10 bits (which represent y) are extracted by performing a bitwise AND with 1023.
        int y = nums[i] & 1023;
        // The higher bits (which represent x) are extracted by right-shifting the value by 10 bits. This retrieves the original nums[i].
        int x = nums[i] >> 10;

        nums[index] = y;
        nums[index-1] = x;

        index -= 2;
    }

    return nums;
}