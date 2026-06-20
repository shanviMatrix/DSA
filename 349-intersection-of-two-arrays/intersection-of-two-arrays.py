class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        common_numbers = []

        for number in nums1:
            if number in nums2 and number not in common_numbers:
                common_numbers.append(number)

        return common_numbers