#include <iostream>
#include <fstream>

using namespace std;

int time[100000000];

ifstream fin("C:\\Users\\CLionProjects\\ds\\1.in");
ofstream fout("C:\\Users\\CLionProjects\\ds\\1.out");

int main() {
    int n;
    int max;

    fin >> n;
    int start[n];
    int end[n];

    for (int i = 0; i < n; i++) {
        fin >> start[i] >> end[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = start[i]; j < end[i]; j++) {
            time[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int a = start[i]; a < end[i]; a++) {
            time[a]--;
        }
        for ( int j = 0; j < 100000000; j++){
            if (time[j] > 0) {
                temp++;
            }
        }
        for (int j = start[i]; j < end[i]; j++) {
            time[j]++;
        }
        if (temp > max) {
            max = temp;
        }
    }
    fout << max;
    return 0;
}