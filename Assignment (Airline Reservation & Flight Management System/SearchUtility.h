#ifndef SEARCHUTILITY_H
#define SEARCHUTILITY_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Generic template search function
// T     = type of pointer (Flight* or Passenger*)
// Match = a function or functor that returns bool
template <typename T, typename Match>
T findItem(const vector<T>& collection, Match matchFunction) {
    // Use find_if from STL algorithms to search the collection
    typename vector<T>::const_iterator it = find_if(
        collection.begin(),
        collection.end(),
        matchFunction
    );

    if (it != collection.end()) {
        return *it;
    }

    return nullptr;
}

// Generic template function to display all items in a collection
template <typename T>
void displayAll(const vector<T>& collection) {
    if (collection.empty()) {
        cout << "No items found." << endl;
        return;
    }
    for (int i = 0; i < (int)collection.size(); i++) {
        collection[i]->displayDetails();
        cout << endl;
    }
}

#endif
