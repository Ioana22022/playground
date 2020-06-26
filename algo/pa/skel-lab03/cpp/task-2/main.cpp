#include <bits/stdc++.h>
using namespace std;

struct Result {
    int len;
    vector<int> subsequence;
};

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    vector<int> v;
    vector<int> w;

    void read_input() {
        ifstream fin("in");
        fin >> n >> m;

        v.push_back(-1); // adaugare element fictiv - indexare de la 1
        for (int i = 1, e; i <= n; i++) {
            fin >> e;
            v.push_back(e);
        }

        w.push_back(-1); // adaugare element fictiv - indexare de la 1
        for (int i = 1, e; i <= m; i++) {
            fin >> e;
            w.push_back(e);
        }

        fin.close();
    }

    Result get_result() {
        Result result;
        result.len = 0;

        /*
        TODO: Aflati cel mai lung subsir comun intre v (de lungime n)
        si w (de lungime m).
        Se puncteaza separat urmatoarele 2 cerinte:
        2.1. Lungimea CMLSC. Rezultatul pentru cerinta aceasta se va pune in
        ``result.len``.
        2.2. Reconstructia CMLSC. Se puncteaza orice subsir comun maximal valid.
        Solutia pentru aceasta cerinta se va pune in ``result.subsequence``.
        */

        return result;
    }

    void print_output(Result result) {
        ofstream fout("out");
        fout << result.len << '\n';
        for (int x : result.subsequence) {
            fout << x << ' ';
        }
        fout << '\n';
        fout.close();
    }
};

// Please always keep this simple main function!
int main() {
    // Allocate a Task object on heap in order to be able to
    // declare huge static-allocated data structures inside the class.
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
