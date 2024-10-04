#include <iostream>
#include <vector>
using namespace std;

// Find all combinations of scores
void findCombinations(int score) {
    // Assign Points
    const int TD = 6;
    const int FG = 3;
    const int Safety = 2;
    const int TD_2pt = 8;
    const int TD_FG = 7;

    cout << "Possible combinations of scoring plays if a team’s score is " << score << ":\n";

    // Gi through all points
    for (int td_2pt = 0; td_2pt <= score / TD_2pt; ++td_2pt) {
        for (int td_fg = 0; td_fg <= (score - td_2pt * TD_2pt) / TD_FG; ++td_fg) {
            for (int td = 0; td <= (score - td_2pt * TD_2pt - td_fg * TD_FG) / TD; ++td) {
                for (int fg = 0; fg <= (score - td_2pt * TD_2pt - td_fg * TD_FG - td * TD) / FG; ++fg) {
                    int remainingScore = score - (td_2pt * TD_2pt + td_fg * TD_FG + td * TD + fg * FG);
                    if (remainingScore % Safety == 0) {
                        int safety = remainingScore / Safety;
                        cout << td_2pt << " TD + 2pt, "
                            << td_fg << " TD + FG, "
                            << td << " TD, "
                            << fg << " 3pt FG, "
                            << safety << " Safety\n";
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    // Loop until 1 or 0
    do {
        cout << "Enter 0 or 1 to STOP\n";
        cout << "Enter the NFL score: ";
        cin >> score;

        if (score > 1) {
            findCombinations(score);
        }

    } while (score > 1);

    return 0;
}
