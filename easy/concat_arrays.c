/* 
Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize);

int main() {
	int arr1[] = {1, 15, 2, 3};
	int size = 8;
	int *concat = getConcatenation(arr1, 4, &size);

	for (int i = 0; i < size; i++) {
		printf("%d, ", concat[i]);
	}
}

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
	int *ans = (int *) malloc(sizeof(int) * (*returnSize));

	memcpy(ans, nums, sizeof(int) * numsSize);
	memcpy(ans + numsSize, nums, sizeof(int) * numsSize);

	return ans;
}
