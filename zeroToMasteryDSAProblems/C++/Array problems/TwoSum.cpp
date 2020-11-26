//Given an array of integers numsand an integer target, return indices of the
// two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may 
//not use the same element twice.
//
//You can return the answer in any order.

/*
Example 1:

Input: nums = [2, 7, 11, 15], target = 9
Output : [0, 1]
Output : Because nums[0] + nums[1] == 9, we return[0, 1].

Example 2 :

	Input : nums = [3, 2, 4], target = 6
	Output : [1, 2]

	Example 3 :

	Input : nums = [3, 3], target = 6
	Output : [0, 1]
*/

// OBSERVATION: solution written on leetcode. This will not build!             
// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // this will be the return vector that will contain the indices
        // it will have size 2 and the elements will be initialized with -1
        vector<int> res(2, -1);

        int len = nums.size();
        int other_elem = 0;
        int i = 0;

        // Unordered multimaps are associative containers that store elements 
        // formed by the combination of a key
        // value and a mapped value, much like unordered_map containers, 
        // but allowing different elements to have equivalent keys.
        unordered_multimap<int, int> hashMap;

        // if we dont have at least two elements return now
        if (len < 2)
        {
            return res;
        }

        // if we have only two elements return the first to indices
        if (len == 2)
        {
            res[0] = 0;
            res[1] = 1;
            return res;
        }

        // insert into the hashMap key -> values where key will be the value
        // from the array and value will be the indices of the array
        // I have chosen the multimap because we can have duplicate elements
        // in the array so wee need a structure which can support multiple 
        // values with the same key.

        // O(n) time
        for (int i = 0; i < len; ++i)
        {
            hashMap.insert(make_pair(nums[i], i));
        }

        // loop over the array
        // O(n) time
        while (i < len - 1)
        {
            // the other element of the pair we are looking for is
            // other_element = target - element
            other_elem = target - nums[i];

            // special funcion to find the multiple values corresponding to
            // a key
            auto j_range = hashMap.equal_range(other_elem);

            // we will check if the other_element is present in the hashMap
            // Maximum this will iterate twice O(2)
            for (auto j = j_range.first; j != j_range.second; ++j)
            {
               // we must not take into account an element from the array
               //  twice
               // For example we can have value 3 on positon 0 and 4 in the
               // array and our target is 6. If "i" is 0 we must not take into
               // acount "j=0", only "j=4".
                if (i != j->second)
                {
                    res[0] = i;
                    res[1] = j->second;
                    // we can break if we found the solution
                    break;
                }
            }
            ++i;
        }
        return res;
    }
};

// Time: O(n), Space: O(n)
