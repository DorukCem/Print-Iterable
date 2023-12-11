Header only library for printing C++ containers such as vector and map

# How to download library
Just download print.h and include it in your project

# How to use
The library has only one function ```print``` which is under the namespace ```p```
```cpp
using namespace p

std::vector<int> veci{1, 2, 3};
print(veci);
```
Also works for deeply nested containers
```cpp
std::vector<std::vector<std::vector<int>>> vecofvecofvecs = {{{1,2}, {1,4}}, {{2,5}, {4,2}}}
print(vecofvecofvecs);
```
Two optional parameters are available for specifying the delimiter and end character 
```cpp
print(std::vector<int>{1,2,3,4}, "-"); // 1-2-3-4
print(std::vector<int>{1,2,3,4}, "**", "|x"); // 1**2**3**4|x
```