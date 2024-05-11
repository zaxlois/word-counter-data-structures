#include "Array.h" // Include the header file of the class

Array::Array() {
    maxSize = InitialSize; // Sets the size as the initial size
    data = new WordPair[maxSize]; // Binds space for the array
    elements = 0; // Sets the variable to zero
}

Array::Array(int size) {
    maxSize = size; // Sets the size as the custom size in parameter
    data = new WordPair[maxSize]; // Binds space for the array
    elements = 0; // Sets the variable to zero
}

void Array::AddPair(const string &pair) {
    // Checks if the elements of the table are greater than or equal to max size of the array
    if (elements >= maxSize) {
        // If they are then the array first increases capacity with the function IncreaseCapacity()
        IncreaseCapacity();
    }
    // Then adds the new object in the last position of the elements
    data[elements] = WordPair(pair);
    // Then increases the elements of the table
    elements++;
}

void Array::IncreaseCapacity() {
    // This function creates an array that its size is the same as the main array plus the initial size
    // And copies the elements of the main array to the other

    WordPair *temp; // The new array
    int newSize = maxSize + InitialSize; // The new size
    temp = new WordPair[newSize]; // Binds space for the new array

    // Copies the elements
    for (int i = 0; i < maxSize; i++) {
        temp [i] = data[i];
    }

    delete [] data; // Deletes the objects of the main array
    data = temp; // Sets the array that we made as the main array
    maxSize = newSize; // Sets the max size as the new size
}

void Array::fixTable() {
    // This function creates an array that its size is equal with the elements of the main array
    // And copies the elements in the new array

    WordPair *temp; // The new array
    temp = new WordPair[elements]; // Binds space for the new array

    //Copies the elements
    for (int i = 0; i < elements ; i++) {
        temp[i] = data[i];
    }

    delete [] data; // Deletes the objects of the main array
    data = temp; // Sets the array that we made as the main array
    maxSize = elements; // Sets the max size as the elements value
}

int Array::getElements() {return elements;} // Returns the elements value

WordPair Array::getObject(int pos) {return data[pos];} // Returns the object of a specific object in the array based the parameter

bool Array::isPairIn(const std::string &pair) {
    // This function is searching if the pair that is a parameter exists in the array
    // If exists , the object that has the pair increases counter by 1
    for (int i = 0;i < elements; i++) {
        if (data[i].getPair() == pair) {
            data[i].IncreaseCounter();
            return true; // Returns true if it was found
        }
        // Because the array maybe has some empty space if the searching finds an empty slot returns false
        if (data[i].getPair().empty()) {
            return false;
        }
    }
    return false;
}

void Array::insertPair(WordPair key) {
    // This function inserts a WordPair object in the array
    data[elements] = key;
    elements++; // Increases the elements value
}