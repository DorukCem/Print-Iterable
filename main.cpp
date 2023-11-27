#include "print.h"
#include "string"
#include "array"

int main() {

   std::vector<int> veci{1, 2, 3};
   std::vector<std::string> vecs{"hello", "my", "name"};
   std::vector<std::vector<int>> vecofvecs = {{1,2,3}, {2,4}};
   std::vector<std::vector<std::vector<int>>> vecofvecofvecs = {{{1,2}, {1,4}}, {{2,5}, {4,2}}};
   
   print(veci);
   print(vecs); 
   print(vecofvecs); 
   print(vecofvecofvecs); 

   print(std::array<int, 3>{1 ,2, 3});
   
   return 0;
}