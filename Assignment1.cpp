// Assignment1.cpp

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool validate_base(string base)
{
    if (base == "2" || base == "8" || base == "10" || base == "16")
        return true;
    else
        return false;
}

int base_to_dec(string input_number, int base)
{
    map<string, string> value_map = {
        {"0","0"},{"1","1"},{"2","2"},{"3","3"},{"4","4"},{"5","5"},{"6","6"},
        {"7","7"},{"8","8"},{"9","9"},{"A", "10"},{"a","10"},{"B","11"},{"b","11"},
        {"C","12"},{"c","12"},{"D","13"},{"d","13"},{"E","14"},{"e","14"},{"F","15"},{"f","15"}
    };

    int output = 0;
    int length = input_number.length();
    for (int i = 0; i < length; i++)
    {
        string digit = { input_number[i] };
        output += stoi(value_map[digit]) * pow(base, length - 1 - i);
    }
    
    return output;
}

string dec_to_base(int number, int base)
{
    map<int, string> value_map = {
        { 0,"0"},{ 1,"1"},{ 2,"2"},{ 3,"3"},{ 4,"4"},{ 5,"5"},{ 6,"6"},{ 7,"7"},{ 8,"8"},{ 9,"9"},
        { 10,"A"},{ 11,"B"},{ 12,"C"},{ 13,"D"},{ 14,"E"},{ 15,"F"}
    };

    int dividend = number;
    string output = "";
    while (dividend > 0)
    {
        output += value_map[dividend % base];
        dividend = dividend / base;
    }
    reverse(output.begin(), output.end());
    cout << output << endl;
    return output;
}

string convert_number(string input_number, int source_base, int target_base)
{
    int dec_number = base_to_dec(input_number, source_base);
    string output = dec_to_base(dec_number, target_base);
    return output;
}

bool validate_input(string input_number, int source_base)
{
    bool is_valid;
    switch (source_base)
    {
    case 2:
        is_valid = input_number.find_first_not_of("01") == -1;

        if (!is_valid)
            cout << "\nYou have not entered a valid binary input.\n\n";

        return is_valid;

        break;
    case 8:
        is_valid = input_number.find_first_not_of("01234567") == -1;

        if (!is_valid)
            cout << "\nYou have not entered a valid octal input.\n\n";

        return is_valid;

        break;
    case 10:
        is_valid = input_number.find_first_not_of("0123456789") == -1;

        if (!is_valid)
            cout << "\nYou have not entered a valid decimal input.\n\n";

        return is_valid;

        break;
    case 16:
        is_valid = input_number.find_first_not_of("0123456789ABCDEF") == -1;

        if (!is_valid)
            cout << "\nYou have not entered a valid hexadecimal input.\n\n";

        return is_valid;

        break;
    }

    return true;

}

int main()
{
    string resume;
    string input_number;
    string source_base;
    string target_base;
    string output;
    bool is_valid_input;
    bool is_valid_base;
    while (true)
    {
        is_valid_input = false;
        is_valid_base = false;
        system("cls");
        cout << "---------------------------\n";
        cout << "NUMBERING SYSTEM CALCULATOR\n";
        cout << "---------------------------\n\n";

        while (!is_valid_input)
        {
            cout << "Enter number to convert:\n";
            cin >> input_number;
            is_valid_input = input_number.find_first_not_of("1234567890abcdefABCDEF") == -1;

            if (!is_valid_input)
                cout << "You have not entered a valid number. \n\n";
        }
        
        while (!is_valid_base)
        {
            cout << "Enter source base (i.e. base to convert FROM):\n";
            cin >> source_base;
            is_valid_base = validate_base(source_base);

            if (!is_valid_base)
                cout << "You have not entered a valid base. Please enter one of 2, 8, 10, or 16. \n\n";
        }

        is_valid_base = false;

        while (!is_valid_base)
        {
            cout << "Enter target base (i.e. base to convert TO):\n";
            cin >> target_base;
            is_valid_base = validate_base(target_base);

            if (!is_valid_base)
                cout << "You have not entered a valid base. Please enter one of 2, 8, 10, or 16. \n\n";
        }

        if (!validate_input(input_number, stoi(source_base)))
        {
            system("pause");
            continue;
        }

        output = convert_number(input_number, stoi(source_base), stoi(target_base));

        cout << "Converting the number " << input_number << " from base " << source_base << " to base " << target_base << " results in:\n";
        cout << output << "\n";

        while (resume != "Y" || resume != "y" || resume != "N" || resume != "n")
        {
            cout << "\n" << "Do you wish to continue with new inputs?\n";
            cout << "Enter (Y) to continue.\n";
            cout << "Enter (N) to quit.\n";
            cin >> resume;

            if (resume == "Y" || resume == "y")
                break;
            else if (resume == "N" || resume == "n")
                return 0;
            else
                cout << resume << " is not a valid input.\n";
        }
        
    }
}
