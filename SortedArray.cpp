#include "SortedArray.h" // Include the header file of the class

SortedArray::SortedArray() : Array() {} // Empty constructor for the creation of the array. Same as base class Array()

int SortedArray::BinarySearch(WordPair pair) {
    // Sets a low and high values that indicate the "size" of the array that is searching for the pair
    int low = 0; // The start of the array
    int high = maxSize - 1; // The end of the array
    while (low <= high) {
        // As long as high is greater than low
        int mid = (high + low) / 2; // value that indicates the middle position of the array
        if (data[mid].getPair() == pair.getPair()) {
            // if pair is found returns the counter of the current object
            return data[mid].getCounter();
        }
            // if not , resizes the array by changing the values of low and high
        else if (data[mid].getPair() < pair.getPair()) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

void SortedArray::AddPair(const std::string &pair) {
    // Checks if the elements of the table are greater than or equal to max size of the array
    if (elements >= maxSize) {
        // If they are then the array first increases capacity with the function IncreaseCapacity()
        IncreaseCapacity();
    }

    // Then adds the new object in the last position of the elements
    data[elements] = WordPair(pair);
    // Then increases the elements of the table
    elements ++;
}



void SortedArray::swap(WordPair &a,WordPair &b) {
    // Swaps the objects
    WordPair temp = a;
    a = b;
    b = temp;
}

int SortedArray::partition(int low,int high) {
    // Continually swaps the objects with the swap function
    //Until the array is sorted
    WordPair pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (data[j].getPair() <= pivot.getPair()) {
            i++;
            swap(data[i],data[j]);
        }

    swap(data[i + 1],data[high]);

    return i + 1;
}
void SortedArray::QuickSort(int low,int high) {
    // Sorting the arry using the partition function
    if (low < high) {
        int pi = partition(low,high);
        QuickSort(low,pi - 1);
        QuickSort(pi + 1,high);
    }
}

