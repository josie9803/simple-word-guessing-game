#include<iostream>
using namespace std;

int myStrlen (char str[]) //calculate the length of cstring
{
	int count = 0;
	while (str[count] != NULL)
		count++;
	return count;
}

bool findTheWord (char* word, char character) //check whether cstring contain a specific character
{
	for (int i = 0; word[i] != NULL; i++)
		if (word[i] == character)
			return true;
	return false;
}

bool myStrcmp (const char* str1, const char* str2) //check whether two cstrings are identical
{
	for (int i = 0; str1[i] != NULL || str2[i] != NULL; i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}

char* mysteryWord (char* word) //create an array that contains numbers of * which are equal to numbers of characters in cstring
{
	char* newMysteryWord = new char [myStrlen(word)+1];
	for (int i = 0; word[i] != NULL; i++)
		newMysteryWord[i] = '*';
	newMysteryWord[myStrlen(word)] = NULL;
	return newMysteryWord;
}

char* revealWord (char* word, char* temp, char character) //copy a specific character from cstring 1 to cstring 2
{
    for(int i = 0; i < myStrlen(word); i++)
        if (character == word[i])
			temp[i] = word[i];
	return temp;  
}

void printResult (char* word, char character) //print result whether user enters correct character
{
	if (findTheWord(word, character))
	{
		cout << "Got it!" << endl;
		cout << endl;
	}
	else 
		cout << "Sorry." << endl << endl;
}

int main()
{
	int number_of_guess;
	char* word = new char;
	char* temp;
	char character, say_yes;

	do
	{
		cout << "Enter the secret word (all in lowercase): ";
		cin >> word;
		temp = mysteryWord(word);
		
		if (myStrlen(word) < 10)
			number_of_guess = 10;
		else if (myStrlen(word) > 20)
			number_of_guess = 20;
		else
			number_of_guess = ((myStrlen(word))+5);

		cout << "=========================================" << endl << endl;

		bool done = false;
		for (int i = 0; (i < number_of_guess) && (!done); i++)
		{
			cout << "Word so far: " << temp << endl;

			cout << "Take guess number " << i + 1 << ": ";
			cin >> character;

			revealWord (word, temp, character);
			printResult(word, character);
		
			if (myStrcmp(word, temp))
				done = true;
		}
		
		if (done)
			cout << "Good. You correctly guessed the word: " << word << endl;
		else
			cout << "Sorry no more lives. The word is " << word << endl;

		cout << endl << "Do you want to play one more time? y/n ? ";
		cin >> say_yes;
		cout << endl;
	}
	while (say_yes == 'y');

	cout << "Bye!" << endl;

	system("pause");
	return 0;
}