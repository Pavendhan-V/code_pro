
/*

Initialization:
    1. std::unordered_set<int> us;                              // default constructor
    2. std::unordered_set<int> us = {1, 2, 3, 4, 5};            // initializer list
    3. custom hash and equality function
        stuct customHash {
            bool operator()(int x) {
                return x % 10;
            }
        };
        struct customEqual {}
            bool operator()(int a, int b) {
                return a == b;
            }
        };

        std::unordered_set<int, customHash, customEqual> us;

Capacity:
    1. size();              // returns the number of elements in the unordered_set
    2. empty();             // returns true if the unordered_set is empty, otherwise false
    3. max_size();          // returns the maximum number of elements the unordered_set can hold

Modifiers:
    1. insert(value);               // inserts a unique value into the unordered_set
    2. emplace(value);              // constructs and inserts a value in place
    3. erase(value);                // removes an element by value
    4. erase(iterator);             // removes an element at the iterator position
    5. clear();                     // removes all elements from the unsorted_set
    6. swap(other_unsorted_set);    // swaps the contents with another unsorted_set

Lookup:
    1. find(value);                 // returns an iterator to the element if found, otherwise end()
    2. count(value);                // return 1 if the value exists, otherwise 0

Bucket interface:
    1. 

*/