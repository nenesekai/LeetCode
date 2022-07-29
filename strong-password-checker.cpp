#include <iostream>

using namespace std;

class Solution
{

public:

    int strongPasswordChecker(string password)
    {
        int pw_size = password.size(), step = 0;

        string combo = "-";

        bool cap = false, uncap = false, num = false;

        for (char chr : password)
        {
            if (chr >= 'a' && chr <= 'z') uncap = true;
            if (chr >= 'A' && chr <= 'Z') cap   = true;
            if (chr >= '0' && chr <= '9') num   = true;

            if (cap && uncap && num) break;
        }

        for (int i = 0; i < password.size(); i++)
        {
            if (password[i] != combo[0])
            {
                combo = string(1, password[i]);
            }
            else
            {
                combo += string(1, password[i]);

                if (combo.size() >= 3)
                {
                    step++;
                    
                    if (pw_size < 6)
                    {
                        combo = string(1, password[i]);
                        pw_size++;
                    
                        if (!uncap) 
                        {
                            uncap = true;
                            continue;
                        }

                        if (!cap)
                        {
                            cap = true;
                            continue;
                        }

                        if (!num)
                        {
                            num = true;
                            continue;
                        }
                    }
                    else if (pw_size > 20)
                    {
                        combo = string(1, password[i]) + string(1, password[i]);
                        pw_size--;
                    }
                    else
                    {
                        combo = "-";
                    
                        if (!uncap) 
                        {
                            uncap = true;
                            continue;
                        }

                        if (!cap)
                        {
                            cap = true;
                            continue;
                        }

                        if (!num)
                        {
                            num = true;
                            continue;
                        }
                    }
                }
            }
        }

        int unsolved = 0;

        if (!cap)   unsolved++;
        if (!num)   unsolved++;
        if (!uncap) unsolved++;

        if (pw_size < 6)
        {
            step     += 6 - pw_size;
            unsolved -= 6 - pw_size;
        }

        if (pw_size > 20)
        {
            step     += pw_size - 20;
        }

        if (unsolved > 0) step += unsolved;

        return step;
    }

};

int main()
{
    string password = "bbaaaaaaaaaaaaaaacccccc";

    Solution solution;

    cout << solution.strongPasswordChecker(password) << endl;

    return 0;
}