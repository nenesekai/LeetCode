#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    string validIPAddress(string queryIP) 
    {
        vector<string> digit;

        if (queryIP.find('.') != -1)
        {
            while (queryIP.find('.') != -1)
            {
                digit.push_back(queryIP.substr(0, queryIP.find('.')));
                queryIP.erase(0, queryIP.find('.') + 1);
            }

            digit.push_back(queryIP);

            if (digit.size() == 4)
            {
                for (vector<string>::iterator iter = digit.begin(); iter < digit.end(); iter++)
                {
                    try
                    {
                        if (!(stoi(*iter) >= 0 && stoi(*iter) <= 255)) return "Neither";

                        if (iter->length() != 1 && iter->at(0) == '0') return "Neither";
                        
                        for (string::iterator digit_iter = iter->begin(); digit_iter < iter->end(); digit_iter++)
                        {
                            if (!(*digit_iter >= '0' && *digit_iter <= '9')) return "Neither";
                        }
                    }
                    catch(const std::exception& e)
                    {
                        return "Neither";
                    }
                }
                    
                return "IPv4";
            }

        }
        else if (queryIP.find(':') != -1)
        {
            while (queryIP.find(':') != -1)
            {
                digit.push_back(queryIP.substr(0, queryIP.find(':')));
                queryIP.erase(0, queryIP.find(':') + 1);
            }

            digit.push_back(queryIP);

            if (digit.size() == 8)
            {
                for (vector<string>::iterator iter = digit.begin(); iter < digit.end(); iter++)
                {
                    if (!(iter->length() >= 1 && iter->length() <= 4))
                    {
                        return "Neither";
                    }
                    else
                    {
                        for (string::iterator digit_iter = iter->begin(); digit_iter < iter->end(); digit_iter++)
                        {
                            if (!((*digit_iter >= '0' && *digit_iter <= '9') || (*digit_iter >= 'a' && *digit_iter <= 'f') || (*digit_iter >= 'A' && *digit_iter <= 'F')))
                            {
                                return "Neither";
                            }
                        }
                    }
                }

                return "IPv6";
            }
        }
        
        return "Neither";
    }

};

int main()
{
    Solution* obj = new Solution();

    cout << obj->validIPAddress("1e1.4.5.6") << endl;

    return 0;
}