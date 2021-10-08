#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

void to_lower_case(string& value) {
    transform(value.begin(), value.end(), value.begin(), ::tolower);
}

void to_upper_case(string& value) {
    transform(value.begin(), value.end(), value.begin(), ::toupper);
}
void add_text(string& stringBuffer) {
    string value;
    cout << "Enter text : ";
    cin.ignore();
    getline(std::cin, value);
    stringBuffer += value;
}
void write_file_by_path(string* value) {
    string path;
    ofstream out;
    cout << "Enter file path : ";
    cin >> path;
    out.open(path);
    if (out.is_open()) out << *value << endl;
    cout << "Text was written in : " << path << endl;
}
void read_text_from_file(string& stringBuffer) {
    string path,value;
    cout << "Enter file path : ";
    cin >> path;
    ifstream in(path);
    if (in.is_open())
    {
        while (getline(in, value))
        {
            stringBuffer += value + "\n";
        }
    }
    in.close();
}
int main()
{
    //q - quite programm;
    //+ - add text to stringBuffer;
    //c - clear text in stringBuffer;
    //L - transform text in stringBuffer to lowercase;
    //U - transfrom text in stringBuffer to uppercase;
    //w - write text in strinfBuffer to file by path;
    //r - read text to stringBuffer;
    //t - out text from stringBuffer to console;
    string stringBuffer = "";
    while (true) {
        char comand;
        
        cout << "Enter comand : ";
        cin >> comand;
        
        switch (comand) {
        case 'q': {
            exit(0);
            break;
        }
        case '+': {
            add_text(stringBuffer);
            break;
        }
        case 'c': {
            stringBuffer = "";
            break;
        }
        case 'L': {
            to_lower_case(stringBuffer);
            break;
        }
        case 'U': {
            to_upper_case(stringBuffer);
            break;
        }
        case 'w': {
            write_file_by_path(&stringBuffer);
            break;
        }
        case 't': {
            cout << stringBuffer << endl;
            break;
        }
        case 'r': {
            read_text_from_file(stringBuffer);
            break;
        }
        default: cout << "Wrong command try again" << endl;
        }
    }
}
