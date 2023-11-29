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

// Forward declarations
template<typename T>
void print_iterable(const T& t);

void print_iterable(const std::string& str);

void print_iterable(const bool b);

template<typename TupType, size_t... I>
void print_iterable(const TupType& tup, std::index_sequence<I...>);

template<typename... T>
void print_iterable(const std::tuple<T...>& tup);

template<class T1, class T2>
void print_iterable(const std::pair<T1, T2>& pair);

template<Iterable T>
void print_iterable(const T& t);

template<typename T>
void print(const T& t);

// ----------------- End of forward declartions

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

// Helper to put commas between print statments inside fold expression
template<typename T>
void print_with_delim(const T& t, size_t I, size_t index_length)
{
   print_iterable(t);
   if (I != index_length-1) {std::cout << ", ";}
}

// Print a tuple
template<typename TupType, size_t... I>
void print_iterable(const TupType& tup, std::index_sequence<I...> index_s)
{
   std::cout << "(";
   (..., print_with_delim( std::get<I>(tup) , I, index_s.size()) ); // Fold expression: get<0>, get<1>, ...
   std::cout << ")";
}
// Wrapper for printing a tuple
template<typename... T>
void print_iterable(const std::tuple<T...>& tup)
{
   print_iterable(tup, std::make_index_sequence<sizeof...(T)>()); // make_index_sequence -> 0, 1, 2, ..., N-1 
}


// Print a pair
template<class T1, class T2>
void print_iterable(const std::pair<T1, T2>& pair)
{
   std::cout << "(";
   print_iterable(pair.first );
   std::cout << " : ";
   print_iterable(pair.second); 
   std::cout<< ")";
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