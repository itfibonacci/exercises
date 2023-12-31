"""
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
"""

def contains_duplicate(nums):
	frequency = {}

	for num in nums:
		if num in frequency:
			return True
		else:
			frequency[num] = 1
	return False

def contains_duplicate(nums, seen=None):
	if len(nums) == 0:
		return False
	
	if not seen:
		seen = set()

	if nums[0] in seen:
		return True
	else:
		seen.add(nums[0])
		return contains_duplicate(nums[1:], seen)

print(contains_duplicate([1,1,1,3,3,4,3,2,4,2]))
print(contains_duplicate([1,2,3,4]))
print(contains_duplicate([1,2,3,1]))
