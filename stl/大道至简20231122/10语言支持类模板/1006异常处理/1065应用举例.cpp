#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;

void Tfunction()
{
    cout << "1. I'll be back." << endl;
}

void termfunction()
{
    cout << "2. I'll be back." << endl;
    exit(1);
}

class Test
{
public:
    Test(std::string msg) : m_msg(msg)
    {
        std::cout << "In Test::Test()" << std::endl;
    }

    ~Test()
    {
        std::cout << "In Test::~Test()"
                  << " std::uncaught_exceptions() = " << std::uncaught_exceptions()
                  << std::endl;
    }

private:
    std::string m_msg;
};

int main()
{
    std::string msg = "overflow.";
    std::runtime_error ep(msg);
    cout << ep.what() << " 1. " << endl;
    try
    {
        throw ep;
    }
    catch (exception &e)
    {
        cout << e.what() << " 2. " << endl;
    }

    int id = cin.get();
    if (id == 49)
    {
        unexpected_handler oldHand = set_unexpected(Tfunction);
        unexpected();
    }
    else if (id == 50)
    {
        std::terminate_handler oldHand_t = std::set_terminate(termfunction);
        throw bad_alloc();
        // std::terminate();
    }
    else if (id == 51)
    {
        Test t1("outside try block");
        try
        {
            Test t2("inside try block");
            throw 1;
        }
        catch (...)
        {
        }
    }

    return 0;
}