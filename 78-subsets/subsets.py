class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        result = []

        def backtrack(index, current):

            if index == len(nums):
                result.append(current[:])
                return

            # Take the current element
            current.append(nums[index])
            backtrack(index + 1, current)

            # Don't take the current element
            current.pop()
            backtrack(index + 1, current)

        backtrack(0, [])

        return result