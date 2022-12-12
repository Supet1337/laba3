#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <regex>

using namespace std;

void is_valid_email(const string& str) {
    static const regex r(R"(([<a href=](https?\:\/\/)?([a-zA-Z0-9]+([a-zA-Z0-9-]+[a-zA-Z0-9]\.[a-zA-Z0-9]+)+(\/?[?=&\d.]?[\w-]+)+)))");
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
        std::cout << "Ôàéë íå îòêðûò\n\n";
    else
        std::cout << "Ôàéë îòêðûò!\n\n";

    string buf;
    while(getline(fin, buf)){
        is_valid_email(buf);
    }

    return 0;

}

