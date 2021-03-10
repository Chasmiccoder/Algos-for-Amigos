/*
Program to Convert Infix expressions to their Postfix or Prefix form, and to evaluate
the Postfix and Prefix expressions.

Author: Aryaman Kolhe
Date: 08-March-2021
*/

/*
    TO DO:
    - Create Help menu
    - Implement balanced bracket check as well
    - Make the whole thing menu driven
    - Manually calculate the answer to the sample questions, and cross verify the answers with this program
*/

#include <iostream>
#include <string>
#include <vector>

#define PB push_back
#define MP make_pair

using namespace std;

vector<string> push( vector<string> vi, string element, int top );
void print_vector( vector<string> vi, string name_of_vector );
string string_trim( string str );

vector<string> push( vector<string> vi, string element, int top ) {
    
    if ( vi.empty() ) {
        vi.push_back( element );
        return vi;
    }
    else if ( top < vi.size() ) {
        vi.push_back( element );
    }
    
    vi[ top+1 ] = element;
    return vi;
}

void print_vector( vector<string> vi, string name_of_vector ) {
    printf( "Printing Vector: "  );
    cout << name_of_vector << "\n";

    int size = vi.size();
    printf( "Size:%d\n", size );

    for ( int i = 0; i < size; i++ ) {
        cout << vi[i] << endl;
    }
    printf( "------------\n" );
}

string string_trim( string str ) {
    
    int length = str.length();
    int i = 0;
    int start_point = 0;
    while ( i < length ) {
        string character = str.substr( i,1 );
        if ( character != " " ) {
            start_point = i;
            break;
        }
        i++;
    }
    
    i = length-1;
    int end_point = 0;
    while ( i >= 0 ) {
        string character = str.substr( i,1 );
        if ( character != " " ) {
            end_point = i;
            break;
        }
        i--;
    }

    string new_str = str.substr( start_point, end_point - start_point + 1 );
    return new_str;
}

class Conversion {
    /*
    Contains the variables and methods required to convert a string expression given in infix format
    to either prefix or postfix format
    Vars:


    Methods:


    //////Inherited Methods Used form the Stack class:



    */
    
    private:
        int number_of_operators;
        vector< pair< pair< string, string >, int > > vi_operator; // operator vector
        // vi_operator.first.first gives us the operator
        // vi_operator.first.second gives us the associativity
        // vi_operator.second gives us the precedence
        
        
    
    public:
        Conversion() {
            
            // Using macros PB for push_back and MP for make_pair
            vi_operator.PB( MP( MP( "^", "right"), 0 ) );
            vi_operator.PB( MP( MP( "*", "left"), 1 ) );
            vi_operator.PB( MP( MP( "/", "left"), 1 ) );
            vi_operator.PB( MP( MP( "%", "left"), 1 ) );
            vi_operator.PB( MP( MP( "+", "left"), 2 ) );
            vi_operator.PB( MP( MP( "-", "left"), 2 ) );
            vi_operator.PB( MP( MP( "=", "right"), 3 ) );

            number_of_operators = vi_operator.size();
        }

        vector<int> getPriorityAndAssociativity( string operator_ ) {
            // Returns the priority index (lesser the index, more the priority), and the associativity 
            // of an operator. Returns -1 if the operator does not exist in the operator vector.
            
            for ( int i = 0; i < number_of_operators; i++ ) {
                if ( vi_operator[i].first.first == operator_ ) {
                    vector<int> vi;
                    vi.push_back( vi_operator[i].second ); //FIX ASSOCIATIVIT!>!>!??????????????????
                    if ( vi_operator[i].first.second == "left" ) {
                        vi.push_back( 1 );
                    }
                    else {
                        vi.push_back( 0 ); // Right Associativity
                    }
                    return vi;
                }

            }
            vector<int> vi;
            vi.push_back( -1 );
            vi.push_back( -1 );
            return vi;
        }


