class Solution1:
    '''
    :author: Rufeer
    :solution: O(n^2)
    :runtime: 7804 ms
    '''
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

class Solution2:
    '''
    :author: yilmazali
    :solution: Hash Table O(n)
    :runtime: 56 ms
    '''
    def twoSum(self, nums, target):
        num_set = {}
        for num_index, num in enumerate(nums):
            if (target-num) in num_set:
                return [num_set[target-num], num_index]
            num_set[num] = num_index
