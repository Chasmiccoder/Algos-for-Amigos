/*
Program to Convert Infix expressions to their Postfix or Prefix form, and to evaluate
the Postfix and Prefix expressions.

Author: Aryaman Kolhe
Start Date: 08-March-2021
*/

/*
    TO DO:
    - Account for decimal points during evaluation
    - Implement expression evaluation
    - Create a testing suite with known inputs and outputs
    - Implement balanced bracket check as well
*/


#include <iostream>
#include <string>
#include <vector>
#include <math.h>


// Macros that make defining the operator vector easy
#define PB push_back
#define MP make_pair


using namespace std;


vector<string> push( vector<string> vi, string element, int top );
void print_vector( vector<string> vi, string name_of_vector );
string string_trim( string str );
string string_reverse( vector<string> str_symbols );
string string_swap_parentheses( string str );


vector<string> push( vector<string> vi, string element, int top ) {
    /*
    Function performs push operation on a stack
    Note! Top element must be incremented after using this separately
    
    Arguments -
    vector<string> vi = Vector to which push should be performed
    string element    = Element to be pushed
    int top           = Top pointer of stack vi

    Return Value -
    vector<string> vi = Stack after push is performed

    */
    
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
    /*
    Function prints a vector in sequence
    Mainly used for debugging

    Arguments -
    vector<string> vi     = Vector to be printed
    string name_of_vector = Name of the vector to be displayed

    */
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
    /*
    Function returns a string after trimming it for whitespaces at the beginning and the end

    Argument -
    string str = String to be trimmed

    Return Value -
    string str = String after trimming

    */
    
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


string string_reverse( vector<string> str_symbols ) {
    /*
    Reverses an input string

    Argument -
    Vector of strings that contains the expression

    Return Value - 
    String that contains the symbols in reverse

    */
    
    string new_str = "";
    int length = str_symbols.size();

    for ( int i = length - 1; i >= 0; i-- ) {
        string symbol = str_symbols[i];
        new_str += " " + symbol;
    }

    new_str = string_trim( new_str );

    return new_str;
}


string string_swap_parentheses( string str ) {
    /*
    Replaces all instances of "(" with ")" and vice versa in a string
    Super useful for prefix conversion

    Argument - 
    String for which parentheses are to be swapped

    Return Value -
    String after swapping the parentheses

    */
    
    string new_str = "";
    int length = str.length();

    for ( int i = 0; i < length; i++ ) {
        string character = str.substr( i,1 );

        if ( character == "(" ) 
            character = ")";
        else if ( character == ")" ) 
            character = "(";
        
        new_str += character;
    }

    return new_str;
}


class Conversion {
    /*
    Contains the variables and methods required to convert a string expression given in infix format
    to either prefix or postfix format

    Vars -
    vector< pair< pair< string, string >, int > > vi_operator = Vector which contains the operators along with their details
    int number_of_operators = Contains the size of the operator vector

    vi_operator is a string vector of a pair of pairs.
    For the ith element,
    vi_operator[i].first.first gives us a string containing the operator under consideration
    vi_operator[i].first.second gives us a string that specifies its associativity
    vi_operator[i].second gives us an integer corresponding to the precedence of the operator
    

    How precedence is calculated - ( ICO = Incoming Operator, ISO = In-stack Operator )
    In this implementation, lower the integer, more the priority of the operator
    For example, if ICO > ISO then, the integer of the ICO operator is lesser than that of the ISO operator i.e,
    ico_precedence < iso_precedence 
    
    If ICO > ISO, we want to return 1, which will push the ICO into the operation stack
    If ICO < ISO, we want to return 0, which will perform a continuous pop operation until either the operation stack is empty, or ICO > ISO
    If ICO = ISO, we check for the associativity. 

    If the operators follow left associativity, we perform the continuous pop operation
    If the operators follow right associativity, we push ICO into the operation stack
    For example, if the operators follow left associativity, for the expression:
    A (ISO) B (ICO) C, we want to execute A (ISO) B before.


    Methods -
    Conversion()
    Initializes the operators (along with their details), and calculates the number of operators

    vector<int> getPriorityAndAssociativity( string operator_ )
    Returns the priority index and associativity of an operator

    bool precedence( string ICO, string ISO )
    Compares the precedence of both ICO and ISO. Returns true if ICO > ISO

    vector<string> getSymbols( string expression )
    Goes through an expression and breaks it into fundamental symbols (variables and operators)

    bool notOperand( string symbol )
    Returns true if a symbol is an operand (variable or constant)

    string convert_infix_to_postfix( string expression )
    Returns the postfix format of an expression in infix format

    string convert_infix_to_prefix( string expression );
    Returns the prefix format of an expression in infix format

    */
    
    private:
        vector< pair< pair< string, string >, int > > vi_operator; 
        int number_of_operators;
        
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
            /*
            Returns the priority index (lesser the index, more the priority), and the associativity of an operator 
            Returns -1 if the operator does not exist in the operator vector.

            */
            
            for ( int i = 0; i < number_of_operators; i++ ) {

                if ( vi_operator[i].first.first == operator_ ) {

                    vector<int> vi;
                    vi.push_back( vi_operator[i].second );

                    if ( vi_operator[i].first.second == "left" ) 
                        vi.push_back( 1 );
                    
                    else 
                        vi.push_back( 0 ); // Right Associativity
                    
                    return vi;
                }
            }

            vector<int> vi;
            vi.push_back( -1 );
            vi.push_back( -1 );
            return vi;
        }


        bool precedence( string ICO, string ISO ) {
            /*
            Returns true if ICO > ISO
            If they have the same priority, it checks for associativity
            Basically, if we want to push to the stack, true is returned
            For the continuous pop operation, false is returned.

            */

            vector<int> ico_precedence = getPriorityAndAssociativity( ICO );
            vector<int> iso_precedence = getPriorityAndAssociativity( ISO );

            if ( ico_precedence[0] < iso_precedence[0] ) {
                // ICO > ISO. Lesser the index of precedence, greater the priority
                return true;
            }
            
            else if ( ico_precedence[0] == iso_precedence[0] ) {

                // Left associativity
                if ( ico_precedence[1] == 1  ) 
                    return false; 
                
                // Right associativity
                return true; 
            }
            else {
                // ICO < ISO
                return false;
            }
        }


        vector<string> getSymbols( string expression ) {
            /*
            Breaks the input expression into its fundamental symbols (variables, constants and operators)
            A symbol is just the smallest element in the expression
            Introducing symbols to account for variables and integers that have more than one characters
            
            */
            
            int start_index = 0;
            int expression_length = expression.length();
            vector<string> symbols;
            
            for ( int i = 0; i < expression_length; i++ ) {

                string character = expression.substr( i,1 );

                // Store the symbol if we encounter a space
                if ( character == " " ) {
                    
                    string one_symbol = expression.substr( start_index, i-start_index );                    
                    symbols.push_back( one_symbol );
                    start_index = i+1;
                }

                // Store the last symbol if we encounter the end of the expression
                else if ( i == expression_length - 1 ) {

                    string one_symbol = expression.substr( start_index, i-start_index+1 );
                    symbols.push_back( one_symbol );
                }
            }

            return symbols;
        }

        bool notOperand( string symbol ) {
            /*
            Returns true if the symbol is an operand
            Returns false if the symbol is either an operator, or a bracket
            */
            
            for ( int i = 0; i < number_of_operators; i++ ) {
                if ( vi_operator[i].first.first == symbol ) 
                    return false;
            }

            if ( symbol == "(" || symbol == ")" ) 
                return false;
            
            return true;
        }

        string convert_infix( string expression, string conversion_type );
};


