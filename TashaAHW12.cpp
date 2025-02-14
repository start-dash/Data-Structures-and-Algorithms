/*
 Given an array positive numbers, find the maximum sum of a subsequence such that no two numbers in the sequence are adjacent in the array.
 Your algorithm should be O(n) where n is the number of elements in the array.
 Assume at least one element is present in the array
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;
using std::vector;

int maxSum(vector<int>& nums) {
	int number = nums.size();
	if (number == 1) {
		return nums[0];
	}

	int memory[number];
	
	memory[0] = nums[0];
	memory[1] = max(nums[0], nums[1]);

	for (int i = 0; i < number; i++) {
		memory[i + 2] = max(memory[i + 1], memory[i] + nums[i + 2]);
		memory[i + 2] = max(memory[i + 2], nums[i + 2]);
	}

	return memory[number - 1];


}


int main() {
	vector<int> nums;
	// Test 1
	nums = {75, 105, 120, 75, 90, 135};
	cout << maxSum(nums) << endl; //330
	// Test 2
	nums = {5, 5, 10, 100, 10, 5};
	cout << maxSum(nums) << endl; //110
	// Test 3
	nums = {3, 2, 7, 10};
	cout << maxSum(nums) << endl; //13
	// Test 4
	nums = {3, 2, 5, 10, 7};
	cout << maxSum(nums) << endl; //15
}

