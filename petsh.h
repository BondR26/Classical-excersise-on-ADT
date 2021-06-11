#pragma once
#include<iostream>

class Nickname
{
private:

	char nickname[CHAR_MAX];
	//char kind[CHAR_MAX];
	int count_of_similair_nicknames;
	Nickname* left;
	Nickname* right;
public:

	Nickname();

	void locate_nickname(Nickname* root, char pet_name[]);

	void AddItem(Nickname* this_kind, char pet_name[]);

	void DisplayNickname(Nickname* const root);

	bool Look_for_Nickname(const Nickname* const root, char pet_name[]);

};





class Pets_Kind
{
private:

	char kind_name[CHAR_MAX];

	Nickname* nicknames_of_this_kind;//every pet kind has a binary tree of the name in it
	
	Pets_Kind* left_kind;
	Pets_Kind* right_kind;

public:

	Pets_Kind();

	void AddPet(Pets_Kind* root, char pet_kind[], char pet_name[]);
	
	void locate_place(Pets_Kind* root, char pet_name[], char pet_kind[]);

	void DisplayPet(Pets_Kind* const root);

	void DisplaySameNicknames(Pets_Kind* const root, char pet_name[]);

};


