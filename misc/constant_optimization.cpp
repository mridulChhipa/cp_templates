/*
 map<vector<int>, int> is too slow, so we can use unordered_map with a custom hash function for vector<int>.
Since std::vector<int> does not have a built-in hash function, we need to define our own hash function for it.
*/

#include <iostream>
#include <vector>
namespace std
{
  template <>
  struct hash<vector<int>>
  {
    size_t operator()(const vector<int> &v) const
    {
      size_t hash_value = 0;
      for (int i : v)
      {
        hash_value ^= std::hash<int>{}(i) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
      }
      return hash_value;
    }
  };
}