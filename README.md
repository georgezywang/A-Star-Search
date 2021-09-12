# A-Star-Search
## Dependencies
Before compiling, please make sure you have support for `C++17` and the corresponding `C++STL`. In addition, this projects requires support of `Boost`, a widely used `C++` library. It specifically uses `Boost Program Options`. Refer to the [Boost Documentation](https://www.boost.org/) to install `Boost`. Please make sure that all `C++STL` and the `Boost` library have been included in your `C++` include path, otherwise the program won't compile.

## Compiling
The compilation has been mostly taken care of. To compile the code from scratch, run `make main` or simply run `make` in the project root directory. The output `driver.o` executable can be found in the root directory of the project folder.

If for some reason, you are not able to get `Boost` installed, run `make WO_Boost` instead, but this version of code will have less sanity checks of the input argument.

To remove the existing executable, run `make clean`.

## Fifteens Puzzle with Knight’s Moves
Assuming the input test case is a `.txt` file, with relative path `test.txt`. Then by using the `--filePath` optional argument, one can run the test case by the command `./driver.o --filePath test.txt --pSet 1`. The `--pSet` argument indicates which problem the program is directed to solve. `1` indicates solving *Fifteens Puzzle with Knight’s Moves*. The outputs are saved in `test_output.txt` as required. You can find example outputs [here](Tests/input_FPK_1_output.txt).

## Superqueens Puzzle
Assuming the input test case is a `.txt` file, with relative path `test.txt`. Then by using the `--filePath` optional argument, one can run the test case by the command `./driver.o --filePath test.txt --pSet 2`. The `--pSet` argument indicates which problem the program is directed to solve. `2` indicates solving *Superqueens Puzzle*. The outputs are saved in `test_output.txt` as required. You can find example outputs [here](Tests/SQP_1_(size_18)_output.txt).
