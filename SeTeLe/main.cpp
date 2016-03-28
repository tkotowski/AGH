#include <iostream>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

void vectorTest() {
    cout << endl << endl;
    cout << "VECTOR" << endl;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(5);
    v.insert(v.begin() + 1, 7);
    v[0] = 9;
    v.push_back(v[0]);
    v.push_back(v[1]);
    cout << "found:" << *find(v.begin(), v.end(), 3) << endl;
    v.erase(find(v.begin(), v.end(), 3));
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << "min element: " << *min_element(v.begin(), v.end()) << endl;
    cout << "The size of v is: " << v.size() << "\nThe capacity of v is: " << v.capacity() << endl;
    cout << count(v.begin(), v.end(), 9) * 9 << endl;
        cout << "Sum of the first four: " << accumulate(v.begin(), v.begin() + 4, 0);
    vector<int>::const_iterator it;
    cout << "\nThe content of v is: ";
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void setTest() {
    cout << endl << endl;
    cout << "SET" << endl;
    set<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(7);
    s.insert(5);
    s.insert(7);
    s.erase(s.begin());
    s.insert(9);
    cout << "found " << *find(s.begin(), s.end(), 3) << endl;
    s.erase(find(s.begin(), s.end(), 3));
    cout << "minimal element: " << *min_element(s.begin(), s.end()) << endl;
    cout << "summ of nines: " << count(s.begin(), s.end(), 9) * 9 << endl;
    cout << "The size of s is: " << s.size() << "\nThe capacity of s is: " << s.max_size();
    set<int>::const_iterator it;
    cout << "\nThe content of s is: ";
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "summ of elements: " << accumulate(s.begin(), s.end(), 0) << endl;
}

typedef multimap<int, string, std::less<int> > mp_type;

void multimapTest() {
    cout << endl << endl;
    cout << "MULTITAP" << endl;

    mp_type mp;
    mp.insert(mp_type::value_type(2, "dwa"));
    mp.insert(mp_type::value_type(3, "trzy"));
    mp.insert(mp_type::value_type(4, "cztery"));
    mp.insert(mp_type::value_type(7, "siedem"));
    mp.insert(mp_type::value_type(5, "piec"));
    mp.insert(mp_type::value_type(7, "siedem"));
    mp.erase(mp.begin());
    mp.insert(mp_type::value_type(9, "dziewiec"));

    mp_type::iterator temp_iterator = mp.begin();
    mp.insert(*temp_iterator);
    temp_iterator++;
    mp.insert(*temp_iterator);
    mp.erase(mp.equal_range(3).first, mp.equal_range(3).second);

    cout << "minimal element: " << min_element(mp.begin(), mp.end())->first;
    cout << " " << min_element(mp.begin(), mp.end())->second << endl;

    cout << "liczba dziewiatek: " << mp.count(9) << endl;
    int summ = 0;
    mp_type::iterator iter = mp.begin();
    for(int i = 0; i < 4; i++) {
        summ += iter->first;
        iter++;
    }

    cout << "suma pierwszych czterech elementow: " << summ << endl;

    cout << "The size of mp is: " << mp.size() << "\nThe capacity of mp is: " << mp.max_size();
    mp_type::const_iterator it;
    cout << "\nThe content of mp is: \n";
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;

}
int main() {
    vectorTest();
    setTest();
    multimapTest();
    return 0;
}




