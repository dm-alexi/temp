#!venv/bin/python3

from sys import argv
from solver import Solver

if __name__ == '__main__':
    if len(argv) != 2:
        print('usage: ./main.py <equation>\nOnly one argument is accepted.')
    else:
        print(Solver(argv[1]))
