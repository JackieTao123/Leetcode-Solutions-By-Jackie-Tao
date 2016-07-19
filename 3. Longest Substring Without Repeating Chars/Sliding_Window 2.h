/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

//This method use MAP to implement.

#include <iostream>
#include <string>
//#include <set>
#include <algorithm>
#include <map>

using std::string;
//using std::set;
using std::map;
using std::max;
class Solution{
public:
	int lengthOfLongestSubstring(string s){
		if (s.empty())
			return 0;
		map<char, int> mapping;
		int len = s.length();
		int max_len = 0;
		for (int i = 0, j = 0; j < len; ++j)
		{
			//mapping has the same character.
			if (mapping.find(s[j]) != mapping.end())
			{
				i = max(mapping[s[j]], i);
			}
			max_len = max(max_len, (j - i + 1));
			mapping[s[j]] = j + 1;
		}
		return max_len;
	}
};