func minMaxGame(nums []int) int {
    n := len(nums)
    f := func(i int) int {
        if nums[2*i] < nums[2*i+1] && i%2 == 0 ||
        nums[2*i] > nums[2*i+1] && i%2 == 1 {
            return nums[2*i]
        }
        return nums[2*i+1]
    }
    for n != 1 {
        for i := 0; i < n / 2; i++ {
            nums[i] = f(i)
        }
        n /= 2
    }
    return nums[0]
}