string Conversion::convert_infix( string expression, string conversion_type ) {
    /*
    This function takes an expression in infix format and returns the postfix form of that expression
    All parentheses handling is done in this function
    
    Infix to Postfix Conversion:
    ============================
    We will iterate over the symbols and follow the following rules
    If an operand is found, it is added to the output

    If an operator is found, it is pushed to the stack if the In-Stack element has lower priority

    Else we will conduct a pop operation that pops the operators until the In-stack element has lower priority, 
    or the stack becomes empty

    If at the end of symbol parsing, the stack is not empty, we will pop out the elements and add them to the output

    Infix to Prefix Conversion:
    ===========================
    Infix to Prefix conversion is similar to Postfix conversion
    We just need to start from the end of the expression and iterate backwards

    Each time a symbol is to be added to the output, we will append it at the end, 
    and then to produce the final string, we will reverse it
    Operator and operand handling is to be done the way it is done with postfix conversion
    
    16-06
    */


    // Instead of changing the entire parentheses handling section, we can just swap "(" and ")" in a string, to make evaluations easier
    if ( conversion_type == "prefix" ) {
        expression = string_swap_parentheses( expression );
    }
        
    // Vector that contains all the symbols to be parsed
    vector<string> symbols = getSymbols( expression );
    
    // Number of symbols to be parsed
    int number_of_symbols = symbols.size();

    // Number of characters in the expression
    int expression_length = expression.length();
    
    // Final output
    string new_expression = "";

    // Operation Stack which keeps track of the parentheses and the operators
    vector<string> stack;
    
    // top pointer that needs to be updated after each push and pop operation
    int top = -1;

    // Loop variable that keeps track of which symbol is under consideration
    int i = 0;

    bool to_postfix = true;

    if ( conversion_type == "prefix" ) {
        
        to_postfix = false;
        i = number_of_symbols - 1;
    }

    while ( ( i < number_of_symbols && to_postfix ) || ( i >= 0 && to_postfix == false ) ) {
    
        string symbol = symbols[i];
    
        // If the symbol is a constant or a variable (an operand), send it to the output
        if ( notOperand( symbol ) ) 
            new_expression += " " + symbol;
        
        // The Symbol is an operator or a parenthesis
        else {
            
            // Keeps track of whether an element has been pushed into the stack or not. Turns false if no more operations are to take place
            // This var is essential to prevent duplicates
            bool execute_operation = true;

            // Turns true if the continuous pop operation takes place
            bool if_pop_operation = false;

            // Keeps track of the In-stack Operator
            string top_symbol = "";

            // If the operation stack is empty, push the operator into the stack
            if ( top == -1 ) {
            
                stack = push( stack, symbol, top );
                top++;        
                execute_operation = false;
            }

            // If the operation stack is not empty, get the In-stack operator
            else {
                top_symbol = stack[ top ];
            }
            
            // If an open parenthesis is seen, push it into the stack
            if ( symbol == "(" && execute_operation ) {
                 
                stack = push( stack, symbol, top );
                top++;
                execute_operation = false;
            }
            
            // If a closed parenthesis is seen, perform pop operation until an open parenthesis is encountered
            if ( symbol == ")" ) {
                while ( top_symbol != "(" ) {

                    stack.pop_back();
                    top--;
                    new_expression += " " + top_symbol;
                    top_symbol = stack[ top ];
                }

                // We need to pop once more to remove "("
                stack.pop_back();
                top--;
                execute_operation = false;
            }
            
            // If the In-stack operator is an open parenthesis, push the Incoming operator if it is not a closing parenthesis
            if ( top_symbol == "(" && symbol != ")" && execute_operation ) {
                
                stack = push( stack, symbol, top );
                top++;
                execute_operation = false;
            }

            // If ICO > ISO, this var is true
            bool ico_greater_than_iso = precedence( symbol, top_symbol );
            
            // If ICO > ISO, push the ICO into the operation stack
            if ( ico_greater_than_iso && execute_operation  ) {
                
                stack = push( stack, symbol, top );
                top++;
                execute_operation = false;
            }

            // If ICO < ISO, perform continuous pop operation until ICO > ISO or the stack is empty
            while ( execute_operation && ico_greater_than_iso == false )  {

                // Setting this to be true, so that the ICO can get pushed into the stack at the end of this continuous pop operation
                if_pop_operation = true;
                
                // To be, or not to be?
                string to_be_outputted = stack[ top ];
                
                stack.pop_back();
                top--;
                new_expression += " " + to_be_outputted;

                // If the operation stack is empty, discontinue the pop operation
                if ( top == -1 ) {
                    break;
                }
                
                // Update the In-stack operator after one pop
                top_symbol = stack[ top ];

                // If the In-stack operator is an opening parenthesis, discontinue pop operation
                if ( top_symbol == "(" ) {
                    break;
                }

                // Recalculate precedence between ICO and the new ISO
                ico_greater_than_iso = precedence( symbol, top_symbol );
            }
            
            // If the continuous pop operation was executed for the operands, push the Incoming operator into the stack
            if ( if_pop_operation ) {
                stack = push( stack, symbol, top );
                top++;
            }            
        }

        // Update loop variable to move on to the next symbol
        if ( to_postfix )
            i++;
        else 
            i--;
    }

    // After parsing all the symbols, push the operation stack's elements to the output
    while ( top > -1 ) {
        
        string operator_ = stack[ top ];
        stack.pop_back();
        new_expression += " " + operator_;
        top--;
    }
    

    // Remove initial and trailing spaces of the final string
    new_expression = string_trim( new_expression );

    // In the case of Infix to Prefix conversion, the actual output will be derived once we reverse the found solution
    if ( to_postfix == false ) {
        // We are converting the string to its symbols to account for variables and constants that have more than one character
        vector<string> symbols_in_prefix = getSymbols( new_expression );
        new_expression = string_reverse( symbols_in_prefix );
    }

    return new_expression;    
}


