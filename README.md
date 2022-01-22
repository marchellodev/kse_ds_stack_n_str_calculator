# KSE Algorithms Homework #1

[Task](https://github.com/kse-ua/algorithms/blob/main/assignments_2021/assignment_1.md)

- Define and implement a `Stack` data structure
- Implement a calculator, that takes in a string (i.e. `2 * (3 + 7 - 1)`) and returns the result (i.e. `18`)


## Running
Note: The program uses Linux's readline ([for better editing experience](https://stackoverflow.com/a/7463298)), so it'll only work on Linux machines (maybe also MacOS, I am not sure). Please refore to commit [03a63c](https://github.com/marchellodev/kse_ds_stack_n_str_calculator/commit/03a63cd70a8fde953db16b783bda6e2cb50ca070) when trying to run this thing on an OS other than Linux.

```shell
# Cleanup
rm Makefile kse_alg_1 cmake_install.cmake CMakeFiles CMakeCache.txt cmake-build-debug bin CTestTestfile.cmake _deps testing lib testing\[* -rf

# Building & Running
cmake .
make
./kse_alg_1
```


## TO-DO
- [ ] Use custom data structure instead of `vector<>` for lists
- [ ] Define `Queue` and use it instead of `vector<Token>` for the Shunting-yard algorithm
- [ ] Implement testintg


## Tested on the following inputs:
```shell
2 + 3                             5
2 * (3 + 7 - 1)                   18
2 + (3 * (8 - 4))                 14
3 + 4 * 2 / (1 - 5)^2^3           3

# additional task
3 -- 2                            5
```
