#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "begin()" << endl;
    auto it = vi.begin();
    *it *= 10; // 1 * 10
    cout << *it;
    while (++it != vi.end()) {
        *it *= 10; // 2 * 10, 3 * 10, ..., 10 * 10
        cout << ' ' << *it;
    }
    // Output: 10 20 30 40 50 60 70 80 90 100
    cout << '\n' << endl;

    cout << "rbegin()" << endl;
    auto rit = vi.rbegin();
    *rit *= 10;
    cout << *rit;
    while (++rit != vi.rend()) {
        *rit *= 10;
        cout << ' ' << *rit;
    }
    // Output: 1000 900 800 700 600 500 400 300 200 100
    cout << '\n' << endl;

    cout << "cbegin()" << endl;
    auto cit = vi.cbegin();
    // *cit *= 10; // error: assignment of read-only location ‘cit.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()’
    cout << *cit;
    while (++cit != vi.cend()) {
        // *cit *= 10; // error: assignment of read-only location ‘cit.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()’
        cout << ' ' << *cit;
    }
    // Output: 100 200 300 400 500 600 700 800 900 1000
    cout << '\n' << endl;

    cout << "crbegin()" << endl;
    auto crit = vi.crbegin();
    // *crit *= 10; // error: assignment of read-only location ‘cit.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()’
    cout << *crit;
    while (++crit != vi.crend()) {
        // *crit *= 10; // error: assignment of read-only location ‘cit.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()’
        cout << ' ' << *crit;
    }
    // Output: 1000 900 800 700 600 500 400 300 200 100

    return 0;
}