class Evaluation : public Conversion {
// Use Hash Maps for input values of variables
// Derive some useful functions from Conversion using inheritance
    private:
        int tmp;
        vector<string> variables;
    public:

        bool isConstant( string symbol ) {
            // Returns true if the symbol is a constant.
            
            int length = symbol.length();

            for ( int i = 0; i < length; i++ ) {
                string character = symbol.substr( i,1 );

                // The first character is allowed to be a negative sign
                if ( i == 0 && character == "-" ) {
                    continue;
                } 

                bool flag = false;
                for ( int j = 0; j < 10; j++ ) {
                    if ( character == to_string(i) ) {
                        flag = true;
                        break;
                    }
                }

                // The character was not an integer
                if ( flag == false ) {
                    return false;
                }
            }

            // The input symbol is a constant
            return true;
        }
        

        vector<string> getVariables( string expression ) {
            // Takes an expression and extracts the variables

            //vector< pair<string, double> > variables;
            vector<string> variables;
            vector<string> symbols = getSymbols( expression );
            int length = symbols.size();
            

            for ( int i = 0; i < length; i++ ) {
                string symbol = symbols[i];

                // If a symbol is not and operand and not a constant, then it is a variable
                if ( notOperand(symbol) && isConstant(symbol) == false ) {
                    variables.push_back( symbol );
                }
            }
            
            return variables;
        }

