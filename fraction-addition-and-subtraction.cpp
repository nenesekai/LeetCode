#include <iostream>
#include <numeric>

using namespace std; 

long long gcd(long long int a, long long int b)
{        
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a,long long b)
{     
    if (a > b)
        return (a / gcd(a, b)) * b;
    else
        return (b / gcd(a, b)) * a;    
} 

class Solution
{

private:

    bool positive = true;
    int tempNumerator = 0, numerator = 0, tempDenominator = 0, denominator = 1;
    string num;

public:

    string fractionAddition(string expr)
    {
        while (expr != "")
        {   
            if (expr[0] == '+')
            {
                expr.erase(expr.begin());
                positive = true;
            }

            if (expr[0] == '-')
            {
                expr.erase(expr.begin());
                positive = false;
            }

            if (expr[0] >= '0' && expr[0] <= '9')
            {
                tempNumerator = stoi(expr.substr(0, expr.find('/')));
                expr.erase(expr.begin(), expr.begin() + expr.find('/'));
            }

            if (expr[0] == '/')
            {
                expr.erase(expr.begin());
            }

            if (expr[0] >= '0' && expr[0] <= '9')
            {
                if (expr.find('+') == -1 && expr.find('-') == -1) { tempDenominator = stoi(expr); expr = ""; }
                if (expr.find('+') != -1 && expr.find('-') == -1) { tempDenominator = stoi(expr.substr(0, expr.find('+'))); expr.erase(expr.begin(), expr.begin() + expr.find('+')); }
                if (expr.find('+') == -1 && expr.find('-') != -1) { tempDenominator = stoi(expr.substr(0, expr.find('-'))); expr.erase(expr.begin(), expr.begin() + expr.find('-')); }
                if (expr.find('+') != -1 && expr.find('-') != -1) { tempDenominator = stoi(expr.substr(0, min(expr.find('+'), expr.find('-')))); expr.erase(expr.begin(), expr.begin() + min(expr.find('+'), expr.find('-'))); }
            }

            int newDenominator = lcm(denominator, tempDenominator);
            numerator = numerator * (newDenominator / denominator) + (tempNumerator * (newDenominator / tempDenominator) * (positive ? 1 : -1));
            denominator = newDenominator;
        }

        int _gcd = gcd(numerator, denominator);

        numerator   /= _gcd;
        denominator /= _gcd;

        return to_string(numerator) + "/" + (numerator == 0 ? "1" : to_string(denominator));
    }

};

int main()
{
    Solution* obj = new Solution();

    cout << obj->fractionAddition("-1/2+4/3") << endl;

    cout << gcd(6, 8) << endl;

    return 0;
}