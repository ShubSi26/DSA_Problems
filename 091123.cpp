#include <iostream>
using namespace std;
#define SIZE 100
int calHash(int key, int size) {
return key % size;
}
int main() {
int size, numKeys;
cout<<"Enter Hash table size: ";
cin >> size;
cout<<"Enter number of keys: ";
cin >> numKeys;

int keys[numKeys];
int hashTable[SIZE];
for (int i = 0; i < SIZE; i++) {
hashTable[i] = -1;
}
for (int i = 0; i < numKeys; ++i) {
cout<<"Enter Key: ";
cin >> keys[i];
}

int minIndices[numKeys];
for (int i = 0; i < numKeys; ++i) {
int key = keys[i];
int index = calHash(key, size);

while (hashTable[index] != -1) {
index = (index + 1) % size;
}
hashTable[index] = key;

int mIndex = index;
while (keys[i] != hashTable[mIndex]) {
mIndex = (mIndex + 1) % size;
}
minIndices[i] = mIndex;
}
for (int i = 0; i < numKeys; ++i) {
for (int j = i + 1; j < numKeys; ++j) {
if (minIndices[i] > minIndices[j]) {
int temp = minIndices[i];
minIndices[i] = minIndices[j];
minIndices[j] = temp;
temp = keys[i];
keys[i] = keys[j];
keys[j] = temp;
}
}
cout << "index: " << minIndices[i] << ", value: " << keys[i] << endl;
}
return 0;
}