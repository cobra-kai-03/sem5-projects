// C++ program Implementing One Time Pad Algorithm

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// Method 1
// Returning encrypted text
string stringEncryption(string text, string key)
{

	// Initializing cipherText
	string cipherText = "";

	// Initialize cipher array of key length
	// which stores the sum of corresponding no.'s
	// of plainText and key.
	int cipher[key.length()];

	for (int i = 0; i < key.length(); i++) {
		cipher[i] = text.at(i) - 'A' + key.at(i) - 'A';
	}

	// If the sum is greater than 25
	// subtract 26 from it
	// and store that resulting value
	for (int i = 0; i < key.length(); i++) {
		if (cipher[i] > 25) {
			cipher[i] = cipher[i] - 26;
		}
	}

	// Converting the no.'s into integers

	// Convert these integers to corresponding
	// characters and add them up to cipherText
	for (int i = 0; i < key.length(); i++) {
		int x = cipher[i] + 'A';
		cipherText += (char)x;
	}

	// Returning the cipherText
	return cipherText;
}

// Method 2
// Returning plain text
static string stringDecryption(string s, string key)
{
	// Initializing plain text
	string plainText = "";

	// Initializing integer array of key length
	// which stores difference
	// of corresponding no.'s of
	// each character of cipherText and key
	int plain[key.length()];

	// Running for loop for each character
	// subtracting and storing in the array
	for (int i = 0; i < key.length(); i++) {
		plain[i] = s.at(i) - 'A' - (key.at(i) - 'A');
	}

	// If the difference is less than 0
	// add 26 and store it in the array.
	for (int i = 0; i < key.length(); i++) {
		if (plain[i] < 0) {
			plain[i] = plain[i] + 26;
		}
	}

	// Converting int to corresponding char
	// add them up to plainText
	for (int i = 0; i < key.length(); i++) {
		int x = plain[i] + 'A';
		plainText += (char)x;
	}

	// Returning plainText
	return plainText;
}


static const char pool[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int poolsize=sizeof(pool)-1;

char get_char()
{
    return(pool[rand()%poolsize]);
}

// Method 3
// Main driver method
int main()
{
	while(true)
	{
	

    cout<<"Do you want: "<<endl;
    cout<<"1.Predefined key"<<endl;
    cout<<"2.Random Key"<<endl;
	cout<<"3.Any key to exit"<<endl;

    int ch;
    cout<<"Enter choice"<<endl;
    cin>>ch;

	if(ch!=1 && ch!=2){
        cout<<"Invalid choice!!!!"<<endl;
       exit(1);
    }

	// Declaring plain text
	//string plainText = "Hello";
    cout<<"Enter plaintext to be encrypted: "<<endl;
    string plainText;
    cin>>plainText;


	// Generating Random key of the length of plaintext
    string key;
    if(ch==1)
    {
        cout<<"Enter key: "<<endl;
        cin>>key;
    }
    else if(ch==2)
    {
    for(int i=0;i<plainText.length();i++)
    {
        key+=get_char();
    }
    }
	// Converting plain text to toUpperCase
	// function call to stringEncryption
	// with plainText and key as parameters
	for (int i = 0; i < plainText.length(); i++) {
		// convert plaintext to uppercase
		plainText[i] = toupper(plainText[i]);
	}
	for (int i = 0; i < key.length(); i++) {
		// convert key to uppercase
		key[i] = toupper(key[i]);
	}
	string encryptedText = stringEncryption(plainText, key);

	// Printing cipher Text
	cout << "Cipher Text - " << encryptedText << endl;

	// Calling above method to stringDecryption
	// with encryptedText and key as parameters

	cout << "Message - "
		<< stringDecryption(encryptedText, key)<<endl;

	}

	return 0;
}

