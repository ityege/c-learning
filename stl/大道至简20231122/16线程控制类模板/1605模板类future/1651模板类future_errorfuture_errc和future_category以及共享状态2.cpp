#include <iostream> // std::cout
#include <future>   // std::promise, std::future_error
using namespace std;
int main()
{
    std::promise<int> prom;
    try
    {
        prom.get_future();
        prom.get_future(); // throws std::future_error
    }
    catch (std::future_error &e)
    {
        cout << "future_error caught"
             << "(" << e.code() << ")"
             << " : " << e.what() << endl;
    }
    return 0;
}