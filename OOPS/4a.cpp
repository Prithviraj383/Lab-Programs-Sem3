#include <iostream>
using namespace std;

int main() {
    int count[6] = {0};   // count[1] to count[5] for candidates
    int spoilt = 0;
    int vote;

    cout << "Enter votes (1 to 5). Enter 0 to stop:\n";

    while (true) {
        cin >> vote;

        if (vote == 0)
            break;

        if (vote >= 1 && vote <= 5)
            count[vote]++;
        else
            spoilt++;
    }

    cout << "\nElection Results:\n";
    for (int i = 1; i <= 5; i++) {
        cout << "Candidate " << i << ": " << count[i] << " votes\n";
    }

    cout << "Spoilt ballots: " << spoilt << endl;

    return 0;
}
