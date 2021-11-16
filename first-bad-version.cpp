#include <iostream>

#define mid(start, end) (end - start) / 2 + start

class Solution 
{

    int bad_version = 10;

public:

    int firstBadVersion(int n) 
    {
        int start = 1, end = n;
        if (isBadVersion(1)) return 1;
        for (;;)
        {
            if (start + 1 == end)
            {
                return end;
            }
            else if (isBadVersion(mid(start, end)) && !isBadVersion(mid(start, end) - 1))
            {
                return mid(start, end);
            }
            else if (isBadVersion(mid(start, end)))
            {
                end = mid(start, end) - 1;
            }
            else if (!isBadVersion(mid(start, end)))
            {
                start = mid(start, end);
            }
        }
    }

    bool isBadVersion(int version)
    {
        return version >= bad_version;
    }

};

int main()
{
    Solution solution;
    
    std::cout << solution.firstBadVersion(100);

    return 0;
}