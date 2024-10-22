def bubble_sort(nums: list) -> None:
    '''
        Function for bubble sort
    '''
    # Time Complexity : O(n^2)
    n = len(nums)

    for i in range(0, n):
        for j in range(0, n - i - 1):
            # If current Element is greater than next element
            if (nums[j] > nums[j + 1]):
                # Swap the current Element and next element
                temp = nums[j + 1]
                nums[j + 1] = nums[j]
                nums[j] = temp
                
if __name__ != "main":
    nums = [1,5,4,2,3,2,5,3,23,4,24]
    bubble_sort(nums)

    for a in nums:
        print(a, end=" ")
    print()