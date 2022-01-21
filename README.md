# KSE Algorithms Homework #1

[Task](https://github.com/kse-ua/algorithms/blob/main/assignments_2021/assignment_1.md)

- Define and implement a `Stack` data structure
- Implement a calculator, that takes in a string (i.e. `2 * (3 + 7 - 1)`) and returns the result (i.e. `18`)


## Running
```shell
# Cleanup
rm Makefile kse_alg_1 cmake_install.cmake CMakeFiles CMakeCache.txt -rf

# Building & Running
cmake .
make
./kse_alg_1
```


## TO-DO
- [ ] Use custom data structure instead of `vector<>` for lists
- [ ] Define `Queue` and use it instead of `vector<Token>` for the Shunting-yard algorithm


## Tested on the following inputs:
```shell
2 + 3                             5
2 * (3 + 7 - 1)                   18
2 + (3 * (8 - 4))                 14
3 + 4 * 2 / (1 - 5)^2^3           3
```