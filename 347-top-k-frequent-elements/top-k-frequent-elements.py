class Solution:
    def topKFrequent(self, nums, k):

        frequency = {}

        # Count frequency
        for number in nums:
            if number in frequency:
                frequency[number] += 1
            else:
                frequency[number] = 1

        # Sort numbers according to frequency
        numbers = list(frequency.keys())

        numbers.sort(key=lambda x: frequency[x], reverse=True)

        # Take first k numbers
        answer = numbers[:k]

        return answer