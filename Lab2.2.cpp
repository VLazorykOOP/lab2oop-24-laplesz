#include <iostream>
#include <string> 
#include <list>

using namespace std;

const int max_rows = 8;
const int max_symbols = 8;

string input_data[max_rows - 1];


string bit(int, int);

string bit(int number, int NumOfBits)
{
    int i = 1;

    list<int> bitsList;

    if (number)
    {
        for (; number != 0; number /= 2)
        {
            int bit = number % 2;
            bitsList.push_front(bit);
        }
    }
    else
        bitsList.push_front(0);

    if (bitsList.size() < NumOfBits)
    {
        for (int i = NumOfBits - bitsList.size(); i != 0; i--)
            bitsList.push_front(0);
    }

    string result = "";

    for (list<int>::const_iterator ci = bitsList.begin(); ci != bitsList.end(); ci++, i++)
    {
        string s = to_string(*ci);

        result += s;
    }

    return result;
}


string  CorrectingData(string str_inp)
{
    string result;

    if (str_inp.length() >= 8)
    {
        result = str_inp.substr(0, max_symbols);
    }
    else
    {
        result = str_inp;

        for (int j = str_inp.length(); j <= max_symbols - 1; j++)
        {
            result += ' ';
        }
    }

    return result;
}

string GetParityBit(string str_inp)
{
    int count = 0;

    for (size_t i = 0; i < str_inp.length(); i++)
    {
        if (str_inp[i] == '1')
            count++;
    }

    return (count > 0 && count % 2 == 0) ? "1" : "0";
}

string Encrypting(int row_number, int symbol_number, char symbol)
{
    string bit_0_2 = bit(row_number, 3);

    string bit_3_5 = bit(symbol_number, 3);

    string bit_6 = GetParityBit(bit_0_2 + bit_3_5);

    string bit_7_14 = bit(int(symbol), 8);

    string bit_15 = GetParityBit(bit_7_14);

    return bit_0_2 + bit_3_5 + bit_6 + bit_7_14 + bit_15;
}

void PrintData()
{
    if (input_data->length() == 0)
        return;

    cout << "Entered and encrypted lines: " << std::endl;

    for (int i = 0; i < input_data->length(); i++)
    {
        cout << i + 1 << " line: " << input_data[i] << std::endl;

        for (size_t j = 0; j < max_symbols; j++)
        {
            cout << input_data[i][j];
            cout << " ( " + Encrypting(i, j, input_data[i][j]) + " )\n";
        }
    }
}

int main()
{
    cout << "Enter 8 lines of characters. A maximum of 8 characters per line will be processed.\n" << std::endl;

    for (int i = 0; i < max_rows; i++)
    {
        cout << "Enter " << i + 1 << " line: ";

        string temp;

        cin >> temp;

        input_data[i] = CorrectingData(temp);
    }

    PrintData();

    return 0;
}
