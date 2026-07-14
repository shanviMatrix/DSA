class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        from collections import Counter

        result = []

        length = len(p)

        target = Counter(p)
        window = Counter(s[:length])

        if target == window:
            result.append(0)

        for i in range(length, len(s)):

            window[s[i]] += 1

            window[s[i - length]] -= 1

            if window[s[i - length]] == 0:
                del window[s[i - length]]

            if window == target:
                result.append(i - length + 1)

        return result