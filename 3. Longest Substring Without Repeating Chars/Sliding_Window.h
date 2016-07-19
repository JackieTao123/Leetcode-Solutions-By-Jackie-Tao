/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using std::string;
using std::set;
using std::max;
class Solution{
public:
	int lengthOfLongestSubstring(string s){
		if (s.empty())
		{
			return 0;
		}
		set<char> window;
		unsigned len = s.length();
		unsigned i= 0;
		unsigned j = 0;
		int max_len = 0;
		while (i < len&&j < len)
		{
			//exist the same character in the current substring.
			if (window.find(s[j]) == window.end())
			{
				window.insert(s[j]);
				j++;
				max_len = max(max_len, int(j - i));
			}
			else
			{
				window.erase(s[i]);
				i++;
			}
		}
		return max_len;
	}
};