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
void print_iterable(const T& t, const std::string& sep);

void print_iterable(const std::string& str, const std::string& sep);

void print_iterable(const bool b, const std::string& sep);

template<typename TupType, size_t... I>
void print_iterable(const TupType& tup, std::index_sequence<I...>, const std::string& sep);

template<typename... T>
void print_iterable(const std::tuple<T...>& tup, const std::string& sep);

template<class T1, class T2>
void print_iterable(const std::pair<T1, T2>& pair, const std::string& sep);

template<Iterable T>
void print_iterable(const T& t, const std::string& sep);

template<typename T>
void print(const T& t, const std::string& sep = ", ", const std::string& end = "\n");

// ----------------- End of forward declartions

// Print a non-iterable type
template<typename T>
void print_iterable(const T& t, const std::string& sep)
{
   std::cout << t;
}

// Specialization for std::string (should be treated like non-iterable)
void print_iterable(const std::string& str, const std::string& sep)
{
   std::cout << str;
}

// Print bools
void print_iterable(const bool b, const std::string& sep) {
   std::cout << std::boolalpha << b;
}

// Helper to put sep string between print statements inside fold expression
template<typename T>
void print_with_delim(const T& t, size_t I, size_t index_length, const std::string& sep)
{
   print_iterable(t, sep);
   if (I != index_length - 1) {
      std::cout << sep;
   }
}

// Print a tuple
template<typename TupType, size_t... I>
void print_iterable(const TupType& tup, std::index_sequence<I...> index_s, const std::string& sep)
{
   std::cout << "(";
   (..., print_with_delim(std::get<I>(tup), I, index_s.size(), sep)); // Fold expression: get<0>, get<1>, ...
   std::cout << ")";
}

// Wrapper for printing a tuple
template<typename... T>
void print_iterable(const std::tuple<T...>& tup, const std::string& sep)
{
   print_iterable(tup, std::make_index_sequence<sizeof...(T)>(), sep); // make_index_sequence -> 0, 1, 2, ..., N-1 
}

// Print a pair
template<class T1, class T2>
void print_iterable(const std::pair<T1, T2>& pair, const std::string& sep)
{
   std::cout << "(";
   print_iterable(pair.first, sep);
   std::cout << " : ";
   print_iterable(pair.second, sep); 
   std::cout << ")";
}

// Print an iterable (can be deeply nested)
template<Iterable T>
void print_iterable(const T& t, const std::string& sep)
{  
   int indx = 0;
   std::cout << '[';
   for (auto it = t.begin(); it != t.end(); ++it) {
      print_iterable(*it, sep); // <---- Recursive call to go one level deeper

      if (indx++ != t.size() - 1) { 
         std::cout << sep; 
      }
   } 
   std::cout << ']';
}

// Wrapper
template<typename T>
void print(const T& t, const std::string& sep, const std::string& end)
{
   print_iterable(t, sep);
   std::cout << end;
}