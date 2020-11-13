// Longest Word
// Have the function LongestWord(sen) take the sen parameter being passedand return the largest
// word in the string.If there are two or more words that are the same length, return the first word
// from the string with that length.Ignore punctuation and assume sen will not be empty.

//Examples
//Input : "fun&!! time"
//Output : time
//Input : "I love dogs"
//Output : love

#include <iostream>
#include <string>
using namespace std;

string LongestWord(string sen)
{
    int maxCount = 0;
    int count = 0;
    int maxStartPos = 0;
    int maxEndPos = 0;
    int len = sen.size();
    int startPos = 0;
    string retString;

    // check each character if it is a letter
    for (int i = 0; i < len; ++i)
    {
        // if it is a letter then count it and check against
        // the maxCount saved
        // if the present count is bigger then save that and save the
        // start and end position
        // C++ specific: isalhpa() will work here
        if ((sen[i] >= 'a' && sen[i] <= 'z') ||
            (sen[i] >= 'A' && sen[i] <= 'Z'))
        {
            count++;

            if (maxCount < count)
            {
                maxCount = count;
                maxEndPos = i;
                maxStartPos = startPos;
            }
        }
        // if we find a character which is not a letter
        // then reset count and start from a new position
        else
        {
            count = 0;
            if (i < len - 1)
            {
                startPos = i + 1;
            }
        }
    }

    // construct a new string with the longest word to return
    for (int i = maxStartPos; i <= maxEndPos; ++i)
    {
        retString.push_back(sen[i]);
    }

    return retString;

}

int main(void) 
{

	string s("fun&!! time");
	cout << LongestWord(s);
	return 0;

}

