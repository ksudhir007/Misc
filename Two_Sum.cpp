class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        vector<int> result;
        for (i = 0; i < numbers.size(); i++)
        {
            for (j = i+1; j < numbers.size(); j++)
            {
                if(numbers[i]+numbers[j] == target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    goto out;
                }
            }
        }
        out:
            return result;
    }
};

/*
Brute force - above solution - O(n^2)

Another solution:  O(nlogn)
  Sort the array;
  take two counters - one starting in beginning, one starting at ending;
  while(first_counter<second_counter)
  {
    temp = numbers[first_counter] + numbers[second_counter];

    if (temp == target]
    {
      add indexes to vector result;
      break;
    }
    if (temp < target)
      increment first_counter;
    if (temp > target)
      decrement second_counter;
  }

Another solution: O(n) time and O(n) space 

  take an empty hash<int,bool>; - bool can be discarded
  iterate the array one by one;
  for every element you encounter:
      check if it is in hash
      if not found:
        store (target - current number) in hash;
      if found;
        save the index of current number;
        iterate from 0 to the current index in array
          break when array_element is target - current_number
*/
