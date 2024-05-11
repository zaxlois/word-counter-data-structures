#include "UnsortedArray.h" // Include the header file of the class

UnsortedArray::UnsortedArray() : Array() {} // Empty constructor. Same as the Array constructor

int UnsortedArray::SequentialSearch(WordPair pair) {
    // This function searches serially for the object from the parameter
    // and if the pair of the object is the same as the pair from the array
    //  returns the counter of the pair in the array
    for (int i = 0; i < maxSize; i++) {
        if (data[i].getPair() == pair.getPair()) {
            return data[i].getCounter();
        }
    }
    return 0; // If the pair wasn't found 0 is returned
}

void UnsortedArray::AddPair(const std::string &pair) {
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