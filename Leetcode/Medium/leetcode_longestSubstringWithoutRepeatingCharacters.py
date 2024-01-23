'''
Leetcode Medium: 3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0

        left = 0
        result = 0
        latestVisitedIndex = {}

        for right in range(len(s)):
            if s[right] not in latestVisitedIndex:
                result = max(result, right - left + 1)
            else:
                if left > latestVisitedIndex[s[right]]:
                    result = max(result, right - left + 1)
                else:
                    left = latestVisitedIndex[s[right]] + 1
            latestVisitedIndex[s[right]] = right
        return result

'''
# shorter Python code (remove duplicate logics)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        start = result = 0
        seen = dict()

        for i, c in enumerate(s):

            if seen.get(c, -1) >= start:
                start = seen[c] + 1

            result = max(result, i - start + 1)
            seen[c] = i

        return result
'''