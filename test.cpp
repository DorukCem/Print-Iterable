#include "print.h"
#include <bits/stdc++.h>

int main() {


   std::vector<int> veci{1, 2, 3};
   std::vector<std::string> vecs{"hello", "my", "name"};
   std::vector<std::vector<int>> vecofvecs = {{1,2,3}, {2,4}}; // * -> Deeply nested
   std::vector<std::vector<std::vector<int>>> vecofvecofvecs = {{{1,2}, {1,4}}, {{2,5}, {4,2}}}; // * -> Really deeply nested 
   std::vector<std::array<int, 3>> vecofarrs = {{1,2,3}, {2,4}}; // * -> Iterables can be of different types
   std::set<int> hashset = {1, 2, 3, 4};
   std::map<int, std::string> hashmap = {{1, "Killer Mike"}, {2, "El-P"}};
   int i = 42;
   int* pointer = &i;
   
   // Nested std::map with integers
   std::map<int, std::map<int, std::map<int, std::string>>> nestedMap1 = {
      {1, {{2, {{3, "A"}, {4, "B"}}}, {5, {{6, "C"}, {7, "D"}}}}},
      {8, {{9, {{10, "E"}, {11, "F"}}}, {12, {{13, "G"}, {14, "H"}}}}}
   };

   
   print(nestedMap1);

   print("C-Style"); // * -> C style string
   print(std::string{"std::string"});
   print(veci);
   print(vecs); 
   print(vecofvecs); 
   print(vecofvecofvecs); 
   print(vecofarrs); 
   print(std::array<int, 3>{1 ,2, 3});
   print(std::array<std::vector<int>, 1> {std::vector{1,2,3}} ) ;
   print(hashset);
   print(hashmap);
   print(std::make_pair(4, 2)); // * pair
   print(std::tuple<double, char, std::string>{0.6, 'F', "Bart Simpson"}); //* Tuple
   print(pointer);
   print(true);
   print(false);
   print(std::make_pair(std::vector<int>{1, 2, 3}, std::map<int, std::string>{ {1, "Run"}, {2, "The"}} ));
   
   print(std::tuple<std::vector<int>>{{1,2,3}});
   print(1, "asdasd", 0.6f);

   return 0;
}

// TODO: optional arguements