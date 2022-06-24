/*
Author: 		The Egg Gang
Prorgam: 		File Extract
Description:	Read in a text file, extract the first letter
				from each word in the file, and then output those
				letters in order under a new output file.
*/

#include <stdio.h>
#include <string.h>

#define MAX_CHARS 100 //max chars per word
#define MAX_WORDS 1000 //max num of words

void extract(char word[][101], int num_words, char *result);

int main()
{
	char words[MAX_WORDS + 1][MAX_CHARS + 1]; //array of strings from input
	char str[MAX_CHARS + 1]; //resulting string
	char filename[MAX_CHARS + 1];//filename

	printf("\nEnter the filename: ");
	scanf("%s", filename);
	// for filename examples, use either message.txt, vickenstrips.txt, or create your own text file

	FILE *fr = fopen(filename, "r"); //open in read mode

	if(fr == NULL) //checking if opening with error
	{
		printf("ERROR TOO BAD LOL\n");
		return 1; //abnormal termination
	}

	int i; //i counts number of strings read from file
	for(i = 0; !feof(fr) && !ferror(fr); i++)
		fscanf(fr, "%s", words[i]);
	
	strcat(filename, ".dcf"); //name of output file

	fclose(fr);

	//writing to file, aka output
	FILE *fw = fopen(filename, "w"); //open in write mode

	if(fw == NULL) //checking if opening with error
	{
		printf("ERROR TOO BAD LOL\n");
		return 1; //abnormal termination
	}

	extract(words, i, str);
	printf("\nYour decrypted file name is: %s", filename);
	fprintf(fw, "\n%s\n\n", str); //same as printf but for files
	printf("\nYour fancy message is: %s", str);

	fclose(fw);
	
	return 0;
}

void extract(char word[][101], int num_words, char *result)
{
	int i;
	for(i = 0; i < num_words; i++)
		result[i] = word[i][0]; //first character of each string

	result[i] = '\0';

}