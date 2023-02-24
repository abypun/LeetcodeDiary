func minimumOperations(nums []int) int {
    records := map[int]bool{}
    for i := 0; i < len(nums); i++ {
        if nums[i] != 0 {
            records[nums[i]] = true
        }
    }
    return len(records)
}
