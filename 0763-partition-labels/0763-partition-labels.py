class Solution:
    def partitionLabels(self, s):
        last = {}

        for i in range(len(s)):
            last[s[i]] = i
        result = []
        start = 0
        end = 0

        for i in range(len(s)):
            end = max(end, last[s[i]])
            if i == end:
                result.append(end - start + 1)
                start = i + 1

        return result