#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream> 
//#include <bits/stdc++.h>

using namespace std;

class endec {				// Klass erstellen
	int key;
	string txt = "TextFile1.txt";
	char c;


public:
	void encrypt();
	void decrypt();
};

void endec::encrypt() {				// implementing key for encrypt data and enter the key (free choice)
	cout << "key: ";
	cin >> key;

	//string test = "test";
	string test = "";
	cin >> test;
	fstream fin, fout;				//fstream is used to read informations from files and write to files 
	fin.open(txt, fstream::in);
	fout.open("TextFile1.txt", fstream::out);			// here i have to change to self made text (insert text); changed in line 27

	for (int a = 0; a <= test.length() - 1; a++) {		// get to every position in the char and begin with length char -1 (0) and then count up (a++)

		cout << a << "\t" << char(test[a]) << "\t" << char(test[a] + key) << "\n"; // position array; buchstabe in string; mit verschiebung und umwandlung zu char;
	}	// Hilfestellung bekommen für dieses Dokument an dieser Stelle mit der Formulierung in Code; die Vorgehensweise war klar, jedoch fehlte mir der Code um dies auszudrücken 

	/*while (fin >> noskipws >> c) {				//stream manipulation
		int temp = (c + key);					// c variable through char c in the beginning
		fout << (char)temp;
	}*/ // Teil der nicht funktionierte... out of order

	fin.close();
	fout.close();
}

void endec::decrypt() {				//  implementing class decryption
	cout << "key: ";
	cin >> key;
	string zwei = "";
	cin >> zwei;
	fstream fin;
	fstream fout;
	fin.open("TextFile1.txt", fstream::in);
	fout.open("TextFile1.txt", fstream::out);

	for (int b = 0; b <= zwei.length() - 1; b++) {
		
		cout << b << "\t" << char(zwei[b]) << "\t" << char(zwei[b] - 2*key) << "\n";

	//while (fin >> noskipws >> c) {			// remove key from encrypted text to decrypt 
		//int temp = (c - key);
		//fout << (char)temp;
	}
	fin.close();
	fout.close();
}

int main() {							// main program for interface
	endec enc;
	char c;
	cout << '\n';
	cout << "Enter your choice; \n";			// implementing a choice for user 
	cout << "1. encrypt \n";
	cout << "2. decrypt \n";
	cin >> c;
	cin.ignore();

	switch (c) {						// depends on choice; switch for initialise and running the selected choice
	case '1': {
		enc.encrypt();
		break;
	}
	case '2': {
		enc.decrypt();
		break;
	}
	}
}
