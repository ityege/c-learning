#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;
int main()
{
    int dim[] = {1, 2, 4, 6, 5, 8, 7, 9, 3}; // 初始数组，用来初始化 vector 型和 deque 型容器
    vector<int> v1, v2, v3(9);
    deque<int> d1, d2, d3(9);
    v1.assign(dim, dim + 9);                       // 初始化 v1
    copy(v1.begin(), v1.end(), back_inserter(d1)); // 初始化 d1
    cout << " Dim (Original) is below : " << endl;
    copy(dim, dim + 9, ostream_iterator<int>(cout, ", ")); // 输出数组 dim
    cout << endl;
    cout << " vector v1 (Original) is below : " << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", ")); // 输出 v1
    cout << endl;
    cout << " deque d1 (Original) is below : " << endl;
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, ", ")); // 输出 d1
    cout << endl;
    v2 = v1;
    d2 = d1;
    partial_sort(v1.begin(), v1.begin() + 5, v1.end()); // 局部排序 v1 的前 5 个元素
    cout << " vector v1 is sorted by the partial_sort() algorithm . : " << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", ")); // 输出局部排序之后的 v1 的结果
    cout << endl;
    partial_sort(d1.begin(), d1.begin() + 5, d1.end()); // 局部排序 d1
    cout << " deque d1 is sorted by the partial_sort() algorithm . : " << endl;
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, ", "));
    // 输出局部排序之后的 d1
    cout << endl;
    cout << " - - - - - - - - - - - - - - - - - " << endl;
    cout << " vector v2 is as same as the original v1 : " << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ", "));
    // 输出 v2 和 v1 的初始内容相似
    cout << endl;
    cout << " deque d2 is as same as the original d1: " << endl;
    // 输出 d2 的内容和 d1 的初始内容相似
    copy(d2.begin(), d2.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    partial_sort(v2.begin(), v2.begin() + 5, v2.end(), greater<int>());
    // 对 v2 的前 5 个元素进行降序排序
    cout << " vector v2 is sorted by the partial_sort() algorithm ( 降序 )) . : " << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ", "));
    // 输出降序排序之后的 v2
    cout << endl;
    partial_sort(d2.begin(), d2.begin() + 5, d2.end(), greater<int>());
    // 降序排序 d2 的前 5 个元素
    cout << " deque d2 is sorted by the partial_sort() algorithm ( 降序 ) ) . : " << endl;
    copy(d2.begin(), d2.end(), ostream_iterator<int>(cout, ", "));
    // 输出排序后的 d2
    cout << endl;
    partial_sort_copy(dim, dim + 9, v3.begin(), v3.end());
    // 对初始数组 dim 排序， 并复制到 v3 中
    cout << " vector v3 (partial_sorted ( 默认升序 )) . : " << endl;
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, ", "));
    // 输出 v3
    cout << endl;
    partial_sort_copy(v3.begin(), v3.end(), d3.begin(), d3.end(), greater<int>()); // 对 v3进行降序排序， 并复制到 d3 中
    cout << " deque d3 (partial_sorted ( 降序 )) . : " << endl;
    copy(d3.begin(), d3.end(), ostream_iterator<int>(cout, ", "));
    // 输出 d3
    cout << endl;
    return 0;
}
