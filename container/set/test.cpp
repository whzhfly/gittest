#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    set<int> a = {10, 20, 30, 40, 50, 60	};

    auto it = ++(++(++(++a.begin())));

    a.insert(it,35);
    for(auto i = a.begin(); i != a.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    a.insert(it,35);
    for(auto i = a.begin(); i != a.end(); ++i)
        cout << *i << ' ';
}

