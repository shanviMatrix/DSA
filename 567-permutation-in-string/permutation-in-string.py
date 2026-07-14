class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter

        length = len(s1)

        target = Counter(s1)
        window = Counter(s2[:length])

        if target == window:
            return True

        for i in range(length, len(s2)):

            window[s2[i]] += 1

            window[s2[i - length]] -= 1

            if window[s2[i - length]] == 0:
                del window[s2[i - length]]

            if target == window:
                return True

        return False