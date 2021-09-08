# A-Star-Search
## Dependencies
Before compiling, please make sure you have support for `C++17` and the corresponding `C++STL`. In addition, this projects requires support of `Boost`, a widely used `C++` library. It specifically uses `Boost Program Options`. Refer to the [Boost Documentation](https://www.boost.org/) to install `Boost`. Please make sure that all `C++STL` and the `Boost` library have been included in your `C++` include path, otherwise the program won't compile.

## Compiling
The compilation has been mostly taken care of. To compile the code from scratch, run `make main` or simply run `make` in the project root directory. The output `driver.o` executable can be found in the root directory of the project folder.

To remove the existing executable, run `make clean`.

## Fifteens Puzzle with Knight’s Moves
Assuming the input test case is a `.txt` file, with relative path `test.txt`. Then by using the `--filePath` optional argument, one can run the test case by the command `./driver.o --filePath test.txt`. The outputs are displayed in the terminal.

## Superqueens Puzzle
To run a test case with `n` queens, one can utilize the `--numQueen` optional argument, by using the following command `./driver.o --numQueen n`.

## Example Outputs
### Fifteens Puzzle
Command: `./driver.o --filePath Tests/input_FPK_1.txt`

Output:
```
length = 21

9 11 12 13 
0 8 14 10 
15 1 5 4 
6 3 2 7 

9 11 12 13 
3 8 14 10 
15 1 5 4 
6 0 2 7 

9 11 12 13 
3 8 0 10 
15 1 5 4 
6 14 2 7 

0 11 12 13 
3 8 9 10 
15 1 5 4 
6 14 2 7 

1 11 12 13 
3 8 9 10 
15 0 5 4 
6 14 2 7 

1 11 12 13 
3 8 9 0 
15 10 5 4 
6 14 2 7 

1 11 12 13 
3 8 9 2 
15 10 5 4 
6 14 0 7 

1 11 12 13 
3 0 9 2 
15 10 5 4 
6 14 8 7 

1 11 12 13 
3 4 9 2 
15 10 5 0 
6 14 8 7 

1 11 0 13 
3 4 9 2 
15 10 5 12 
6 14 8 7 

1 11 3 13 
0 4 9 2 
15 10 5 12 
6 14 8 7 

1 11 3 13 
5 4 9 2 
15 10 0 12 
6 14 8 7 

1 11 3 0 
5 4 9 2 
15 10 13 12 
6 14 8 7 

1 11 3 4 
5 0 9 2 
15 10 13 12 
6 14 8 7 

1 11 3 4 
5 6 9 2 
15 10 13 12 
0 14 8 7 

1 11 3 4 
5 6 9 2 
15 10 0 12 
13 14 8 7 

1 0 3 4 
5 6 9 2 
15 10 11 12 
13 14 8 7 

1 2 3 4 
5 6 9 0 
15 10 11 12 
13 14 8 7 

1 2 3 4 
5 6 9 8 
15 10 11 12 
13 14 0 7 

1 2 3 4 
5 6 9 8 
0 10 11 12 
13 14 15 7 

1 2 3 4 
5 6 0 8 
9 10 11 12 
13 14 15 7 

1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 0 

```

### Superqueen
Command: `./driver.o --numQueen 10`

Output:
```
nAttacks = 0

0 0 0 0 0 0 1 0 0 0 
0 0 1 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 
0 0 0 0 0 1 0 0 0 0 
0 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 0 
0 0 0 0 1 0 0 0 0 0 
1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 0 0 
0 0 0 1 0 0 0 0 0 0 
```