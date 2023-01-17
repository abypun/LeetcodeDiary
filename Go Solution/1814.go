func countNicePairs(nums []int) int {
    rev := func(num int) int {
        ret := 0
        for num > 0 {
            ret = ret * 10 + num % 10
            num /= 10
        }
        return ret
    }

    cnts := map[int]int{}
    for i := 0; i < len(nums); i++ {
        cnts[nums[i] - rev(nums[i])]++
    }

    ret := 0
    for _, v := range cnts {
        ret = (ret + v*(v-1)/2) % (1e9+7)
    }
    return ret
}
