#include "print.h"
#include <bits/stdc++.h>

int main() {

   std::vector<int> veci{1, 2, 3};
   std::vector<std::string> vecs{"hello", "my", "name"};
   std::vector<std::vector<int>> vecofvecs = {{1,2,3}, {2,4}}; // * -> Deeply nested
   std::vector<std::vector<std::vector<int>>> vecofvecofvecs = {{{1,2}, {1,4}}, {{2,5}, {4,2}}}; // * -> Really deeply nested 
   std::vector<std::array<int, 3>> vecofarrs = {{1,2,3}, {2,4}}; // * -> Iterables can be of different types

   std::map<int, std::string> hashmap = {{1, "Killer Mike"}, {2, "El-P"}};
   std::set<int> hashset = {1, 2, 3, 4};

   print(veci);
   print(vecs); 
   print(vecofvecs); 
   print(vecofvecofvecs); 
   print(vecofarrs); 
   print(std::array<int, 3>{1 ,2, 3});

   
   return 0;
}

// TODO: map, set, tuple, variadic arguements