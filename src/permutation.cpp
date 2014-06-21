/*#include <iostream>
#include <vector>

using namespace std;

// Es gibt n Menschen, ausgegeben werden alle möglichen Kombinationen von k der gesamten Menschen (k aus n)
// Ich muss für jede Kombination alle möglichen Permutationen durchspielen!

// QUELLE: http://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c

vector<int> people;
vector<int> combination;

void pretty_print(const vector<int>& v) {                   // Hier irgendwas mit std::next_permutation (#include <algorithm>) programmieren, um alle Reihenfolgen zu ermitteln
  static int count = 0;
  cout << "combination no " << (++count) << ": [ ";
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
  cout << "] " << endl;
}

void go(int offset, int k) {
  if (k == 0) {                                             //
    pretty_print(combination);
    return;
  }
  for (int i = offset; i <= people.size() - k; ++i) {       // 3. Schleife von 0 bis (n-k)
    combination.push_back(people[i]);                       // 4. Vektor "combination": i-te Stelle wird mit people[i] gefüllt
                                                        //cout<<"Test: people["<<i<<"]= "<<people[i]<<endl;
                                                        //cout<<"Test: combination["<<i<<"]= "<<combination[i]<<endl;
    go(i+1, k-1);
    combination.pop_back(); // pop_back verkleinert Vektor um eine Stelle
  }
}

int main() {
  int n = 5, k = 3;

  for (int i = 0; i < n; ++i) { people.push_back(i+1);}     // 1. Hier wird lediglich Vektor people mit 1,2,3,4...bis n gefüllt
  go(0, k);                                                 // 2. Aufruf der Funktion go mit k als Parameter

  return 0;
}
*/
/*
#include <vector>
#include <iostream>
#include <algorithm>

// http://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation

using namespace std;

template<typename It>
bool next_permutation(It begin, It end)
{
        if (begin == end)
                return false;

        It i = begin;
        ++i;
        if (i == end)
                return false;

        i = end;
        --i;

        while (true)
        {
                It j = i;
                --i;

                if (*i < *j)
                {
                        It k = end;

                        while (!(*i < *--k))
                                /* pass *//*;

                        iter_swap(i, k);
                        reverse(j, end);
                        return true;
                }

                if (i == begin)
                {
                        reverse(begin, end);
                        return false;
                }
        }
}

int main()
{
        vector<int> v;// = { 1, 2, 3, 4 };
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        int k=3;
        int count=0;
        do
        {
                for (int i = 0; i < k; i++)
                {
                        cout << v[i] << " ";

                }
                //int count=0;
                //count++;
                cout << endl;
                //count++;
        }
        while (::next_permutation(v.begin(), v.end()));
}
*/
/*
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

template<class T>
void print(const std::vector<T> &vec)
{
    for (typename std::vector<T>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        std::cout << *i;
        if ((i + 1) != vec.end())
            std::cout << ",";
    }
    std::cout << std::endl;
}

int main()
{
    //Permutations for strings
    std::string example("Hello");
    std::sort(example.begin(), example.end());
    do {
        std::cout << example << '\n';
    } while (std::next_permutation(example.begin(), example.end()));

    // And for vectors
    std::vector<int> another;
    another.push_back(1234);
    another.push_back(4321);
    another.push_back(1234);
    another.push_back(9999);

    std::sort(another.begin(), another.end());
    do {
        print(another);
    } while (std::next_permutation(another.begin(), another.end()));

    return 0;
}*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;

void print()
{
    //for(int i=0; i<vec.size(); i++)
    //    cout << vec[i] << " ";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << "\t";
    cout << endl;
}

int main()
{
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);

    for(int i = 1; i <= vec.size() ; i++) {
        //vec.push_back(i);
        cout << vec[i-1] << "\t";
    }

    cout << endl;

    while(next_permutation(vec.begin(), vec.end()) ){
        print();
        // do some processing on vec
    }

    return 0;
}
