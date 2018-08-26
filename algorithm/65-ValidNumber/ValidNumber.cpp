// Source: https://leetcode.com/problems/valid-number/description/
// Author: Diego Lee
// Date: 2018-08-08
//
// Description:
// Validate if a given string is numeric.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
//
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up
// front before implementing one.
//
// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a
// const char * argument, please click the reload button to reset your code definition.

#include <iostream>
#include <cassert>
#include <string>
#include <map>

enum EState
{
    eState_0,
    eState_1,
    eState_2,
    eState_3,
    eState_4,
    eState_5,
    eState_6,
    eState_7,
    eState_8,
};

enum ESymobl
{
    eSymbol_Digit,
    eSymbol_Sign,
    eSymbol_Dot,
    eSymbol_E,
    eSymbol_Blank,
};

typedef std::map<int, int> Symbol2StateMap;
typedef std::map<int, Symbol2StateMap> StateTransitionMap;
class Solution
{
    public:
        bool isNumber(std::string s)
        {
            StateTransitionMap st;
            MakeStateTransition(st);

            int currstate = eState_0;
            for (auto c : s)
            {
                int symbol = -1;
                if (c >= '0' && c <= '9')
                {
                    symbol = eSymbol_Digit;
                }
                else if (c == '+' || c == '-')
                {
                    symbol = eSymbol_Sign;
                }
                else if (c == 'e' || c == 'E')
                {
                    symbol = eSymbol_E;
                }
                else if (c == '.')
                {
                    symbol = eSymbol_Dot;
                }
                else if (c == ' ')
                {
                    symbol = eSymbol_Blank;
                }
                else
                {
                    return false;
                }

                Symbol2StateMap& ss = st[currstate];
                if (ss.find(symbol) == ss.end())
                {
                    return false;
                }
                currstate = ss[symbol];
            }

            // std::cout << "state=" << currstate << std::endl;
            return (currstate == eState_2
                    || currstate == eState_4
                    || currstate == eState_7
                    || currstate == eState_8);
        }

        void MakeStateTransition(StateTransitionMap& st)
        {
            // s0
            st[eState_0][eSymbol_Blank] = eState_0;
            st[eState_0][eSymbol_Digit] = eState_2;
            st[eState_0][eSymbol_Sign] = eState_1;
            st[eState_0][eSymbol_Dot] = eState_3;

            // s1
            st[eState_1][eSymbol_Digit] = eState_2;
            st[eState_1][eSymbol_Dot] = eState_3;

            // s2
            st[eState_2][eSymbol_Digit] = eState_2;
            st[eState_2][eSymbol_Blank] = eState_8;
            st[eState_2][eSymbol_E] = eState_5;
            st[eState_2][eSymbol_Dot] = eState_4;

            // s3
            st[eState_3][eSymbol_Digit] = eState_4;

            // s4
            st[eState_4][eSymbol_Digit] = eState_4;
            st[eState_4][eSymbol_E] = eState_5;
            st[eState_4][eSymbol_Blank] = eState_8;

            // s5
            st[eState_5][eSymbol_Sign] = eState_6;
            st[eState_5][eSymbol_Digit] = eState_7;

            // s6
            st[eState_6][eSymbol_Digit] = eState_7;

            // s7
            st[eState_7][eSymbol_Digit] = eState_7;
            st[eState_7][eSymbol_Blank] = eState_8;

            // s8
            st[eState_8][eSymbol_Blank] = eState_8;
        }
};

void testIsNumber()
{
    Solution s;
    assert(s.isNumber(" 005047e+6") == true);
    assert(s.isNumber("3. ") == true);
    assert(s.isNumber("11") == true);
    assert(s.isNumber("0") == true);
    assert(s.isNumber(" 0.1") == true);
    assert(s.isNumber("abc") == false);
    assert(s.isNumber("1 a") == false);
    assert(s.isNumber("2e10") == true);
}

int main()
{
    testIsNumber();
    return 0;
}
