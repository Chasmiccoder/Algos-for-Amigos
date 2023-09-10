"""
This file contains the rule corresponding to the required final state (after n iterations)
We import cellular_automata, which houses all information regarding the automata, and pass
the automata rule as an argument.
"""

import cellular_automata as ca

def automata_rule(cell_value: int, neighbors: list[list[int]]) -> int:
    """
    Returns the new value of the cell according to the rule specified in this function
    Rule:
    If the left, top or top left element is alive, then make the cell alive
    """
    
    if neighbors[0][1] == 1 or neighbors[1][0] == 1 or neighbors[0][0] == 1 or cell_value == 1:
        return 1
    return 0

if __name__ == "__main__":

    print("\n----------------------------")
    print("Cellular Automata Simulator!")
    print("----------------------------\n")
    grid, m, n, k = ca.read_from_file()

    automata = ca.CellularAutomata(grid, m, n, automata_rule)

    num_iterations = int(input("Enter the number of iterations: "))
    while num_iterations != -1:
        automata.run(iterations=num_iterations, display_iterations=False)
        num_iterations = int(input("Enter the number of iterations: "))

    automata.create_output_file()
