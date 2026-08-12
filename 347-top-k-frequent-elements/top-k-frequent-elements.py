class Solution:
    def topKFrequent(self, nums, k):

        frequency = {}

        for number in nums:
            if number in frequency:
                frequency[number] += 1
            else:
                frequency[number] = 1

        numbers = list(frequency.keys())

        numbers.sort(key=lambda x: frequency[x], reverse=True)

        answer = numbers[:k]

        return answer