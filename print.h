#include <iostream>
#include <vector>

template<typename T>
void print_iterable( const T& t)
{
   std::cout << t;
}

template<typename T>
void print_iterable( const std::vector<T> &v ) 
{  
   std::cout << '[';
   for (auto it = v.begin(); it != v.end(); ++it) {
      print_iterable(*it); // <---- Recursive call to to one level deeper
      if (it != v.end()-1) { 
         std::cout << ", "; 
      }
   } 
   std::cout << ']';

}

template<typename T>
void print( const T& t)
{
   print_iterable(t);
   std::cout << std::endl;
}