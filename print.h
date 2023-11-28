#include <iostream>
#include <tuple>
#include <utility>

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

// Print bools
void print_iterable(const bool b) {
   std::cout << std::boolalpha << b;
}

// Print a tuple
template<typename TupType, size_t... I>
void print(const TupType& tup, std::index_sequence<I...>)
{
   std::cout << "(";
   (..., (std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup))); // Fold expression: get<0>, get<1>, ...
   std::cout << ")" << std::endl;
}
// Wrapper for printing a tuple
template<typename... T>
void print (const std::tuple<T...>& tup)
{
   print(tup, std::make_index_sequence<sizeof...(T)>()); // make_index_sequence -> 0, 1, 2, ..., N-1 
}

// Print a pair
template<class T1, class T2>
void print_iterable(const std::pair<T1, T2>& pair)
{
   std::cout << "(" << pair.first << " : " << pair.second << ")";
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