        vector<string> getSymbolsOfValidExpression( string expression ) {
            // CALL THIS FUNC DURING EVALUATION!
            // Takes the expression (in any form), and returns a string with only constants and operators (which can be solved)
            // takes double input from user, which can be assigned to the vector of variables.
            
            vector<string> variables = getVariables( expression );

            vector< pair<string,double> > vars;

            if ( vars.empty() ) {
                vector<string> symbols = getSymbols( expression );
                return symbols;
            }

            int number_of_variables = variables.size();

            printf( "Enter values for the following variables:\n" );
            for ( int i = 0; i < number_of_variables; i++ ) {
                vars[i].first = variables[i];

                double value = 0.0;
                
                cout << variables[i] << ": ";
                scanf( "%lf",&value );

                vars[i].second = value;
            }

            // find all instances of the variables and replace them in the symbols.
            vector<string> symbols = getSymbols( expression );
            int number_of_symbols = symbols.size();

            for ( int i = 0; i < number_of_variables; i++ ) {
                for ( int j = 0; j < number_of_symbols; j++ ) {

                    // If an instance of the variable is found, it is replaced by the constant value
                    if ( vars[i].first == symbols[j] ) {
                        symbols[j] = to_string( vars[i].second );
                    }
                }
            }

            return symbols;
        }

