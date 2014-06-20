#include <iostream>
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
    cout<<"Test: people["<<i<<"]= "<<people[i]<<endl;
    cout<<"Test: combination["<<i<<"]= "<<combination[i]<<endl;
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
