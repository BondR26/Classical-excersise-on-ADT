
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "binarytree_words.h"

Word* Word::somewhere_to_put_it(Word* word_list_root, char word_to_add[])
{

	Word* copy = word_list_root;

	int count = 0;

	if (strcmp(copy->word, word_to_add) > 0)
	{
		count = 1;
		if (copy->left != NULL)
		{
			count = 0;
			somewhere_to_put_it(copy->left, word_to_add);
		}



	}
	else if (strcmp(copy->word, word_to_add) < 0)
	{
		count = 2;
		if (copy->right != NULL)
		{
			count = 0;
			somewhere_to_put_it(copy->right, word_to_add);
		}
	}
	else if (strcmp(copy->word, word_to_add) == NULL)
	{
		copy->count_of_similair_items++;
	}


	if (count == 1)
	{
		copy->left = new Word;
		strcpy(copy->left->word, word_to_add);
		copy->left->count_of_similair_items = 1;
		copy->left->left = nullptr;
		copy->left->right = nullptr;
	}
	else if (count == 2)
	{
		copy->right = new Word;
		strcpy(copy->right->word, word_to_add);
		copy->right->count_of_similair_items = 1;
		copy->right->left = nullptr;
		copy->right->right = nullptr;
	}


	return copy;

}

void Word::AddItem(Word* ptr_to_root, char word_to_add[])
{

	if (ptr_to_root->word[0] == '\0')
	{
		strcpy(ptr_to_root->word, word_to_add);

	}
	else
	{
		somewhere_to_put_it(ptr_to_root, word_to_add);
	}
}

void Word::display_the_word(Word* root)
{
	Word* copy = root;

	if (copy->left != NULL)
	{

		display_the_word(copy->left);
		
	}

	std::cout << copy->word << " times " << copy->count_of_similair_items << std::endl;

	if (copy->right != NULL)
	{
		display_the_word(copy->right);
		
	}

	

	//copy = nullptr;
}


Word* Word::find_the_word(Word* root, char word[])
{
	Word* copy = root;
	bool word_is_found = false;
	int count = 0;

	while (word_is_found != true and root->count_of_all_words != count and copy != NULL and copy->right != NULL and copy->left != NULL)
	{
		if (strcmp(word, copy->word) > 0)
		{
			copy = copy->right;
		}
		else if (strcmp(word, copy->word) < 0)
		{
			copy = copy->left;
		}
		else if (strcmp(copy->word, word) == NULL)
		{
			word_is_found = true;
			break;
		}
		count++;
	}

	if (word_is_found == true)
	{
		return copy;
	}
	else if (word_is_found == false)
	{
		return nullptr;
	}
}

Word::Word() : word{ '\0' }, count_of_similair_items(0), right{ nullptr }, left{ nullptr }, count_of_all_words(0)
{

}

void Word::delete_all_the_words(Word* root)
{
	root->count_of_all_words = 0;

	Word* copy = root;

	if (copy->left != NULL)
	{
		delete_all_the_words(copy->left);
	}

	if(copy->right != NULL)
	{
		delete_all_the_words(copy->right);
	}

	delete[] copy;

	//copy = nullptr;
}

char** read_the_word(FILE* file)
{
	char** arr = new char*;
	arr[0] = new char[CHAR_MAX];

	char ch;//this is where every symbol from the file will be stored

	int count = 0;//this is the count of the words
	int inner_count = 0; // this is the count for the symbol in a particular array

	bool flag;

	while (!feof(file))
	{
		ch = getc(file);//read the symbol from the file

		if (isalpha(ch))// if current subol(ch) is a letter, the index of this letter will be returned (and pass as true in if statement)
		{
			arr[count][inner_count++] = ch;//this put a read from the file symbol into the string
		}
		else //anything else from letter will be considered NULL and thus want pass the if statement
		{
			if (inner_count == 0)// this is to wave of all the streaks of punctuation sy,bols and only store words
			{
				continue;
			}
			arr[count][inner_count] = '\0';
			count++;//increase the count for words
			inner_count = 0;//start input srtreak from scratch
			arr = (char**)realloc(arr, sizeof(char*) * (count + 1));//allocate memory for one more word
			arr[count] = new char[CHAR_MAX];
		}
	}

	arr[count][0] = EOF;

	return arr;
}

