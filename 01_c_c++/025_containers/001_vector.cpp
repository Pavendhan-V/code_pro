

/*

Initialization and assignment:
    1. std::vector<int> v;                      // default constructor
    2. std::vector<int> v(size, value);         // Initializes with given size and default value
    3. std::vector<int> v { elements };         // List initialization
    4. v = { elements };                        // Assignments

Capacity:
    1. size();                      // return the number of elements
    2. capacity();                  // returns the allocated storage
    3. resize(n, value);            // resizes to n with option value
    4. reverse(n);                  // reverse capacity for n elements
    5. shrink_to_fit();             // reduce capacity to match size
    6. empty();                     // check if the vector is empty

Element access:
    1. v[i];                        // access element at index i (no bounds checking)
    2. v.at(i);                     // access the element with bounds checking
    3. v.front();                   // access the first element
    4. v.back();                    // access the last element
    5. v.data();                    // returns a pointer to the underlying array

Modifiers:
    1. push_back(value);            // adds an element to the end
    2. pop_back();                  // removes the last element
    3. insert(pos, value);          // insert the value at the specified position
    4. erase(pos);                  // removes an element at position
    5. clear();                     // clear all the elements
    6. swap(other);                 // swaps contents with other elements
    7. assign(n, value);            // assign new content
    8. emplace(pos, args...);       // construct an element in-place at pos
    9. emplace_back(args...);       // construct and appends an element

Iterators:
    1. begin();, end();             // return iterators to the start and end.
    2. rbegin();, rend();           // reverse iterators
    3. cbegin();, cend();           // const iterators

*/





#include <iostream>
#include <vector>

using namespace std;


int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5 };

    std::cout << v.front() << std::endl;
    std::cout << v.back() << std::endl;

    // v.reserve(v.size());

    // for (auto i : v) {
    //     std::cout << i << " " << std::endl;
    // }
}