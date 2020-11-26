class Solution {
public:
  void moveZeroes(vector<int>& nums)
  {
    int len = nums.size();

    if (len == 0 || len == 1)
    {
      return;
    }

    // have to pointers: one reads elements, one is where we will write
    // start write and read from same position
    // move read unitil we find a non-zero element
    // if we do find it then write will get reads value and write will also
    // be incremented.
    // So read and write are both incremented when we find a non-zero element
    // So we know that write will stop on a zero-element because it is only
    // incremeted when a non-zero element is found.
    int write = 0;
    for (int read = 0; read < len; read++)
    {
      if (nums[read] != 0)
      {
        nums[write] = nums[read];
        write++;
      }
    }
    // once we moved every non-zero elements on zero-elements,
    // all the elemets from were write has stoped will be set to zero
    for (int i = write; i < len; ++i)
    {
      nums[i] = 0;
    }
  }
};