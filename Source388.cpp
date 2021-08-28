#include "stdafx.h"

class Solution {
	void strip(string &s)
	{
		int k = 0;
		while (k < s.length() && s[k] == ' ')
		{
			k++;
		}
		s = s.substr(k);
	}
public:
	int lengthLongestPath(string input) {
		size_t i = 0, j = 0;
		std::vector<string>	vPaths;
		//string longgestPath;
		int longestlength = 0;
		for (j = input.find('\n', i); ; i=j+1, j = input.find('\n', i))
		{
			// i:	start of line
			// j:	end of line

			// count number of \t
			string sLine;
			if (j == string::npos)
				sLine = input.substr(i);
			else
				sLine = input.substr(i, j - i);
			int k = 0;
			while (k< sLine.length() && sLine[k]=='\t')
			{
				k++;
			}
			string file = sLine.substr(k);

			//strip(file);
			bool isFolder = file.find('.') == file.npos;

			if (k > vPaths.size())
			{
				assert(0);
			}
			else if (k == vPaths.size())
			{
				if (isFolder)
					vPaths.push_back(file);
			}
			else
			{
				if (k >= 0)
					vPaths.erase(vPaths.begin() + k, vPaths.end());
				if (isFolder)
					vPaths.push_back(file);
			}
			
			if (isFolder)
			{
				
			}
			else
			{
				int npath = 0;
				for (auto s: vPaths)
				{
					npath += s.length() +1;
				}
				npath += file.length();

				if (npath > longestlength)
				{
					longestlength = npath;
				}
			}

			if(j == string::npos)
				break;
		}
		return longestlength;
	}
};

void test388()
{
	Solution s;
	assert(20 == s.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
	assert(12 == s.lengthLongestPath("dir\n    file.txt"));
}