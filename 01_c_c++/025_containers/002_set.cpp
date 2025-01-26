

/*

Initialization:
    1. std::set<int> s;                     // default constructor
    2. std::set<int> s = { 1, 2, 3, 4 };    // initializer list
    3. std::set<int, std::greater<int>> s;  // custom comparator, descending order

Capacity:
    1. size();              // returns the number of elements in the set
    2. empty();             // checks if the set is empty
    3. max_size();          // return the maximum number of elements the set can hold

Modifiers:
    1. insert(value);               // insert an element
    2. emplace(value);              // constructs and inserts an element in place
    3. erase(pos);                  // removes the element at the specified position
    4. erase(value);                // removes the element by the value
    5. clear();                     // removes all the elements from the set
    6. swap(other_set);             // swap the content with another set

Element access:
    1. find(value);                 // returns an iterator to the element (or end() if not found)
    2. count(value);                // returns 1 if the element exist, otherwise 0
    3. lower_bound(value);          // returns an iterator to the first element not less then value
    4. upper_bound(value);          // returns an iterator to the first element not greater then value
    5. equal_range(value);          // Returns a pair of iterators representing the range of equal elements (always unique in std::set).

Iterators:
    1. begin();, end();             // iterators to traverse elements
    2. rbegin();, rend();           // reverse iterator
    3. cbegin();, cend();           // const iterator

*/