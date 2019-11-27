#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;


int main()
{
	char word1[50], word2[50];
	
	cin.getline(word1, 50);
	cin.getline(word2, 50);
	
	
	
	if(word1 == word2){
		cout << "sao iguais" << endl;
	}
	else if(word1 < word2){
		cout << word1 << " vem primeiro" << endl;
	}
	else{
		cout << word2 << " vem primeiro" << endl;
	}
	return 0;
}