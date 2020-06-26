#include <bits/stdc++.h>
#include <utility>
using namespace std;


struct Homework {
    int deadline;
    int score;

    Homework(int _deadline, int _score) : deadline(_deadline), score(_score) {}
};

bool dl_compare(struct Homework& h1, struct Homework& h2)
{
    return h1.deadline < h2.deadline;
}

bool score_compare(struct Homework& h1, struct Homework& h2)
{
    return h1.score > h2.score;
}

int max_dl(vector<Homework>& hws)
{
    int ret = hws[0].deadline;

    for(auto hw : hws)
    {
        if(hw.deadline > ret)
        {
            ret = hw.deadline;
        }
    }

    return ret;
}



class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n;
    vector<Homework> hws;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        for (int i = 0, deadline, score; i < n; i++) {
            fin >> deadline >> score;
            hws.push_back(Homework(deadline, score));
        }
        fin.close();
    }

    int get_result() {
        /*
        TODO: Aflati punctajul maxim pe care il puteti obtine planificand
        optim temele.
        */
        int last_dl = max_dl(hws);
        bool used[10];
        int score_final = 0;
        for(int i = 0; i < last_dl; i++)
        {
            used[i] = false;
        }

        sort(hws.begin(), hws.end(), score_compare);
        for(auto hw : hws)
        {
            cout << "(score, dl): " << hw.score << "," << hw.deadline << endl;
        }
        cout <<  "last deadline" << last_dl << endl;

        for(auto hw : hws)
        {
            for(int i = hw.deadline; i > 0; i--)
            {
                if(used[i])
                {
                    continue;
                }
                
                used[i] = true;
                score_final += hw.score;
                break;

            }
        }

        
        /*
        vector<pair<int, vector<int>>> hwMap;
        vector<int> dls;

        sort(hws.begin(), hws.end(), dl_compare);
        for(auto hw : hws)
        {
            cout << "(score, dl): " << hw.score << "," << hw.deadline << endl;
        }
        
        int prev_dl = hws[0].deadline;
        dls.push_back(prev_dl);

        for(auto hw : hws)
        {
           if(hw.deadline != prev_dl)
           {
               dls.push_back(hw.deadline);
               prev_dl = hw.deadline;
           }
        }
        pair<int, vector<int>> hw_dl;
        for(int i = 0; i < dls.size(); i++)
        {
            hw_dl.first = dls[i];
            for(hw : hws)
            {
                if(hw.deadline == hw_dl.first)
                {
                    (hw_dl.second).push_back(hw.score);
                }
                sort(hw_dl.second.begin(), hw_dl.second.end(), score_compare);
            }


            hwMap.push_back(hw_dl);
            hw_dl.second.clear();

        }
        for(auto map : hwMap)
        {
            cout << map.first << ": ";
            for(auto scr : map.second)
            {
                cout << scr << " "; 
            }
            cout << endl;
        }

        for(map : hwMap)
        {
            for(auto scr : map.second)
            {
                if((map.first - time) > 0)
                {
                    score_final += scr;
                    time++;
                    map.first = map.first - time;
                }
            }

        }
        */
        return score_final;
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
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
