// genetic algo inspired approach / local search (suggested by Adyansh Kakran xD)

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// === Parameters ===
#define INITIAL_THRESHOLD 80
#define NUM_SIMULATION_ROUNDS 300
#define TIME_THRESHOLD 0.95
#define AVG_THRESHOLD_FOR_5_MUTATIONS 85 // if the average is below this number, then mutate 5 states
#define AVG_THRESHOLD_FOR_3_MUTATIONS 90
#define AVG_THRESHOLD_FOR_1_MUTATION 100
#define GENERATED_DFA_NUM_STATES_LOWER 90
#define GENERATED_DFA_NUM_STATES_UPPER 110


int random_int(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

vector<vector<int>> generate_random_sol(int *size) {
    int lower = GENERATED_DFA_NUM_STATES_LOWER;
    int upper = GENERATED_DFA_NUM_STATES_UPPER;
    int n = random_int(lower, upper);
    *size = n;
    
    vector<vector<int>> dfa(n);

    for(int i = 0; i < n; i++) {
        int tmp = random_int(0,99);
        
        int c;
        if(tmp < 33) 
            c = 0;
        else if(tmp < 66)
            c = 1;
        else
            c = 2;

        int r = random_int(0, n-1);
        int p = random_int(0, n-1);
        int s = random_int(0, n-1);

        vector<int> row = {c, r, p, s};
        dfa[i] = row;
    }
    return dfa;
}

int beat_move(int move) {
    // returns the move that beats the input move
    // encode 0 = R, 1 = P, 2 = S
    if(move == 0) {
        return 1;
    } else if(move == 1) {
        return 2;
    } else if(move == 2) {
        return 0;
    }
    return -1;
}

bool did_i_win_the_round(int my_move, int opponent_move) {
    // encode 0 = R, 1 = P, 2 = S
    int what_i_need_to_win = beat_move(opponent_move);
    if(my_move == what_i_need_to_win) {
        return true;
    }
    return false;
}

float play_match(vector<vector<int>> my_dfa, int my_dfa_size, vector<vector<int>> opponent_dfa, int opponent_size) {
    // my_dfa will start at state 0, while the opponent will start from any initial state
    int total_score = 0;

    for(int ocs = 0; ocs < opponent_size; ocs++) {
        int score = 0;
        int opponent_current_state = ocs;
        int my_current_state = 0;

        for(int round = 0; round < NUM_SIMULATION_ROUNDS; round++) {

            int my_move = my_dfa[my_current_state][0];
            int opponent_move = opponent_dfa[opponent_current_state][0];

            bool w = did_i_win_the_round(my_move, opponent_move);
            if(w) {
                score++;
            }

            my_current_state = my_dfa[my_current_state][opponent_move+1];
            opponent_current_state = opponent_dfa[opponent_current_state][my_move+1];
        }

        total_score += score;
    }

    float average = (float) total_score * 100 / (NUM_SIMULATION_ROUNDS * opponent_size);
    return average;
}

void print_dfa(vector<vector<int>> dfa, int size) {
    cout << size << "\n";
    for(int i = 0; i < size; i++) {
        char ch;
        if(dfa[i][0] == 0)
            ch = 'R';
        else if(dfa[i][0] == 1)
            ch = 'P';
        else
            ch = 'S';
        cout << ch << " " << dfa[i][1] + 1 << " " << dfa[i][2] + 1 << " " << dfa[i][3] + 1 << "\n";
    }
}

void mutate_one_state(vector<vector<int>> &dfa, int size) {
    /*
    Randomly choses a state in the given dfa, and changes the move it's going to play
    */
    int state = random_int(0, size-1);
    int prev = dfa[state][0];
    int rand = random_int(0,2);
    while(rand == prev)
        rand = random_int(0,2);
    dfa[state][0] = rand;
}

void mutate_one_transition(vector<vector<int>> &dfa, int size) {
    /*
    Mutate the transition from any state, to any other state (via any move)
    */
    int state = random_int(0, size-1);
    int which_transition = random_int(0,2);

    int prev = dfa[state][which_transition+1]; // so that you don't get the same transition destination
    
    int rand = random_int(0, size-1);
    while(rand == prev) {
        rand = random_int(0, size-1);
    }

    dfa[state][which_transition+1] = rand;
}

vector<vector<int>> mutate_dfa(vector<vector<int>> dfa, int size, float average) {
    /*
    Mutate the dfa depending on how it's performing.
    If it is performing well, mutate less
    */
    vector<vector<int>> mutated_dfa = dfa;
    if(average < AVG_THRESHOLD_FOR_5_MUTATIONS) {
        for(int i = 0; i < 5; i++) {
            int choice = random_int(0,1);
            if(choice)
                mutate_one_state(mutated_dfa, size);
            else
                mutate_one_transition(mutated_dfa, size);
        }
    }

    else if(average < AVG_THRESHOLD_FOR_3_MUTATIONS) {
        for(int i = 0; i < 3; i++) {
            int choice = random_int(0,1);
            if(choice)
                mutate_one_state(mutated_dfa, size);
            else
                mutate_one_transition(mutated_dfa, size);
        }
    }

    else if(average < AVG_THRESHOLD_FOR_1_MUTATION) {
        for(int i = 0; i < 1; i++) {
            int choice = random_int(0,1);
            if(choice)
                mutate_one_state(mutated_dfa, size);
            else
                mutate_one_transition(mutated_dfa, size);
        }
    }

    return mutated_dfa;
}

int main() {
    clock_t start_time = clock();
    srand(time(0));

    int n;
    cin >> n;
    // encode 0 = R, 1 = P, 2 = S
    vector<vector<int>> opponent(n);
    
    for(int i = 0; i < n; i++) {
        vector<int> row(4);
        char c;
        int r, p, s;
        cin >> c >> r >> p >> s;
        int move = 0;
        if(c == 'P') {
            move = 1;
        }
        if(c == 'S') {
            move = 2;
        }
        row[0] = move;
        row[1] = r-1;
        row[2] = p-1;
        row[3] = s-1;
        opponent[i] = row;
    }

    vector<vector<int>> my_dfa;
    int my_dfa_size;

    vector<vector<int>> best_dfa;   
    int best_dfa_size;

    float avg = 0;
    float best_avg = 0;

    clock_t current_time = clock();
    float time_taken = (current_time - start_time) / CLOCKS_PER_SEC;

    // keep running till you cross the initial threshold, or the time threshold
    while(avg < INITIAL_THRESHOLD && time_taken < TIME_THRESHOLD) {
        my_dfa = generate_random_sol(&my_dfa_size);
        avg = play_match(my_dfa, my_dfa_size, opponent, n);

        if(avg > best_avg) {
            best_dfa = my_dfa;
            best_avg = avg;
            best_dfa_size = my_dfa_size;
        }

        current_time = clock();
        time_taken = (current_time - start_time) / CLOCKS_PER_SEC;
    }

    // cout << "chosen dfa avg: " << best_avg << "\n";

    current_time = clock();
    time_taken = (current_time - start_time) / CLOCKS_PER_SEC;

    // keep mutating to find a better DFA until you reach the time threshold
    while(time_taken < TIME_THRESHOLD) {
        vector<vector<int>> mutated_dfa = mutate_dfa(best_dfa, best_dfa_size, best_avg);
        float new_avg = play_match(mutated_dfa, best_dfa_size, opponent, n);
        
        if(new_avg > best_avg) {
            best_dfa = mutated_dfa;
            best_avg = new_avg;
        }

        current_time = clock();
        time_taken = (current_time - start_time) / CLOCKS_PER_SEC;
    }

    // cout << "avg after mutation: " << best_avg << "\n";
    
    print_dfa(best_dfa, best_dfa_size);

    return 0;
}
