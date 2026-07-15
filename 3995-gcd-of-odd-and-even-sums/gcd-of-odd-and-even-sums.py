class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        odd_sum = n * n
        even_sum = n * (n + 1)

        while even_sum != 0:
            odd_sum, even_sum = even_sum, odd_sum % even_sum

        return odd_sum