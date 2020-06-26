#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    vector<int> dist;

    void read_input() {
        ifstream fin("in");
        fin >> n >> m;
        for (int i = 0, d; i < n; i++) {
            fin >> d;
            dist.push_back(d);
        }
        fin.close();
    }

    void print_dist()
    {
        for (auto d : dist)
        {
            cout << d << " ";
        }
    }
    int get_result() {
        /*
        TODO: Aflati numarul minim de opriri necesare pentru a ajunge
        la destinatie.
        */

        reverse(dist.begin(), dist.end());
        cout << "m = " << m << endl;
        print_dist();
        uint8_t i = 0, ret = 0;
        int place;

        while (i < dist.size())
        {
            if(dist[i] <= m)
            {
                break;
            }

            else
            {
                while(dist[i] > m)
                {
                    i++;
                    place = dist[i];
                }
                cout << "(i, place): " << i << "," << place << endl;

                ret++;

                for(uint8_t j = 0; j < dist.size() - i; j++)
                {
                    dist.pop_back();
                }

                for (uint8_t index = 0; index < dist.size(); index++)
                {
                    dist[index] = dist[index] - place;
                }

                i = 0;
            }
             
        }
        cout << "RESULT: " << ret << endl;
        return ret;
        
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
        fout.close();
    }
};

// Please always placeeep this simple main function!
int main() {
    // Allocate a Task object on heap in order to be able to
    // declare huge static-allocated data structures inside the class.
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
