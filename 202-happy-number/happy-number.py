class Solution:
    def isHappy(self, n: int) -> bool:
        s = set()

        while n != 1:
            if n in s:
                return False

            s.add(n)

            total = 0
            for digit in str(n):
                total += int(digit) ** 2

            n = total

        return True