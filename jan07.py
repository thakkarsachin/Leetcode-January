'''
Given a string s, find the length of the longest substring without repeating characters.
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        back, fwd = 0, 0
        present = set()
        current = ""
        global_max = 0
        while(fwd < len(s)) : 
            if s[fwd] not in present :
                current = current + s[fwd]
                present.add(s[fwd])
                fwd = fwd + 1
            else :
                global_max = max(global_max, len(current))
                back = back + 1
                fwd = back
                current = ""
                present = set()
        global_max = max(global_max, len(current))
        return global_max