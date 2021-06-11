#ifndef PETS_FUNCT
#define PETS_FUNCT
#define _CRT_SECURE_NO_WARNINGS

#include "petsh.h"

Nickname::Nickname() :left{ nullptr }, right{ nullptr }, count_of_similair_nicknames(0)
{

}

void Nickname::locate_nickname(Nickname* root, char pet_name[])
{
	Nickname* this_kind = root;

	int left_right_index = 0;

	if (strcmp(pet_name, this_kind->nickname) > 0)
	{
		left_right_index = 1;

		if (this_kind->right != nullptr)
		{
			left_right_index = 0;
			locate_nickname(this_kind->right, pet_name);
			
		}
	}
	else if (strcmp(pet_name, this_kind->nickname) < 0)
	{
		left_right_index = 2;
		if (this_kind->left != nullptr)
		{
			left_right_index = 0;
			locate_nickname(this_kind->left, pet_name);
			
		}
	}
	else if (strcmp(pet_name, this_kind->nickname) == 0)
	{
		this_kind->count_of_similair_nicknames++;
	}


	if (left_right_index == 1)
	{
		this_kind->right = new Nickname;
		strcpy(this_kind->right->nickname, pet_name);
		this_kind->right->right = nullptr;
		this_kind->right->left = nullptr;
		this_kind->right->count_of_similair_nicknames = 1;
	}
	else if (left_right_index == 2)
	{
		this_kind->left = new Nickname;
		strcpy(this_kind->left->nickname, pet_name);
		this_kind->left->right = nullptr;
		this_kind->left->left = nullptr;
		this_kind->left->count_of_similair_nicknames = 1;
	}
}

void Nickname::AddItem(Nickname* this_kind, char pet_name[])
{
	if (this_kind->nickname[0] == '\0')
	{
		strcpy(this_kind->nickname, pet_name);
	}
	else
	{
		locate_nickname(this_kind, pet_name);
	}
}

void Nickname::DisplayNickname(Nickname* const root)
{
	Nickname* copy = root;

	if (copy->left != nullptr)
	{
		DisplayNickname(copy->left);
	}

	std::cout << "\n Petname " << copy->nickname << " times " << copy->count_of_similair_nicknames << std::endl;

	if (copy->right != nullptr)
	{
		DisplayNickname(copy->right);
	}

	

}

bool Nickname::Look_for_Nickname(const Nickname* const root, char pet_name[])
{
	bool flag = false;

	if (root->left != nullptr)
	{
		if (Look_for_Nickname(root->left, pet_name) == true)
		{
			flag = true;
		}
	}

	if (root->right != nullptr)
	{
		if(Look_for_Nickname(root->right, pet_name))
		{
			flag = true;
		}
	}
	
	if (strcmp(root->nickname, pet_name) == NULL)
	{
		flag = true;
		std::cout << root->nickname << " ";
	}

	return flag;
}




Pets_Kind::Pets_Kind() : left_kind { nullptr }, right_kind{ nullptr }
{

}

void Pets_Kind::locate_place(Pets_Kind* root, char pet_kind[], char pet_name[])
{
	Pets_Kind* copy = root;
	//copy->nicknames_of_this_kind = new Nickname;
	int count = 0;

	if (strcmp(pet_kind, copy->kind_name) == NULL)
	{
		copy->nicknames_of_this_kind->AddItem(copy->nicknames_of_this_kind, pet_name);
	}
	else if (strcmp(pet_kind, copy->kind_name) > 0)
	{
		count = 1;
		if (copy->right_kind != NULL)
		{
			locate_place(copy->right_kind, pet_kind, pet_name);
			count = 0;
		}
	}
	else if (strcmp(pet_kind, copy->kind_name) < 0)
	{
		count = 2;
		if (copy->left_kind != NULL)
		{
			locate_place(copy->left_kind, pet_kind, pet_name);
			count = 0;
		}
	}


	if (count == 1)
	{
		copy->right_kind = new Pets_Kind;
		strcpy(copy->right_kind->kind_name, pet_kind);
		copy->right_kind->nicknames_of_this_kind = new Nickname;
		copy->right_kind->nicknames_of_this_kind->AddItem(copy->right_kind->nicknames_of_this_kind, pet_name);
		copy->right_kind->right_kind = nullptr;
		copy->right_kind->left_kind = nullptr;

	}
	else if (count == 2)
	{
		copy->left_kind = new Pets_Kind;
		strcpy(copy->left_kind->kind_name, pet_kind);
		copy->left_kind->nicknames_of_this_kind = new Nickname;
		copy->left_kind->nicknames_of_this_kind->AddItem(copy->left_kind->nicknames_of_this_kind, pet_name);
		copy->left_kind->right_kind = nullptr;
		copy->left_kind->left_kind = nullptr;
	}

}


void Pets_Kind::AddPet(Pets_Kind* root, char pet_kind[], char pet_name[])
{
	if (kind_name[0] == '\0')
	{
		strcpy(root->kind_name, pet_kind);
		root->nicknames_of_this_kind = new Nickname;
		root->nicknames_of_this_kind->AddItem(nicknames_of_this_kind, pet_name);
	}
	else
	{
		locate_place(root, pet_kind, pet_name);
	}
}


void Pets_Kind::DisplayPet(Pets_Kind* const root)
{
	Pets_Kind* copy = root;

	if (copy->left_kind != nullptr)
	{
		DisplayPet(copy->left_kind);
	}

	std::cout << "\n\n\nKind " << copy->kind_name << std::endl;
	copy->nicknames_of_this_kind->DisplayNickname(copy->nicknames_of_this_kind);

	if (copy->right_kind != nullptr)
	{
		DisplayPet(copy->right_kind);
	}
}


void Pets_Kind::DisplaySameNicknames(Pets_Kind* const root, char pet_name[])
{
	Pets_Kind* copy = root;

	if (copy->left_kind != nullptr)
	{
		DisplaySameNicknames(copy->left_kind, pet_name);
	}


	if (copy->nicknames_of_this_kind->Look_for_Nickname(copy->nicknames_of_this_kind, pet_name))
	{
		std::cout << copy->kind_name << "\n";
	}


	if (copy->right_kind != nullptr)
	{
		DisplaySameNicknames(copy->right_kind, pet_name);
	}
}

#endif 