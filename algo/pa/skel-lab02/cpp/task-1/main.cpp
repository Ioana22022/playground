#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Object {
    int weight;
    int price;

    Object(int _weight, int _price) : weight(_weight), price(_price) {}
};

bool ratio_compare(Object &o1, Object &o2)
{
    double r1 = (double) (o1.price * o2.weight);
    double r2 = (double) (o2.price * o1.weight);
    
    return (r1 > r2);
}

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, w;
    vector<Object> objs;

    void read_input() {
        ifstream fin("in");
        fin >> n >> w;
        for (int i = 0, weight, price; i < n; i++) {
            fin >> weight >> price;
            objs.push_back(Object(weight, price));
        }
        fin.close();
    }


    double get_result() {
        /*
        TODO: Aflati profitul maxim care se poate obtine cu obiectele date.
        */
        double prft = 0.0;
        sort(objs.begin(), objs.end(), ratio_compare);
        cout << "Weight: " << w << endl;
       
        for(auto obj : objs)
        {
            cout << "(" << obj.price << ", " << obj.weight << ")"  << endl;
            if(obj.weight > w)
            {
                cout << "IF " << endl;

                double prft1 = (double) (w * obj.price);
                prft1 /= obj.weight; 
                prft += prft1;
                break;
            }

            else
            {
                prft += obj.price;
                w = w - obj.weight;
            }

        }

        return prft;
    }

    void print_output(double result) {
        ofstream fout("out");
        fout << setprecision(4) << fixed << result;
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
