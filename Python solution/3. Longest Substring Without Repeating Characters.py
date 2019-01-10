class Solution1:
    '''
    :author: Rufeer
    :solution: O(n^2)
    :runtime: 812 ms
    '''
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxlen = 0
        for i in range(len(s)):
            ch = {}
            l = 0
            for j in range(i, len(s)):
                if s[j] not in ch:
                    ch[s[j]] = True
                    l = l + 1
                else:
                    break
            if l > maxlen:
                maxlen = l
        return maxlen

class Solution2:
    '''
    :author: Rufeer
    :solution: O(n)
    :runtime: 136 ms
    '''
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxlen = 0
        currentSubstring = ''
        for i in s:
            if i in currentSubstring:
                maxlen = max(len(currentSubstring), maxlen)
                index = currentSubstring.index(i)
                currentSubstring = currentSubstring[index+1:] + i
            else:
                currentSubstring = currentSubstring + i
        return max(maxlen, len(currentSubstring))

class Solution3:
    '''
    :author: Rufeer
    :solution: O(n)
    :runtime: 136 ms
    '''
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxlen = 0
        left = 0
        right = 1
        for i in s[1:]:
            if i in s[left:right]:
                maxlen = max(right - left, maxlen)
                index = s[left:right].index(i)
                left = left + index + 1
            else:
                right = right + 1
        return max(maxlen, right - left)


s = Solution3()
print(s.lengthOfLongestSubstring('abca'))