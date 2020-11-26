class Solution {
public:

  // calculate the sum that of the elemts that crosses from the
  // left subarray to the right subarray
  // for example: 1 2 3 4 5 6
  // left subarray: 1 2 3
  // right subarray: 4 5 6
  // subarry with elemts in both: 1 2 3 4 5 6
  int calculateCrossOverSum(vector<int>& arr, int low, int mid, int high)
  {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int totalSum = 0;
    int sum = 0;
    for (int i = mid; i >= low; --i)
    {
      sum = sum + arr[i];
      if (leftSum < sum)
      {
        leftSum = sum;
      }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; ++i)
    {
      sum = sum + arr[i];
      if (rightSum < sum)
      {
        rightSum = sum;
      }
    }

    totalSum = leftSum + rightSum;
    return totalSum;
  }
  int calculateMaxSum(vector<int>& arr, int low, int high)
  {
    if (low == high)
    {
      return arr[low];
    }

    int mid = (low + high) / 2;
    int leftSum = calculateMaxSum(arr, low, mid);
    int rightSum = calculateMaxSum(arr, mid + 1, high);
    int crossOverSum = calculateCrossOverSum(arr, low, mid, high);

    return max(leftSum, max(rightSum, crossOverSum));
  }
  int maxSubArray(vector<int>& nums)
  {
    int maxSum = 0;
    int len = nums.size();

    if (len == 0)
    {
      return 0;
    }
    if (len == 1)
    {
      return nums[0];
    }
    maxSum = calculateMaxSum(nums, 0, len - 1);

    return maxSum;
  }
};