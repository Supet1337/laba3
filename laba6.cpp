#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <regex>

using namespace std;

void is_valid_email(const string& str) {
    static const regex r(R"(([a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\.[a-zA-Z0-9_-]+))");
    smatch match;
    if(regex_search(str, match, r))
        cout << match[0] << endl;
}


int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream fin;
    fin.open("../text.html");
    if (!fin)
        std::cout << "Файл не открыт\n\n";
    else
        std::cout << "Файл открыт!\n\n";

    string buf;
    while(getline(fin, buf)){
        is_valid_email(buf);
    }

    return 0;

}

