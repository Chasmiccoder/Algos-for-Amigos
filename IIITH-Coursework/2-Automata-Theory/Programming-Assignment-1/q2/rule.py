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
    Implement Conway's Game of Life and try to simulate 4 'blinkers' of period 2
    """

    neighbor_count = 0
    for i in range(len(neighbors)):
        for j in range(len(neighbors[i])):
            if not (i == 1 and j == 1):
                if neighbors[i][j] == 1:
                    neighbor_count += 1 

    # Any live cell with fewer than two live neighbours dies, as if by underpopulation
    if cell_value == 1 and neighbor_count < 2:
        return 0

    # Any live cell with two or three live neighbours lives on to the next generation
    if cell_value == 1 and (neighbor_count == 2 or neighbor_count == 3):
        return 1

    # Any live cell with more than three live neighbours dies, as if by overpopulation
    if cell_value == 1 and neighbor_count > 3:
        return 0

    # Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction
    if cell_value == 0 and neighbor_count == 3:
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