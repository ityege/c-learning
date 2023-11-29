#include <iostream>
#include <locale>
#include <clocale>
#include <ctime>
int main()
{
    char dataStr[81];
    time_t curtime;
    struct tm *tmtime;
    time(&curtime);
    tmtime = gmtime(&curtime);
    strftime(dataStr, 80, "% # x", tmtime);
    std::locale french(std::locale("french"), std::locale("american"), LC_TIME);
    std::locale::global(french);
    strftime(dataStr, 80, "% # x", tmtime);
    std::cout << "French Date: " << std::endl;
    std::cout << dataStr << std::endl;
    return 0;
}