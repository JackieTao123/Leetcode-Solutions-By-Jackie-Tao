/*
	Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <iostream>
#include <string>

using std::string;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
		{
			return 0;
		}
		char *p_start = &s[0];
		int len = 0;
		while (*p_start != '\0')
		{
			int temp_len = 0;
			char *q_scan = p_start;
			//q_scan = p_start + 1;
			while (*q_scan != '\0')
			{
				++temp_len;
				if (*(q_scan+1)!= *p_start)
					q_scan += 1;
				else
					break;
			}
			if (len < temp_len)
			{
				len = temp_len;
			}
			if (*(p_start) == '\0')
				return len;
				p_start += 1;
		}
		return len;

	}
};