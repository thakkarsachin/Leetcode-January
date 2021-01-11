/*
Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:

The number of elements currently in nums that are strictly less than instructions[i].
The number of elements currently in nums that are strictly greater than instructions[i].
For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7
*/

class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        answer = 0
        from sortedcontainers import SortedList
        instructionsSorted = SortedList()
        for instruction in instructions:
            left = instructionsSorted.bisect_left(instruction)
            right = len(instructionsSorted) - instructionsSorted.bisect(instruction)
            answer += left if left < right else right
            instructionsSorted.add(instruction)
        return answer % (10**9 + 7)