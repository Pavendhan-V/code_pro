
/*

Initializer:
    1. std::multimap<int, std::string> mm;                                                        // default constructor
    2. std::multimap<int, std::string> mm = { { 1, "one" }, { 2, "two" }, { 2, "duplicate" }};    // initializer list
    3. custom comparator
        struct custom {
            bool operator()(const int &a, const int &b) const {
                return a > b;
            }
        };
        std::multima<int, std::string, comparator> mm;

Capacity:
    1. size();              // returns the number of element in the multimap
    2. empty();             // returns true if the multimap is empty, otherwise false
    3. max_size();          // returns the maximum number of elements the multimap can hold

Element access:
    1. find(key);           // returns an iterator to the first element matching the key or end() if not found
    2. count(key);          // returns the number elements matching the key

Modifiers:
    1. insert({key, value});                    // insert a key-value pair
    2. emplace({key, value});                   // construct and insert a key-value pair in a place
    3. erase(key);                              // removes all the elements with the specific key
    4. erase(pos);                              // removes an element at a specific iterator position
    5. clear();                                 // removes all elements from the multimap
    6. swap(other_multipmap);                   // swaps the contents with another multimap

Lookup:
    1. equal_range(key);                        // returns a pair of iterators representing the range of elements matching the key
    2. lower_bound(key);                        // returns an iterator to the first element not less then the given key
    3. upper_bound(key);                        // returns an iterator to the first element greater than the given key

Iterators:
    1. begin();, end();                         // iterators to traverse the multimap
    2. rbegin();, rend();                       // reverse iterators
    3. cbegin();, cend();                       // const iterators


*/