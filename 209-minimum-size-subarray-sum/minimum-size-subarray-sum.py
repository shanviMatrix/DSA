class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        left = 0
        current_sum = 0
        minimum_length = float("inf")

        for right in range(len(nums)):

            current_sum += nums[right]

            while current_sum >= target:

                current_length = right - left + 1

                minimum_length = min(minimum_length, current_length)

                current_sum -= nums[left]
                left += 1

        if minimum_length == float("inf"):
            return 0

        return minimum_length