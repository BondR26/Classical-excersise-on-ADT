#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ciso646>

#include "bin_tree_int.h"
#include "stack.h"
#include "binarytree_words.h"
#include "petsh.h"
char** read_the_word(FILE* file);

#define THIRD_T


int main(int argc, char* argv)
{
	srand(time(0));

#ifdef FIRST_T 1
	while (1)
	{
		std::cout << "My own stack (made from connected list. with noded made from every letter in line) \n";

		char line[CHAR_MAX];
		Stack s_line;
		std::cout << "Please enter the line ";
		std::cin.getline(line, CHAR_MAX);

		s_line.form_stack(line, &s_line);

		s_line.show_stack_backwards(s_line.show_stack_forward(&s_line));

		
	}
#elif SECOND_T 2 
	
	int num_tree;
	std::cout << "Please enter the number of elemtets you want to have in binary tree ";
	std::cin >> num;
	ARR arr(num);

	
	
	while (1)
	{
		std::cout << "Please choose what to do with binary tree \n";
		std::cout << " 1 sort , 2 fill with rand numbers \n" ;
		std::cout << " 3 show , 4 find number in binary tree \n";
		
		if (choice == 1)
		{
			arr.sort();
			std::cout << "Tree if sorted\n";
		}
		else if (choice == 2)
		{
			
			arr.fill_rand();
			std::cout << "Tree if filled\n";
		}
		else if (choice == 3)
		{
			arr.show();
		}
		else if (choice == 4)
		{
			int num;
			std::cout << "Pleasr anter the number to  ";
			std::cin >> num;

			if (arr.find_bin_way(num))
			{
				std::cout << "The num was found\n";
			}
			else
			{
				std::cout << "The num wasnt found \n";
			}
		}
		else if (choice == 5)
		{
			std::cout << "Good bye \n";
			break;
		}
	}
	
	
	
	

#elif THIRD_T 3

	Word* words = new Word;
	char** word;
	FILE* file;

	file = fopen("the_text.txt", "rb");

	word = read_the_word(file);
	
	int count = 0;
	 
	/*while (word[count][0] != EOF)
	{
		std::cout << word[count++] << std::endl;
	}*/

	count = 0;//rewind the count in order to start fro the begining

	while (word[count][0] != EOF) // adding all the word into the ninary tree
	{
		words->AddItem(words, word[count++]);
	}

	words->count_of_all_words = count;

	char choice;
	while (1)
	{
		
		std::cout << "Please enter 1 to display all the word, 2 to delete all the words, 3 to look for the word and 4 to end task\n";
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "All words writtten to binary and displayed wit the help of recursion\n";

			words->display_the_word(words);
		}
		else if (choice == 2)
		{
			
			words->delete_all_the_words(words);
			std::cout << "All words are removed\n";
		}
		else if (choice == 3)
		{

			std::cout << "Please write a word you want to look for in the binary tree ";

			char word_searched[CHAR_MAX];

			std::cin.getline(word_searched, CHAR_MAX);

			if (Word* found = words->find_the_word(words, word_searched))
			{
				std::cout << "The word was found and it is in text " << found->count_of_similair_items << " times " << std::endl;
			}
			else if (words->find_the_word(words, word_searched) == nullptr)
			{
				std::cout << "The word wasnt found\n";
			}
		}
		else if (choice == 4)
		{
			std::cout << "Good bye \n";
			break;
		}
	}

	

	


	fclose(file);

#elif FOURTH_T 1

	Pets_Kind list_kind;
	FILE* file;
	try
	{
		file = fopen("dogs_and_nicknames.txt", "rb");
		if (file == NULL)
		{
			throw (-1);
		}
	}
	catch (int exception)
	{
		if (exception = -1)
		{
			std::cout << "File wasnt found\n";
			exit(1);
		}
	}

	int count = 0;
	char** names = read_the_word(file);



	while (names[count][0] != EOF)
	{	
		list_kind.AddPet(&list_kind, names[count], names[count+1]);//треба попрацювати над збергынанням ніків для кожного окремого виду 
		count+=2;
	}

	while (1)
	{
		char choice;
		std::cout << "Please enter what you want to do \n";
		std::cout << " Enter 1 to dosplay all the pets or press 2 to find some pet ";
		try
		{
			std::cin >> choice;
			
			throw choice;
			
		}
		catch (char x)
		{
			if (x < '1' and x > '2')
			{
				std::cin.ignore();
				std::cout << " Please try again \n";
				continue;
			}
		}

		if (choice == '1')
		{
			list_kind.DisplayPet(&list_kind);
		}
		else if (choice == '2')
		{

			char nick[CHAR_MAX];
			std::cout << "Please enter the name of the pet you want to find\n";
			try
			{
				std::cin.ignore();
				std::cin.getline(nick, CHAR_MAX);
				if (strlen(nick) > CHAR_MAX)
				{
					throw - 1;
				}
			}
			catch (int excpt)
			{
				if (excpt == -1)
				{
					std::cout << "Too mant character in line ";
					std::cout << " Please try again \n";
					continue;
				}
			}
			list_kind.DisplaySameNicknames(&list_kind, nick);
			std::cout << std::endl;
		}
		else if (choice == '3')
		{
			std::cout << "Goodbue my friend\n";
			break;
		}
	}
#endif

	return EXIT_SUCCESS;
}