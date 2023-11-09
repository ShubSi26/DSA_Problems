#include <iostream>
using namespace std;

int midSquareHash(int key, int tableSize, int r) {
int squared = key * key;
int middleDigit = (squared / 10) % 10;
int hashIndex = middleDigit % tableSize;

return hashIndex;
}
int main() {
int tableSize = 100;
int numKeys;
cin >> numKeys;
int keys[numKeys];
for (int i = 0; i < numKeys; i++) {
cin >> keys[i];
}
int hashTable[tableSize];
for (int i = 0; i < tableSize; i++) {
hashTable[i] = -1;
}
for (int i = 0; i < numKeys; i++) {
int key = keys[i];
int hashIndex = midSquareHash(key, tableSize, 1);
while (hashTable[hashIndex] != -1) {
hashIndex = (hashIndex + 1) % tableSize;
}
hashTable[hashIndex] = key;
}
for (int i = 0; i < tableSize; i++) {
if (hashTable[i] != -1) {
cout << "Index " << i << ": Key " << hashTable[i] << endl;
}
}
return 0;
}