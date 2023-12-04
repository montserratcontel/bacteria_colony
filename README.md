# Bacteria colony
This program is my contribution to the HackerRank contest named "Test Autoevaluación Conocimientos de Programación" created by jjaguillon. The aim is to simulate how three different groups of bacteria interact. The three different colonies are identified by a number (0,1 and 2), and this is how they interact:
* Type 0 bacteria: lose to Type 1 bacteria.
* Type 1 bacteria: lose to Type 2 bacteria.
* Type 2 bacteria: lose to Type 0 bacteria.

These bacteria are distributed in a toroidal scenario, that is represented using an NxN matrix.  Every cell has 8 neighboring cells; if some cell has 3 or more neighbors that beat them, the cell will become the winner type of bacteria.

For the input: an integer number _n_ must be given, which is the matrix dimension, then the bacteria distribution matrix (_n_ times _n_ numbers that range from 0 to 2) and finally another integer number, which is the number of iterations that the user wants. For instance, a valid input is 

5

2 2 2 2 2

2 1 1 1 2

2 1 0 1 2

2 1 1 1 2

2 2 2 2 2

2

Where 5 is the matrix dimension, then the bacteria distribution is given and finally the number of iterations for the program to do, which is 2. The output must be

2 2 2 2 2

2 2 2 2 2

2 2 2 2 2

2 2 2 2 2

2 2 2 2 2

