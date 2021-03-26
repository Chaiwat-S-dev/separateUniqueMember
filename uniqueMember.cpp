#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

const char *input[] = {"Red", "Yellow", "Blue", "Black", "Red", "White", "Blue", "Red", "Green"};
// const char *base[] = {"Red", "Yellow", "Blue", "Black", "White", "Green"};
char output[10][10];
const char **p = input;
int indexRepeat[6] = {0};
int countRepeat = 0;
int mainCount = 0;

int main() {
    while(mainCount < 6) {
        for (int i = mainCount+1; i < 9; i++) {
            // cout << "Compare on: " << input[mainCount] << ',' << input[i] << endl;
            for (int i = 0; i < countRepeat; i++) {
                if(i == mainCount) {
                    mainCount++;
                    break;
                }
            }
            if(strcmp(input[mainCount], input[i]) == 0) {
                // cout << "Found repeat on: " << input[mainCount] << ',' << input[i] << endl; 
                // cout << "index keep: " << i << endl;
                indexRepeat[countRepeat++] = i;
            }
        }
        mainCount++;
    }
    cout << "Count repeat is: " << countRepeat << endl;
    cout << "Index repeat: ";
    for (int i = 0; i < countRepeat; i++)
        cout << indexRepeat[i] << ", ";
    cout << endl;

    cout << "Val repeat : ";
    for (uint8_t i = 0; i < countRepeat; i++)
        cout << input[indexRepeat[i]] << ", ";
    cout << endl;

    int *ptr = indexRepeat;
    char *dest = output[0];
    for(int i = 0; i < 9; i++) {
        if(i != *ptr) {
            strcpy(dest, input[i]);
            // cout << "Size of arr char is : " << sizeof(output[0]) << endl;
            dest += sizeof(output[0]);
        }
        else
            ptr++;
    }
    
    cout << "Result: ";
    for(auto i : output)
        cout << i << ", ";
    cout << endl;
    return 0;
}