        double evaluateMiniExpression( string pre_operand, string post_operand, string operator_ );

        double evaluateExpression( vector<string> symbols, string expression_type );



        
};

double Evaluation::evaluateMiniExpression( string pre_operand, string post_operand, string operator_ ) {
    // evaluates: operand (operator) operand, and returns the value

    // convert string to integer using std::stod()
    double first  = stod( pre_operand );
    double second = stod( post_operand );

    // Supports the following operators: ^ * / % + -
    if ( operator_ == "^" ) {
        return pow(first,second);
    }
    else if ( operator_ == "*" ) {
        return first * second;
    }
    else if ( operator_ == "/" ) {
        return first / second;
    }
    else if ( operator_ == "%" ) {
        int tmp1 = first;
        int tmp2 = second;
        return tmp1 % tmp2;
    }
    else if ( operator_ == "+" ) {
        return first + second;
    }
    else if ( operator_ == "-" ) {
        return first - second;
    }

    return first;
}

double Evaluation::evaluateExpression( vector<string> symbols, string expression_type ) {
    /*
    Takes the symbols in the expression and the type of that expression (either postfix or prefix)
    The expression contains only the constants and the operators
    */
    
    int i = 0;
    int number_of_symbols = symbols.size();
    vector<string> stack;
    int top = -1;

    while( i < number_of_symbols ) {
        string symbol = symbols[i];

        // If the symbol is an operand (constant), push it into the stack
        
        if ( isConstant( symbol ) ) {
            stack = push( stack, symbol, top );
            top++;
        }

        // An operator has been encountered
        else {
            string top_element = stack[ top ];
            top--;
            stack.pop_back();

            string top_minus_one_element = stack[ top ];
            top--;
            stack.pop_back();

            double answer = evaluateMiniExpression( top_minus_one_element, top_element, symbols[i] );

            string answer_string = to_string( answer );
            stack = push( stack, answer_string, top );
            top++;

        }


        i++;

    }

    if ( top!= 0 ) {
        printf("\n\nSomething went wrong!\n\n" );
    }


    string answer = stack[ top ];
    double expression_result = stod( answer );
    
    return expression_result;
}


class UserInterface {
    private:
        int tmp;
    public:
        void welcome() {
            printf( "\nWelcome to the Expression Calculator!\n\n" );

        }

        void help_menu() {
            printf( "Available Operations:\n\n" );
            printf( "1 - Convert Infix Expression to Prefix Form\n" );
            printf( "2 - Convert Infix Expression to Postfix Form\n" );
            printf( "3 - Convert Infix Expression to both Prefix and Postfix Forms\n" );
            printf( "4 - Evaluate an Infix Expression\n" );
            printf( "5 - Evaluate a Prefix Expression\n" );
            printf( "6 - Evaluate a Postfix Expression\n\n" );

            printf( "7 - Print the Instructions\n" );
            printf( "0 - Terminate the program\n\n" );

        }

        void instructions() {
            printf( "Instructions on how to use the program:\n\n" );
            printf( "Please enter the expressions in the following format -\n" );
            printf( "There should be a space between each element of the expression.\n" );
            printf( "For example, there should be a space between the operators and the operands.\n" );
            printf( "Variables must use alphabetic characters only. Constants like 101, 24 can be used.\n" );
            printf( "Example of valid Infix Expression:\n( ( a * b - ( c + d ) ) ) ^ e / ( f * g + h )\n\n" );
            
        }

        void exit_interface() {
            printf( "\n----------------------------------------------\n" );
            printf( "Thank you for using the Expression Calculator!\n\n" );
        }

        void main_loop();

};


