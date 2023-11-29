#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main()
{
    int dim[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double Vdim[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    std::vector<int> v1;
    std::list<int> l1;
    v1.assign(dim, dim + 9);
    std::copy(Vdim, Vdim + 9, std::back_inserter(l1));

    std::cout << "vector v1: " << std::endl;
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::cout << "list l1: " << std::endl;
    std::copy(l1.begin(), l1.end(), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;

    std::vector<int>::iterator itV = v1.end();
    --itV;
    std::iter_swap(v1.begin(), itV);

    std::cout << "vector v1 (swap first): " << std::endl;
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::list<int>::iterator itLs = l1.begin();
    std::advance(itLs, 2);
    std::list<int>::iterator itLe = std::next(l1.end(), -3);
    std::iter_swap(itLs, itLe);

    std::cout << "list l1 (swap first): " << std::endl;
    std::copy(l1.begin(), l1.end(), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;

    itV = v1.begin();
    std::iter_swap(itV, itLs);

    std::cout << "vector v1 (swap second): " << std::endl;
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::cout << "list l1 (swap second): " << std::endl;
    std::copy(l1.begin(), l1.end(), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;

    return 0;
}