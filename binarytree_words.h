#pragma once
struct Word
{
	char word[CHAR_MAX];
	int count_of_similair_items;
	int count_of_all_words;
	Word* right;
	Word* left;

	Word();
	//~Word();

	void delete_all_the_words(Word* root);

	Word* somewhere_to_put_it(Word* word_list_root, char word_to_add[]);

	void AddItem(Word* ptr_to_root, char word_to_add[]);

	void display_the_word(Word* root);

	Word* find_the_word(Word* root, char word[]);
};