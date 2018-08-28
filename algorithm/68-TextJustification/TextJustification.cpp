// Source: https://leetcode.com/submissions/detail/172238016/
// Author: Diego Lee
// Date: 2018-08-28
//
// Description:
// Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is inserted between words.
//
// Note:
//
// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.
// Example 1:
//
// Input:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:
//
// Input:
// words = ["What","must","be","acknowledgment","shall","be"]
// maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be",
//              because the last line must be left-justified instead of fully-justified.
//              Note that the second line is also left-justified becase it contains only one word.
// Example 3:
//
// Input:
// words = ["Science","is","what","we","understand","well","enough","to","explain",
//          "to","a","computer.","Art","is","everything","else","we","do"]
// maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
//

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution
{
    public:
        std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth)
        {
            std::vector<std::string> result;
            if (words.empty())
            {
                return result;
            }

            std::vector<std::string> curr;
            int spaceWidth = maxWidth;
            for (size_t i = 0; i < words.size(); ++i)
            {
                const std::string& word = words[i];
                if (word.size() + curr.size() <= spaceWidth)
                {
                    spaceWidth -= word.size();
                    curr.push_back(word);
                }
                else
                {
                    std::string line = formatLine(curr, spaceWidth, false);
                    // std::cout << "line: " << line << std::endl;
                    result.push_back(line);

                    curr.clear();
                    spaceWidth = maxWidth - word.size();
                    curr.push_back(word);
                }
            }
            if (!curr.empty())
            {
                std::string line = formatLine(curr, spaceWidth, true);
                // std::cout << "line: " << line << std::endl;
                result.push_back(line);
            }
            return result;
        }

        std::string formatLine(const std::vector<std::string>& curr, int spaceWidth, bool lastLine)
        {
            if (curr.empty())
            {
                return "";
            }

            std::string line = curr[0];
            if (curr.size() == 1)
            {
                line.append(std::string(spaceWidth, ' '));
            }
            else
            {
                if (lastLine)
                {
                    for (size_t j = 1; j < curr.size(); ++j)
                    {
                        line.append(" ");
                        --spaceWidth;
                        line.append(curr[j]);
                    }

                    if (spaceWidth > 0)
                    {
                        line.append(std::string(spaceWidth, ' '));
                    }
                }
                else
                {
                    int spaceCnt = curr.size() - 1;
                    int averSpace = spaceWidth / spaceCnt;
                    int mod = spaceWidth - (averSpace * spaceCnt);
                    for (size_t j = 1; j < curr.size(); ++j)
                    {
                        int space = averSpace;
                        if (mod > 0)
                        {
                            space += 1;
                            --mod;
                        }
                        line.append(std::string(space, ' '));
                        line.append(curr[j]);
                    }
                }
            }
            return line;
        }
};

void testFullJustify()
{
    std::vector<std::string> words0 =
    {
        "This", "is", "an", "example", "of", "text", "justification."
    };
    std::vector<std::string> result0 =
    {
        "This    is    an",
        "example  of text",
        "justification.  "
    };

    std::vector<std::string> words1 =
    {
        "What","must","be","acknowledgment","shall","be"
    };
    std::vector<std::string> result1 =
    {
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
    };

    std::vector<std::string> words2 =
    {
        "What","must","be","shall","be."
    };
    std::vector<std::string> result2 =
    {
        "What must be",
        "shall be.   "
    };

    std::vector<std::string> words3 =
    {
        "Science","is","what","we","understand","well",
        "enough","to","explain","to","a","computer.",
        "Art","is","everything","else","we","do"
    };
    std::vector<std::string> result3 =
    {
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
    };

    Solution s;
    std::vector<std::string> result;
    result = s.fullJustify(words0, 16);
    assert(result == result0);
    result = s.fullJustify(words1, 16);
    assert(result == result1);
    result = s.fullJustify(words2, 12);
    assert(result == result2);
    result = s.fullJustify(words3, 20);
    assert(result == result3);
}

int main()
{
    testFullJustify();
    return 0;
}
