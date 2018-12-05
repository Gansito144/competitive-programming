// Complete the maxSubsetSum function below.
func maxSubsetSum(arr []int32) int32 {
    n := len(arr) + 2;
    dp := make([]int32, n)
    for i := 2; i<n; i++ {
        dp[i] = max(dp[i-1], dp[i-2] + arr[i-2])
    }
    return dp[n-1]
}
