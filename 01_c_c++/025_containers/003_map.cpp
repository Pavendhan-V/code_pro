/*

Initialization:
    1. std::map<int, std::string> m;                                        // default constructor
    2. std::map<int, std::string> m = { {1, "one"}, { 2, "two"} };          // initilizer list
    3. custom comparator

        struct custom {
            bool operator()(const int &a, const int &b) const {
                return a > b;
            }
        };

        std::map<int, std::string, custom> m;

capacity:
    1. size();              // returns the number of key-value pairs in the map
    2. empty();             // checks if the map is empty
    3. max_size();          // returns the maximum number of key-value pairs the map can hold

Element access:
    1. m[key];              // Access the value associated with the key (inserts default value if the key is not present)
    2. at(key);             // Access the value associated with the key (throws std::out_of_range if the key is not present)

Modifiers:
    1. insert({key, value});                        // insert a key-value pair value
    2. emplace(key, value);                         // constuct and insert a key-value pair in place
    3. erase(key);                                  // removes an element by key
    4. erase(pos);                                  // removes an element at specified iterator position
    5. clear();                                     // removes an all the element from map
    6. swap(other_map);                             // swaps contents with another map
    7. insert_or_assign(key, value);                // insert or assigns a value to a key

Lookup/element access:
    1. find(key);                                   // Returns an iterator to the key-value pair (or end() if the key is not found).
    2. count(key);                                  // returns 1 if the key exist, otherwise 0
    3. lower_bound(key);                            // returns an iterator to the first element not less then key
    4. upper_bound(key);                            // returns an iterator to the first element not greater then key
    5. equal_range(key);                            // Returns a pair of iterators representing the range of equal elements (always unique in std::set).

Iterators:
    1. begin();, end();             // iterators to traverse elements
    2. rbegin();, rend();           // reverse iterator
    3. cbegin();, cend();           // const iterator

*/