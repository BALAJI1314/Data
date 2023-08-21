#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // Size of the hash table

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Function to insert a key into the hash table
void insert(int hashTable[], int key) {
    int index = hash(key);

    // Linear probing
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE; // Move to the next slot
    }

    hashTable[index] = key;
}

// Function to display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: %d\n", i, hashTable[i]);
    }
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // Initialize all slots to -1 (indicating empty)
    }

    int keys[] = {45, 22, 17, 30, 80, 29, 53};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }

    display(hashTable);

    return 0;
}

