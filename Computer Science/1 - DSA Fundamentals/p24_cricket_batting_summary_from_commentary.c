#include<stdio.h>
#include<string.h>

struct Batsman {

    // Name of the batsman
    char name[100];

    // 'b' if the batsman got out. '*', if he is not out
    char is_out;

    // Name of the bowler who took the wicket
    char bowler[100];

    // Runs scored by the batsman
    int runs;

    // Number of balls faced by the batsman
    int balls;

};



int main() {
    printf( "\n" );

    FILE *file;
    file = fopen("input_cricket.txt", "r");

    if ( file == NULL ) {
        printf( "\nCould not open file!\n" );
    }

    // Number of commentary lines
    int number_of_lines;
    fscanf( file, "%d", &number_of_lines );

    char **cricket_data = (char**)malloc( number_of_lines );

    // Storing cricket data from the file, into the 2D character array
    for( int i = 0; i < number_of_lines; i++ ) {
        char *line = (char*)malloc( 1024 );
        fscanf( file, "%s", line ); // ??&
        cricket_data[i] = line;
        free(line);
    }

    // 11 batsman in a team
    struct Batsman **batsmen = (struct Batsman**)malloc(11 * sizeof(struct Batsman));

    // Initializing the 'batsmen' database
    for ( int i = 0; i < 11; i++ ) {
        struct Batsman *b;
        b->balls = 0;
        b->runs = 0;
        b->is_out = '*';

        batsmen[i] = b;
    }

    // Batsman number
    int B = 0;


    /*
    Format of each commentary line:
    'ball_number' 'bowler_name' to 'batsman_name', 'number_of_runs', 'commentary in words' 
    */

    for( int i = 0; i < number_of_lines; i++ ) {

        int j = 0; // Keeps track of character number in the line
        int k = 0; // Keeps track of the character index in word
        
        char word[100]; // We won't encounter a word with more than 100 characters
        char ball_number[5];
        char bowler_name[100];
        char batsman_name[100];
        char runs[10];
        

        char *line = cricket_data[i];

        
        // Finding the ball number
        while( line[j] != ' ' ) {
            word[k] = line[j];
            k++;
            j++;
        }
        strcat( ball_number, word );
        j++;

        // Emptying the word character array
        word[0] = '\0';
        k = 0;

        // Finding the name of the bowler
        while( line[j] != ' ' ) {
            word[k] = line[j];
            k++;
            j++;
        }
        strcat( bowler_name, word );
        j++;

        word[0] = '\0';
        k = 0;

        // Skipping the word "to"
        j++;
        j++;
        j++;

        // Finding the name of the batsman
        while ( line[j] != ',' ) {
            word[k] = line[j];
            k++;
            j++;
        }
        strcat( batsman_name, word );
        j++;
        j++; // Skip that space after the comma

        word[0] = '\0';
        k = 0;

        // Finding the number of runs scored in that ball
        while( line[j] != ',' ) {
            word[k] = line[j];
            k++;
            j++;
        }
        strcat( runs, word );
        j++;

        // Beyond this point, all we have is the commentary








        /*

        while( cricket_data[line][j] != EOF ) {

            if( cricket_data[line][j] == ' ' && found_ball == 0 ) {

                strcat(ball_number, word);
                word[0] = '\0'; // Empty the string
                found_ball = 1;

            }

            else if( cricket_data[line][j] == ' ' && found_bowler == 0 ) {

                strcat( bowler_name, word );
                word[0] = '\0';
                found_bowler = 1;

            }

            else if ( cricket_data[line][j] == ',' && found_batsman == 0 ) {

                strcat( batsman_name, word );
                word[0] = '\0';
                found_batsman = 1;
            }

            else if ( cricket_data[line][j] == ',' && found_runs == 0 ) {

                strcat( runs, word );
                word[0] = '\0';
                found_runs = 1;

                if ( strcmp(runs, "FOUR") == 0 ) {

                }

            }
            






            else if ( cricket_data[line][j] == ' ' ) {
                word[0] = '\0';
            }



            else {
                word[k] = cricket_data[line][j];
                k++;
            }

            j++;    
        }
        */

    }















    return 0;
}