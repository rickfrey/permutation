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
                                /* pass */;

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
        int k=4;
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