void UserInterface::main_loop() {

    int control = 1;
    Conversion convert_Class;
    
    welcome();
    instructions();
    help_menu();

    /*
    printf( "Enter choice of integer: " );
    scanf( "%d", &control );
    printf( "\n" );

    if ( control == 0 ) {
        exit_interface();
    }
    */

    while ( control != 0 ) {

        printf( "Enter choice of integer: " );
        scanf( "%d", &control );
        printf( "\n" );
        if ( control == 1 ) {
            string infix_expression;
            printf( "Enter the expression in Infix format:\n" );
            cin.ignore();
            getline( cin, infix_expression );
            printf( "\n" );

            string prefix_expression = convert_Class.convert_infix( infix_expression, "prefix" );
            printf( "Prefix Form:\n" );
            cout << prefix_expression << endl;

            printf( "\n" );
        }

        else if ( control == 2 ) {
            string infix_expression;
            printf( "Enter the expression in Infix format:\n" );

            // This line is necessary to get rid of all the extra characters before getline()
            cin.ignore();
            getline( cin, infix_expression );
            printf( "\n" );

            string postfix_expression = convert_Class.convert_infix( infix_expression, "postfix" );
            printf( "Postfix Form:\n" );
            cout << postfix_expression << endl;

            printf( "\n" );
        }

        else if ( control == 3 ) {
            string infix_expression;
            printf( "Enter the expression in Infix format:\n" );
            cin.ignore();
            getline( cin, infix_expression );
            printf( "\n" );

            string prefix_expression = convert_Class.convert_infix( infix_expression, "prefix" );
            string postfix_expression = convert_Class.convert_infix( infix_expression, "postfix" );
            
            printf( "Prefix Form:\n" );
            cout << prefix_expression << endl;
            printf( "Postfix Form:\n" );
            cout << postfix_expression << endl;

            printf( "\n" );
        }

        else if ( control == 0 ) {
            exit_interface();
        }

        else {
            printf( "Invalid Choice!\n" );
            
        }

        

    }
    
}

void test_single_expression() {
    string infix;
    printf( "Enter Expression:\n" );

    // Cannot use scanf(), since we want the input string to include spaces
    cin.ignore();
    getline( cin, infix ); 
    
    Conversion convert_Class;

    string postfix = convert_Class.convert_infix( infix, "postfix" );
    printf( "Postifix Expression:\n" );
    cout << postfix << "\n";

    string prefix  = convert_Class.convert_infix( infix, "prefix" );
    printf( "Prefix Expression:\n" );
    cout << prefix << "\n";
}


int main() {

    // To test a single Infix to Prefix and Postfix Conversion -
    //test_single_expression();
    
    UserInterface UI;
    UI.main_loop();

    return 0;
}

/*
Test Expressions:
passed = The given testcase gave the right output


1. Infix -
1 * ( 2 - 3 + 4 ) ^ 5 / ( 6 * 7 + 8 )
Postfix - (passed)
1 2 3 - 4 + 5 ^ * 6 7 * 8 + /
Prefix - (passed)
* 1 / ^ - 2 + 3 4 5 + * 6 7 8


2. Infix -
a = b + c * 10
Postfix - (passed)
a b c 10 * + =
Prefix - (passed)
= a + b * c 10


3. Infix -
w + f ^ g - h / ( a + b )
Postfix - (passed)
w f g ^ + h a b + / -
Prefix - (passed)
+ w - ^ f g / h + a b


4. Infix -
( ( a * b - ( c + d ) ) ) ^ e / ( f * g + h )
Postfix - (passed)
a b * c d + - e ^ f g * h + /
Prefix - (passed)
/ ^ - * a b + c d e + * f g h


5. Infix -
a - b ^ c + f ^ g / h * g ^ 1
Postfix - (passed) 
a b c ^ - f g ^ h / g 1 ^ * +
Prefix - (passed)
- a + ^ b c / ^ f g * h ^ g 1


6. Infix -
( ( a + b ) * ( b + c - d * f ) ) / ( 1 + 2 )
Postfix - (passed)
a b + b c + d f * - * 1 2 + /
Prefix - (passed)
/ * + a b + b - c * d f + 1 2


*/
