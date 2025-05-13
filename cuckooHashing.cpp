#include <iostream>
#include <vector>

const int SIZE = 11;

std::vector<std::vector<int>> hashTable(SIZE, std::vector<int>(2, -1));

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = index;

    while (hashTable[i][0] != -1 && hashTable[i][1] != -1 && i < SIZE) {
        i = (i + 1) % SIZE;
    }

    if (hashTable[i][0] == -1) {
        hashTable[i][0] = key;
        std::cout << "Key " << key << " inserted at row " << i << ", column 0." << std::endl;
    } else if (hashTable[i][1] == -1) {
        hashTable[i][1] = key;
        std::cout << "Key " << key << " inserted at row " << i << ", column 1." << std::endl;
    } else {
        std::cout << "Hash Table Overflow" << std::endl;
    }
}

void displayHashTable() {
    std::cout << "Hash Table:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Row " << i << ": [" << hashTable[i][0] << ", " << hashTable[i][1] << "]" << std::endl;
    }
}

int getKeyInput() {
    int key;
    std::cout << "Enter a key to insert: ";
    std::cin >> key;
    return key;
}

void displayMenu() {
    std::cout << "\nMenu:" << std::endl;
    std::cout << "1. Insert a key" << std::endl;
    std::cout << "2. Display the hash table" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int key = getKeyInput();
                insert(key);
                break;
            }
            case 2:
                displayHashTable();
                break;
            case 3:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}