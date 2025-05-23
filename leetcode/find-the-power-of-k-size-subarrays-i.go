func resultsArray(nums []int, k int) []int {
    n := len(nums);
    result := make([]int, n - k + 1);

    i := 0;
    for {
        if (i >=  n - k + 1) {
            return result;
        }

        result[i] = powerOfArray(nums[i:i+k]);
        i++;
    }
}

func powerOfArray(nums []int) int {
    prev := -1;
    i := 0;
    for _, val := range nums {
        if ( i != 0 && prev != val - 1 ) {
            return -1;
        }
        prev = val;
        i++;
    }
    return nums[len(nums) - 1];
}