        int precedence( string ICO, string ISO ) {
            // Returns 0 if ico < iso. 1 if ico > iso. If they have the same priority, it checks
            // for associativity. Basically, if we want to push to the stack, 1 is returned. 
            // For the continuous pop operation, 0 is returned.
            vector<int> ico_precedence = getPriorityAndAssociativity( ICO );
            vector<int> iso_precedence = getPriorityAndAssociativity( ISO );

            //cout << "E: " << ICO << " " << ISO << endl;

            if ( ico_precedence[0] < iso_precedence[0] ) {
                // Lesser the index of precedence, greater the priority
                return 1;
            }
            // if |a| = 0, we can get either no solution, or infinitely many solutions
            else if ( ico_precedence[0] == iso_precedence[0] ) {
                if ( ico_precedence[1] == 1  ) { 
                    return 0; // Left associativity, which means that ico < iso, so we want to perform the pop operation
                }                // FIX THE LOGIC IN THESE COMMENT LINES!
                return 1; // Right associativity, which means that ico > iso, so we want to push it into the stack
            }
            else {
                
                return 0;
            }
        }

        vector<string> getSymbols( string expression ) { //*** = Seems okay for now
            // Breaks the input expression into its fundamental symbols
            int expression_length = expression.length();
            vector<string> symbols;
            
            int start_index = 0;
            for ( int i = 0; i < expression_length; i++ ) {
                string character = expression.substr( i,1 );
                //cout << "Character: " << character << endl;

                // Store a symbol if we encounter a space
                if ( character == " " ) {
                    
                    
                    string one_symbol = expression.substr( start_index, i-start_index );

                    //cout << "Symbol: " << one_symbol << endl;
                    
                    symbols.push_back( one_symbol );
                    start_index = i+1;
                }

                // Store the last symbol if we encounter the end of the expression
                else if ( i == expression_length - 1 ) {
                    string one_symbol = expression.substr( start_index, i-start_index+1 );
                    //cout << "Symbol: " << one_symbol << endl;
                    symbols.push_back( one_symbol );

                }

            } 

            return symbols;
        }

        bool notOperand( string symbol ) {
            for ( int i = 0; i < number_of_operators; i++ ) {
                if ( vi_operator[i].first.first == symbol ) 
                    return false;
            }
            if ( symbol == "(" || symbol == ")" ) {
                return false;
            }
            return true;
        }

        string convert_infix_to_postfix( string expression );
        string convert_infix_to_prefix( string expression );

};


