/*
Leetcode 1929: Concatenation of Array
*/

/*
Bruteforce approach:

Time complexity: O(n)
Space complexity: O(n) 
*/

vector<int> getConcatenation(vector<int>& nums) {
    vector <int> ans;
    for (auto element : nums) {
        ans.push_back(element);
    }
    for (auto element : nums) {
        ans.push_back(element);
    }
    return ans;
}

/*
Optimized approach:

Time complexity: O(n)
Space complexity: O(1)
*/

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n; i++) {
        nums.push_back(nums[i]);
    }
    return nums;
}