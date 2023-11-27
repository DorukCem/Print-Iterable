#include <iostream>

// Requires T to have ::iterator and ::const_iterator, which should 
// guarantee that the type is iterable as far as the STL is concerned
template<typename T>
concept Iterable = requires(T a) {
   typename T::iterator;
   typename T::const_iterator;
};

// Print a non iterable type
template<typename T>
void print_iterable( const T& t)
{
   std::cout << t;
}

// Specialization for std::string (should be treated like non-iterable)
void print_iterable(const std::string& str)
{
   std::cout << str;
}

// Print a iterable (can be deeply nested)
template<Iterable T>
void print_iterable(const T& t)
{  
   int indx = 0;
   std::cout << '[';
   for (auto it = t.begin(); it != t.end(); ++it) {
      print_iterable(*it); // <---- Recursive call to to one level deeper

      if (indx++ != t.size() - 1) { 
         std::cout << ", "; 
      }
   } 
   std::cout << ']';
}

// Wrapper
template<typename T>
void print( const T& t)
{
   print_iterable(t);
   std::cout << std::endl;
}