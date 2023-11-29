#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;
class myRandom // 创建一个可产生随机数的仿函数
{
public:
    ptrdiff_t operator()(ptrdiff_t max)
    {
        double tmp;
        tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        return static_cast<ptrdiff_t>(tmp * max);
    }
};
int main()
{
    vector<int> v1;
    int dim[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    v1.assign(dim, dim + 9);
    cout << "vector v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    // 输出最初的 vector 型容器中的元素
    cout << endl;
    random_shuffle(v1.begin(), v1.end());
    cout << "vector v1 (random ): ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl; // 输出打乱顺序后的 vector 型容器中的元素
    sort(v1.begin(), v1.end());
    cout << "vector v1 (sorted again ): ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl; // 输出排序后的 vector 型容器中的元素
    myRandom mrd;
    random_shuffle(v1.begin(), v1.end(), mrd);
    cout << "vector v1 (shuffled again ): ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl; // 输出第二次打乱顺序后的 vector 型容器中的元素
    return 0;
}