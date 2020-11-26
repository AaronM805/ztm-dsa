// For this problem we will reverse the array in 3 stages.
// 1. Reverse the array
// 2. reverse the subarray from 0 to k -1
// 3. reverse the subaray from k to len - 1

// [1 2 3 4 5 6 7] k =3
// Output: [5 6 7 1 2 3 4]
// Steps:
// 1 [7 6 5 4 3 2 1]
// 2 [5 6 7 4 3 2 1]
// 3 [5 6 7 1 2 3 4]

class Solution {
public:
  void Reverse(vector<int>& nums, int begin, int end)
  {
    for (int i = begin, j = end;
         i <= (end + begin) / 2 && j > (end + begin) / 2;
         ++i, --j)
    {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }
  void rotate(vector<int>& nums, int k)
  {
    int len = nums.size();
    if (len == 0 || len == 1)
    {
      return;
    }
    if (k >= len)
    {
      k = k % len;
    }
    if (k == 0)
    {
      return;
    }
    Reverse(nums, 0, len - 1);
    Reverse(nums, 0, k - 1);
    Reverse(nums, k, len - 1);
  }
};