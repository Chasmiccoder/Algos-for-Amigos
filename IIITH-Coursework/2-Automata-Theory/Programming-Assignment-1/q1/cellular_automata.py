"""
Python file which contains the CellularAutomata class, which holds all information
needed to process and evolve the automata
"""

import copy
import time

def read_from_file(path="q1/config.txt"):
    """
    Function that reads the initial state of the automata from a file
    m = number of columns
    n = number of rows

    Why grid is being accessed as grid[n - y][x - 1]
    Doing this to convert cartesian coordinates (from input) to matrix coordinates
    x can be at most n
    """

    with open(path, 'r', encoding='utf-8') as file:
        file_lines = file.readlines()
        input_stream = []
        for line in file_lines:
            args = line.split(' ')
            if args[-1][-1] == '\n':
                args[-1] = args[-1][:-1]
            input_stream.append(args)

    m, n, k = [int(i) for i in input_stream[0]]
    grid = [[0 for j in range(m)] for i in range(n)]

    for i in range(k):
        x, y = [int(i) for i in input_stream[i+1]]
        grid[n - y][x - 1] = 1

    return grid, m, n, k

class CellularAutomata():
    """
    Stores information regarding the Cellular Automata
    along with methods that operate on it.
    """

    def __init__(self, grid, m, n, automata_rule):
        self.grid = copy.deepcopy(grid)            # m by n list that stores the current state
        self.initial_state = copy.deepcopy(grid)   # store the start state of the cellular automata
        self.automata_rule = automata_rule         # function that applies the rule on a specific cell
        self.num_cols = m                          # number of columns in the grid
        self.num_rows = n                          # number of rows in the grid

    def reset_automata(self):
        """
        Reset the current grid to the initial state
        """
        self.grid = copy.deepcopy(self.initial_state)

    def print_automata(self):
        """
        Prints the current state of the automata
        """
        print()
        for row in self.grid:
            for cell in row:
                if cell == 1:
                    print(f"\033[7m{'X'}\033[27m", end=' ')
                else:
                    print("-", end=' ')
            print()
        print()

    def extract_neighbors(self, grid_copy, index1, index2):
        """
        Returns the neighborhood of grid element in row index1 and column index2
        We need to use grid_copy and not self.grid because self.grid changes mid iteration
        """
        neighbors = []
        for i in range(index1 - 1, index1 + 2):
            row = []
            for j in range(index2 - 1, index2 + 2):
                if i < 0 or i >= self.num_rows or j < 0 or j >= self.num_cols:
                    row.append(-1) # we should not operate on this, since it is out of bounds
                else:
                    row.append(grid_copy[i][j])
            neighbors.append(row)
        return neighbors

    def execute_rule(self):
        """
        Executes the rule for the entire grid,
        and returns the result of one iteration
        """

        grid_copy = copy.deepcopy(self.grid)

        for i in range(self.num_rows):
            for j in range(self.num_cols):
                neighbors = self.extract_neighbors(grid_copy, i, j)
                self.grid[i][j] = self.automata_rule(self.grid[i][j], neighbors)


    def run(self, iterations, store_states=False, display_iterations=True):
        """
        Runs the required iterations on the current grid
        If store_states is True, this function returns the states
        from the initial state to the final iteration. 
        This gets disabled if there's the number of iterations is beyond
        the threshold (to save memory)
        """

        simulation = []
        threshold = 50

        grid_copy = copy.deepcopy(self.grid)
        simulation.append(grid_copy)

        print("Initial State:")
        self.print_automata()

        for i in range(iterations):
            self.execute_rule()

            if store_states and iterations <= threshold:
                grid_copy = copy.deepcopy(self.grid)
                simulation.append(grid_copy)

            if display_iterations:
                print(f"State after iteration: {i+1}")
                self.print_automata()
                time.sleep(0.3)  # better aesthetically

        print(f"After iteration: {iterations}")
        self.print_automata()
        
        return simulation
    
    def create_output_file(self):
        file = open('q1/output.txt', 'w')
        string = ''
        for row in self.grid:
            for cell in row:
                if cell == 1:
                    string += 'X'
                else:
                    string += 'O'
            string += '\n'
        file.write(string)