string Conversion::convert_infix_to_postfix( string expression ) {
    /*
    A symbol is just the smallest element in the expression
    Introducing symbols to account for variables and integers that have more than one characters
    */
    

    // Vector with all Symbols to be parsed
    vector<string> symbols = getSymbols( expression );
    
    // Number of symbols to be parsed
    int number_of_symbols = symbols.size();


    // Number of characters in the expression
    int expression_length = expression.length();
    
    // Final output
    string postfix_expression = "";

    // Operation Stack
    //Stack stack_Class;
    vector<string> stack; // Operation Stack
    //int top = -1;

    //vector<string> stack = stack_Class.outputStack();
    //int top = stack_Class.outputTop(); //This is not working, top is not getting updated dynamically
    int top = -1;

    // Loop variable that keeps track of which symbol is under consideration
    int i = 0;
    while ( i < number_of_symbols ) {
    
        
        
        string symbol = symbols[i];

        // THESE TWO LINES ARE VITAL FOR DEBUGGIN'
        //cout << "Symbol: " << symbol << endl;
        //print_vector( stack, "OperationStack" );
    
        if ( notOperand( symbol ) ) {
            // If the symbol is a number or a variable, send it to the output
            postfix_expression += " " + symbol;
        }
        else {
            
            
            bool check_top = true; // give this var a meaningful name
            bool check_precedence = false;
            string top_symbol = "";
            if ( top == -1 ) {
                // If there is nothing in the operation stack, push the operator into the stack
                
                //stack_Class.push( symbol );   
                stack = push( stack, symbol, top );
                top++;
                
                
                check_top = false;
            }
            else {
                top_symbol = stack[ top ];
            }
            
            //print_vector( stack, "OperationStack" );
            //printf( "here;%d\n", symbol == "(" );

            // Accounting for parenthesis
            if ( symbol == "(" && check_top ) {
                check_top = false;
                //stack_Class.push( symbol );
                
                stack = push( stack, symbol, top );
                top++;
                
            }
            
            
            if ( symbol == ")" ) {
                check_top = false;
                while ( top_symbol != "(" ) {

                    string operator_ = stack[ top ];
                    stack.pop_back();
                    top--;
                    postfix_expression += " " + operator_;
                    top_symbol = stack[ top ];
                }
                // We need to pop once more to remove "("
                stack.pop_back();
                top--;
            }
            
            if ( top_symbol == "(" && symbol != ")" && check_top ) {
                check_top = false;
                stack = push( stack, symbol, top );
                top++;
            }

            int ico_greater_than_iso = precedence( symbol, top_symbol ); // 1 if true

            //printf("E:\n");
            //cout << "ICO: " << symbol << " ISO: " << top_symbol << endl;
            //printf( "prec: %d\n", ico_greater_than_iso );
            
            
            if ( ico_greater_than_iso == 1 && check_top  ) {
                check_top = false;
                stack = push( stack, symbol, top );
                top++;
            }
            

            // This loop will pop elements of the operation stack until precedence of ICO > ISO
            while ( check_top && ico_greater_than_iso == 0 )  {
                //cout << "ICO: " << symbol << " ISO: " << top_symbol << endl;
                // pop operation
                check_precedence = true;

                
                
                // To be, or not to be?
                string to_be_outputted = stack[ top ];
                
                stack.pop_back();
                
                top--;
                postfix_expression += " " + to_be_outputted;

                if ( top == -1 ) {
                    break;
                }
                
                top_symbol = stack[ top ];
                //printf("SATHP?\n");
                

                if ( top_symbol == "(" ) { //HANDLE THIS
                    break;
                }
                //cout << "ICO: " << symbol << " ISO: " << top_symbol << endl;
                ico_greater_than_iso = precedence( symbol, top_symbol );
                //printf("Q:%d\n", ico_greater_than_iso);
            }
            //printf("D:\n");
            
            if ( check_precedence ) {
                // The ico element must get pushed at the end of the pop operation
                stack = push( stack, symbol, top );
                top++;
            }

            
            
        }

        i++;
        
    }
    
    
    //printf( "top: %d\n", top );

    // After parsing all the symbols we can push the operation stack's elements to the output
    while ( top > -1 ) {
        //sprintf( "ENTE\n" );
        
        string operator_ = stack[ top ];
        stack.pop_back();

        //printf( "OPERATOR:" );
        //cout << operator_ << endl;
        postfix_expression += " " + operator_;
        top--;
    }

    postfix_expression = string_trim( postfix_expression );

    return postfix_expression;    
}

class Evaluation {
// Use Hash Maps for input values of variables
};


int main() {


    string infix;
    int max_length_of_string = 100;
    printf( "Enter Expression:\n" );
    getline( cin, infix ); // Cannot use scanf(), since we want the input string to include spaces
    //infix = "1 * ( 2 - 3 + 4 ) ^ 5 / ( 6 * 7 + 8 )";
    
    Conversion convert_Class;
    string postfix = convert_Class.convert_infix_to_postfix( infix );

    printf( "Postifix Expression:\n" );
    cout << postfix << "\n";


    return 0;
}

/*
Test Expressions:
passed = The given testcase gave the right output


1. Infix -
1 * ( 2 - 3 + 4 ) ^ 5 / ( 6 * 7 + 8 )
Postfix - (passed)
1 2 3 - 4 + 5 ^ * 6 7 * 8 + /


2. Infix -
a = b + c * 10
Postfix - (passed)
a b c 10 * + =


3. Infix -
w + f ^ g - h / ( a + b )
Postfix - (passed)
w f g ^ + h a b + / -

4. Infix -
( ( a * b - ( c + d ) ) ) ^ e / ( f * g + h )
Postfix - (passed)
a b * c d + - e ^ f g * h + /

5. Infix -
a - b ^ c + f ^ g / h * g ^ 1
Postfix - (passed)
a b c ^ - f g ^ h / g 1 ^ * +

6. Infix -
( ( a + b ) * ( b + c - d * f ) ) / ( 1 + 2 )
Postfix - (passed)
a b + b c + d f * - * 1 2 + /





*/
