#include "snowman.hpp"
#include <stdexcept>
#include <iostream>
#include <math.h>
#include <array>

using namespace std;
namespace ariel
{
    const int CHAR_TO_INT = 48, PART_OPTIONS = 4, NUM_OF_PARTS = 10, DECIMAL_BASE = 10, DIGITS = 8;
    string snowman(int n)
    {
        array<array<string, PART_OPTIONS>, NUM_OF_PARTS> str;
        const int H = 0;
        const int XU = 1;
        const int L = 2;
        const int N = 3;
        const int R = 4;
        const int YU = 5;
        const int XD = 6;
        const int T = 7;
        const int YD = 8;
        const int B = 9;

        str.at(H).at(0) = " _===_\n";
        str.at(H).at(1) = "  ___ \n .....\n";
        str.at(H).at(2) = "   _  \n  /_\\\n";
        str.at(H).at(3) = "  ___ \n (_*_)\n";

        str.at(N).at(0) = ",";
        str.at(N).at(1) = ".";
        str.at(N).at(2) = "_";
        str.at(N).at(3) = " ";

        str.at(L).at(0) = ".";
        str.at(L).at(1) = "o";
        str.at(L).at(2) = "O";
        str.at(L).at(3) = "-";

        str.at(R).at(0) = ".";
        str.at(R).at(1) = "o";
        str.at(R).at(2) = "O";
        str.at(R).at(3) = "-";

        str.at(XU).at(0) = " (";
        str.at(XD).at(0) = "<(";
        str.at(XU).at(1) = "\\(";
        str.at(XD).at(1) = " (";
        str.at(XU).at(2) = " (";
        str.at(XD).at(2) = "/(";
        str.at(XU).at(3) = " (";
        str.at(XD).at(3) = " (";

        str.at(YU).at(0) = ") \n";
        str.at(YD).at(0) = ")>\n";
        str.at(YU).at(1) = ")/\n";
        str.at(YD).at(1) = ") \n";
        str.at(YU).at(2) = ") \n";
        str.at(YD).at(2) = ")\\\n";
        str.at(YU).at(3) = ") \n";
        str.at(YD).at(3) = ") \n";

        str.at(T).at(0) = " : ";
        str.at(T).at(1) = "] [";
        str.at(T).at(2) = "> <";
        str.at(T).at(3) = "   ";

        str.at(B).at(0) = " ( : ) ";
        str.at(B).at(1) = " (\" \") ";
        str.at(B).at(2) = " (___) ";
        str.at(B).at(3) = " (   ) ";

        string n_str = to_string(n);
        string ans;

        if (n_str.size() != DIGITS)
        {
            throw std::invalid_argument("number has to have exactly 8 digits.");
        }

        // HNLRXYTB -> HXLNRYXTYB

        const int H_OFFSET = 7;
        const int X_OFFSET = 3;
        const int L_OFFSET = 5;
        const int N_OFFSET = 6;
        const int R_OFFSET = 4;
        const int Y_OFFSET = 2;
        const int T_OFFSET = 1;
        const int B_OFFSET = 0;

        array<int, NUM_OF_PARTS> options = {
            (n / (int)pow(DECIMAL_BASE, H_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, X_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, L_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, N_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, R_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, Y_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, X_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, T_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, Y_OFFSET)) % DECIMAL_BASE,
            (n / (int)pow(DECIMAL_BASE, B_OFFSET)) % DECIMAL_BASE};


        for (int i = 0; i < NUM_OF_PARTS; i++)
        {
            int tmp = (n % DECIMAL_BASE);
            if (tmp < 1 || tmp > 4)
            {
                throw std::invalid_argument("all digits needs to be within 1 <= (digit) <= 4");
            }
            ans.append(str.at(i).at(options.at(i) - 1)); // [options[i] - 1]);
        }

        return ans;
    }
}