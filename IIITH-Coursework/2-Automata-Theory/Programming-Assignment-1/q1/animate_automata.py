"""
You can run this script to generate a gif out of the automata
"""

from rule import automata_rule
import cellular_automata as ca

import numpy as np
import cv2
from PIL import Image
import glob
import os


def generate_images(simulation):

    SCALE_FACTOR = 40

    for imgNumber in range(len(simulation)):
        state = simulation[imgNumber]
        img = np.zeros([len(state), len(state[0]), 3])

        for i in range(len(state)):
            for j in range(len(state[0])):
                img[i][j][0] = (1-state[i][j]) * 255
                img[i][j][1] = (1-state[i][j]) * 255
                img[i][j][2] = (1-state[i][j]) * 255

        res = cv2.resize(img, dsize=(len(state[0])*SCALE_FACTOR, len(state)*SCALE_FACTOR), interpolation=cv2.INTER_NEAREST)
        cv2.imwrite(f'image_{imgNumber}.png', res)


def create_gif():
    frames = (Image.open(f) for f in glob.glob('image_*.png'))
    frame1 = next(frames)  # extracts first image from iterator
    frame1.save(fp='automata_animation.gif', format='GIF', append_images=frames, save_all=True, duration=500, loop=0)


def clear_images(num_frames):
    for i in range(num_frames):
        os.remove('image_'+str(i)+'.png')


if __name__ == "__main__":
    print("\n---------------------------")
    print("Cellular Automata Animator!")
    print("---------------------------\n")
    grid, m, n, k = ca.read_from_file()

    automata = ca.CellularAutomata(grid, m, n, automata_rule)
    num_iterations = int(input("Enter the number of iterations: "))

    print("Simulating the automata...")
    simulation = automata.run(iterations=num_iterations, store_states=True, display_iterations=False)
    num_frames = len(simulation)

    print("Generating frames...")
    generate_images(simulation)

    print("Creating gif...")
    create_gif()

    print("Removing Intermediate saved frames...")
    clear_images(num_frames)

    print("\nDone!\n")
