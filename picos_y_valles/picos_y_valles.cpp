/*
* Solucion aportada por el profesor de la FdI (UCM):
* Solution given by FdI's (UCM) professor:
*   ANTONIO ALEJANDRO SANCHEZ RUIZ-GRANADOS
* Editada y completada por:
* Edited and completed by:
*   JAIME B.
*/
#include <iostream>
#include <vector>

using namespace std;

// true
void peaks_and_valleys(const vector<int>& v, int& peaks, int& valleys) {
    peaks = valleys = 0;

    // Inv: 1 <= i <= v.size() and 
    //      peaks = #j: 1 <= j < i: v[j-1] < v[j] > v[j+1] and 
    //      valleys = #k: 1 <= k <i: v[k-1] > v[k] < v[k+1]
    // T: v.size() - i
    for (int i = 1; i < v.size() - 1; ++i) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1])
            ++peaks;

        if (v[i - 1] > v[i] && v[i] < v[i + 1])
            ++valleys;
    }
}
// peaks = #j: 1<=j<v.size()-1: v[j-1] < v[j] > v[j+1] and 
// valleys = #k: 1<=k<v.size()-1: v[k-1] > v[k] < v[k+1]

/*COMPLEJIDAD DEL ALGORITMO
*   Sabemos que todas las instrucciones ejecutadas tienen coste constante.
*
*   Existe un bucle dentro del algoritmo que ejecuta instrucciones de coste
*   constante para, en el peor de los casos, todos los elementos del vector
*   v.
*
*   Por ello, definiendo n como el numero de elementos del vector v, podemos
*   afirmar que el coste del algoritmo será:
*
*       O(n)
*/
/*COMPLEXITY OF THE ALGORITHM
*   We know all executed instructions belong to O(1).
*
*   Inside our algorithm exists a loop, which executes instructions of constant
*   cost for, in the worst case scenario, every element of vector v.
*
*   Therefore, defining n as the number of elements of vector v, we can affirm
*   that the cost of our algorithm equals to:
*
*       O(n)
*/

void solve() {
    // read case
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute and write the solution
    int peaks, valleys;
    peaks_and_valleys(v, peaks, valleys);
    cout << peaks << " " << valleys << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve();

    return 0;
}