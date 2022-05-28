#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{

public:

    int calPoints(vector<string>& ops)
    {
        int total = 0;
        stack<int> stk;

        for (string op : ops)
        {
            if (op == "C") 
            {
                total -= stk.top();
                stk.pop();
            }
            else if (op == "D")
            {
                stk.push(stk.top() * 2);
                total += stk.top();
            }
            else if (op == "+")
            {
                int temp = stk.top();
                stk.pop();
                temp += stk.top();
                stk.push(temp - stk.top());
                stk.push(temp);
                total += stk.top();
            }
            else
            {
                stk.push(std::stoi(op));
                total += stk.top();
            }
        }

        return total;
    }

};

int main()
{
    vector<string> ops{"8373","C","9034","-17523","D","1492","7558","-5022","C","C","+","+","-16000","C","+","-18694","C","C","C","-19377","D","-25250","20356","C","-1769","-8303","C","-25332","29884","C","+","C","-29875","-15374","C","+","14584","13773","+","17037","-28248","+","16822","D","+","+","-19357","-26593","-8548","4776","D","-8244","378","+","-19269","-25447","18922","-16782","2886","C","-17788","D","-22256","C","308","-9185","-19074","1528","28424","D","8658","C","7221","-13704","8995","-21650","22567","-29560","D","-9807","25632","6817","28654","D","-18574","C","D","20103","7875","C","9911","23951","C","D","C","+","18219","-20922","D","-24923"};
    Solution solution;

    cout << solution.calPoints(ops) << endl;

    return 0;
}