#include <iostream> // std::cerr
#include <future>   // std::promise, std::future_error, std::future_category
using namespace std;
int main()
{
    std::promise<int> prom;
    try
    {
        prom.get_future();
        prom.get_future(); // throws a std::future_error of the future category
    }
    catch (std::future_error &e)
    {
        if (e.code().category() == std::future_category())
            std::cerr << "future_error of the future category thrown\n";
        if (e.code() == std::make_error_condition(std::future_errc::future_already_retrieved))
            std::cerr << "[future already retrieved]\n";
        else
            std::cerr << "[unknown exception]\n";
        error_code temp = make_error_code(future_errc::promise_already_satisfied);
        std::cout << e.what() << endl;
        cout << temp.value() << endl;
    }
    cin.get();
    return 0;
}