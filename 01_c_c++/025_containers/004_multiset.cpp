/*

Initialization:
    1. std::multiset<int> ms;                           // default constructor
    2. std::multiset<int> ms = { 1, 2, 2, 3, 3 };       // initializer list
    3. custom comparator
        struct decendingComparator {
            bool operator()(int a, int b) const {
                return a > b;
            }
        };

        std::multiset<int decendingComparator> ms;

Capacity:
    1. size();              // returns the number of element in the multiset
    2. empty();             // check if the multiset empty
    3. max_size();          // returns the maximum number of elements the multiset can hold


Modifiers:
    1. insert(value);                   // insert a value into multiset
    2. emplace(value);                  // construct and insert a value in place
    3. erase(value);                    // removes all occurrence of a specific value
    4. erase(pos);                      // removes an element at a specific iterator position
    5. clear();                         // removes all elements from the multiset
    6. swap(other_multiset);            // swaps contents with other multiset

lookup:
    1. count(value);                    // returns a number of occurrence of a specific value
    2. find(value);                     // returns an iterator to the first occurrence of the value ( or end() if not found)
    3. equal_range(value);              // returns a pair of iterators defining the range of elements equal to a given value
    4. lower_bound(value);              // returns an iterator to the first element not less then given value
    5. upper_bound(value);              // returns an iterator to the first element greater than give value

Iterators:
    1. begin();, end();                 // iterators to traverse the multiset
    2. rbegin();, rend();               // revers iterators
    3. cbegin();, cend();               // const iterators

*/