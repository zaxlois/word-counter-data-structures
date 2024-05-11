#include "HashTable.h" // Include the header file of the class

HashTable::HashTable() : Array() {
    for (int i = 0; i < maxSize; i++) {
        data[i].setPair();//
    }
}

int HashTable::Hash(const std::string &pair)  {
    int sum = 0;//set sum to 0
    for (char c : pair)//
        sum ++;

    return sum % maxSize;
}

void HashTable::IncreaseCapacity() {
    WordPair *temp;//Creating a  new array
    int newSize = maxSize + InitialSize;//Setting the new size
    temp = new WordPair[newSize];//binding space for the new array

    for (int i = 0; i < newSize; i++)
        temp[i].setPair();//copies the elements

    for (int i = 0; i < maxSize; i++) {
        if (!data[i].getPair().empty()) {
            int newIndex = Hash(data[i].getPair());
            while (!temp[newIndex].getPair().empty()) {
                newIndex = (newIndex + 1) % newSize;
            }
            temp[newIndex] = data[i];
        }
    }
    delete [] data;//delete the objects from the main array
    data = temp;//Sets the array we created as the main array
    maxSize = newSize;//Sets the max size as the new size
}

int HashTable::search(WordPair pair) {
    int index = Hash(pair.getPair());
    while (!data[index].getPair().empty()) {
        if (data[index].getPair() == pair.getPair()) {
            return data[index].getCounter();
        }
        index = (index + 1) % maxSize;
    }
    return 0;
}

void HashTable::AddPair(const std::string &pair) {
    if (elements >= maxSize) {
        IncreaseCapacity();//Increasing the size if there is no more space
    }
    int index = Hash(pair);//creating the index using the hash function
    while (!data[index].getPair().empty()) {
        index = (index + 1) % maxSize;
    }
    data[index] = WordPair(pair);
    elements ++;//increase the elements
}

bool HashTable::isPairIn(const string & pair) {
    for (int i = 0 ; i < maxSize ; i++) {
        if (data[i].getPair() == pair) {//checking if the pair already exists in the table
            data[i].IncreaseCounter();//increasing the counter of the Pair
            return true;
        }
    }
    return false;
}
