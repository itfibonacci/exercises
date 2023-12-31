"""
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".

"""


def substrings_with_no_repeated_chs(string):
	count = 0
	window_start = 0
	window_end = 2

	while window_end < len(string):
		if (string[window_start] != string[window_start + 1] and string[window_start + 1] != string[window_end] and string[window_start] != string[window_end]):
			count += 1
		window_start += 1
		window_end += 1	
	return count

print(substrings_with_no_repeated_chs("aababcabc"))
print(substrings_with_no_repeated_chs("xyzzaz"))

# Let's change the problem statement. We accept k and string. Find number of k length substrings with no repeated characters. k >= 2 # looks correct hopefully

def substrings_with_no_repeated_chs(k, string):
	result = []
	current_letters = set()
	window_start = 0
	window_end = k - 1

	while window_end < len(string):
		for i in range(len(string[window_start:window_end+1])):
			if (string[window_start:window_end+1][i] not in current_letters):
				current_letters.add(string[window_start:window_end+1][i])
			else:
				result.append(string[window_start:window_end+1])
				break
		current_letters = set()
		window_start += 1
		window_end += 1

	return (len(string) - k + 1) - len(result)

print(substrings_with_no_repeated_chs(3, "aababcabc"))
print(substrings_with_no_repeated_chs(4, "aababcabc"))
print(substrings_with_no_repeated_chs(4, "abcd"))
print(substrings_with_no_repeated_chs(4, "abcdabcd"))
