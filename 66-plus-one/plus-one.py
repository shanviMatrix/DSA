class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        number = ""

        for digit in digits:
            number += str(digit)

        number = int(number) + 1

        answer = []

        for digit in str(number):
            answer.append(int(digit))

        return answer