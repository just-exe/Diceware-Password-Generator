#include <iostream>
#include <fstream>
#include <string.h>
#include <random>
#include <vector>
#include <time.h>

using namespace std;

int main() {
    string number = "";
    string word = "";
    vector<string> allNums;
    vector<string> words;
    int numWords;

    ifstream in;
    in.open("1.txt");

    if (in.fail()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    //Gather input for password
    cout << "Hello! How many words would you like your password to have?" << endl;
    cin >> numWords;

    //Create numbers to find corresponding words
    srand(time(NULL));
    for(int j = 0; j < numWords; j++){
        for (int i = 0; i < 5; i++) {
         number += to_string(rand() % 6 + 1);
        }
        allNums.push_back(number);
        //cout << allNums.at(j) << endl;
        number = "";
    }

    //Seek file for number match, then store word in vector
    for (int i = 0; i < numWords; i++) {
        in.clear();
        in.seekg(0, ios::beg);
        while(getline(in, word)) {
            //cout << allNums.at(i);
            if (word.substr(0, 5) == allNums.at(i)) {
                word = word.substr(6, 9);
                words.push_back(word);
                //cout << word << endl;
                continue;
            }
        }
    }

    //Displaying new password to user
    cout << "Your password is:" << endl;

    for (int i = 0; i < numWords; i++) {
        cout << words.at(i) << " ";
    }

    in.close();
    return 0;
}