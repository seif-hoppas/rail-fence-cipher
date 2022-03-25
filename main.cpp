// FCAI Ã¢â‚¬â€œ Programming 1 Ã¢â‚¬â€œ 2022 - Assignment 2
// Program Name: cipher_decipher.cpp
// Program Description: ciphering a message or deciphering it by a c++ program
// Last Modification Date: 3/23/2022
// Author1 and ID and Group: seif eldin mahmoud helmy , 20210169 , Group B
// Teaching Assistant: xxxxx xxxxx
// Purpose: to cipher a message or decipher a message
#include <bits/stdc++.h>
using namespace std;
void cipher(){
    string str , str2 ;
    int key ;
    cout << "please enter the message to cipher: " << endl;
    getline(cin,str);
    cout << "please enter the key"  << endl;
    cin >> key;
    cin.ignore();
    str.erase(remove(str.begin(), str.end(), ' '), str.end());// to remove spaces
    for_each(str.begin(), str.end(), [](char & c) {
        c = tolower(c); // to get all the characters in lower case
    });
    if (key == 3)
    {for(int i = 0 ; i < str.length() ; i += 4){
            cout << str[i];
        }
        for (int j = 1 ; j < str.length(); j += 2){
            cout << str[j];
        }
        for (int k = 2 ; k < str.length(); k += 4){
            cout << str[k];
        }}
    else if (key == 4){
        for(int i = 0 ; i < str.length() ; i +=6){
            cout << str[i];
        }
        for (int j = 1 ; j < str.length(); j += 4){
            cout << str[j];
        }
        for (int k = 2 ; k < str.length(); k += 2){
            cout << str[k];
            k += 2;
        }
        for (int z = 3 ; z < str.length(); z +=6){
            cout << str[z];
        }
    }

}
void decipher() {
    string text ;
    string str = "";
    int key , size ;
    cout << "please enter the message to decipher: " << endl;
    getline(cin,text);
    size = text.length();//the rows are text size
    cout << "please enter the key"  << endl;
    cin >> key; // the columns are the key;
    char decipher[key][size];
    for (int i = 0 ; i < key ; ++i){
        for (int j = 0 ; j < size ; ++j){
            // giving the array null
            decipher[i][j] = 0;
        }

    }
    for (int i = 0 , j = 0 , z = 1 ; j < size ; i += z , ++j){
        // let every index in this for loop to be *
        decipher[i][j] = '*';
        if(i == key-1){
            // last row is key - 1
            z = -1; // if i == the last index in the rows then lets decrease it by 1
        }
        else if (i == 0){
            z = 1;
        }

    }
    int count = 0;
    for (int i = 0 ; i < key ; ++i){
        for (int j = 0 ; j < size ; ++j){
            if (decipher[i][j] == '*'){ // if the indexes has the value of *
                decipher[i][j] = text[count++]; // give it text[index] and increase the index by 1
            }
        }
    }
    for (int i = 0 , j = 0 , z = 1 ; j < size ; i += z , ++j){
        str += decipher[i][j];// append on the string every character
        if(i == key-1){
            z = -1;
        }
        else if (i == 0){
            z = 1;
        }
    }
    cout << str << endl;
}

int main() {
    cout << "Ahlan ya user ya habibi , what do u want to do today " << endl;
    cout << "1- Cipher\n2- Decipher\nplease choose 1 or 2  " << endl;
    int num;
    cin >> num;
    cin.ignore();
    if (num == 1) {
        cipher();
    } else if (num == 2) {
        decipher();

    } else {
        cout << "Invalid choice " << endl;
    }
}
