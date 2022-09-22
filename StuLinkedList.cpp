/*********************************************************
*  file name: StuLinkedList.cpp
*  programmer name: Jack Kwok
*  date created:4/16/2020
*  date of last revision:4/16/2020
*  details of the revision: None
*  short description: funtions for linked list structure of students
**********************************************************/

#include "StuLinkedList.h"
#include <cassert>

size_t list_length(const Stu* head_ptr)
{
	assert(head_ptr != NULL);
	const Stu* cursor = head_ptr;
	size_t answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link)
	{
		answer++;
	}
	return answer;
}
void list_head_insert(Stu*& head_ptr, const Student& entry)
{
	Stu* temp;
	temp = new Stu;
	temp->data = entry;
	temp->link = head_ptr;
	head_ptr = temp;
}
void list_insert(Stu* previous_ptr, Student& entry)
{
	Stu* temp = new Stu;
	temp->data = entry;
	temp->link = previous_ptr->link;
	previous_ptr->link = temp;
}
Stu* list_search(Stu* head_ptr, const string& targetName)
{
	assert(head_ptr != NULL);
	Stu* cursor = NULL;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link)
	{
		//looks by the student's last name
		if (cursor->data.getLastName() == targetName)
		{
			return cursor;
		}

	}
	return cursor;
}
const Stu* list_search(const Stu* head_ptr, const string& targetName){
	assert(head_ptr != NULL);
	const Stu* cursor = NULL;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link)
	{
		//looks by the student's last name
		if (cursor->data.getLastName() == targetName)
		{
			return cursor;
		}

	}
	return cursor;
}
Stu* list_locate(Stu* head_ptr, std::size_t position)
{
	if (head_ptr == NULL || position <= 0)
		return NULL;

	Stu* cursor = head_ptr;
	for (size_t i = 1; i < position && cursor != NULL; i++)
	{
		cursor = cursor->link;

	}
	return cursor;
}
const Stu* list_locate(const Stu* head_ptr, std::size_t position)
{
	if (head_ptr == NULL || position <= 0)
		return NULL;

	const Stu* cursor = head_ptr;
	for (size_t i = 1; i < position && cursor != NULL; i++)
	{
		cursor = cursor->link;

	}
	return cursor;
}
void list_head_remove(Stu*& head_ptr) {
	Stu* newList = head_ptr->link;
	delete head_ptr;
	head_ptr = newList;
	//Stu* remove = head_ptr;
	//head_ptr = head_ptr->link;
	//delete remove;
}
void list_remove(Stu* head_ptr, const string& entry) {
	assert(head_ptr != NULL);
	Stu* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link) {
		if (cursor->link->data.getLastName() == entry) {
			Stu* temp;
			temp = cursor->link;
			cursor->link = temp->link;
			delete temp;
		}
		cursor = cursor->link;
	}
}
void list_copy(const Stu* source_ptr, Stu*& head_ptr, Stu*& tail_ptr)

{
	head_ptr = tail_ptr = NULL;
	if (source_ptr == NULL)
		return;

	head_ptr = new Stu;

	head_ptr->data = source_ptr->data;
	tail_ptr = head_ptr;
	for (source_ptr = source_ptr->link, source_ptr != NULL; source_ptr = source_ptr->link;)
	{
		tail_ptr->link = new Stu;
		tail_ptr->link->data = source_ptr->data;
		tail_ptr = tail_ptr->link;
	}
}
void list_clear(Stu*& head_ptr)
{
	while (head_ptr != NULL)
	{
		list_head_remove(head_ptr);
	}
}
void list_sort(Stu*& head_ptr, int sortSel) {
	Stu* cursor = head_ptr;
	int count = 0;
	while (cursor != NULL) {
		count++;
		cursor = cursor->link;
	}
	if (sortSel == 1) {
		for (int i = count; i > 1; i--) {
			Stu* temp = NULL, * swap1;
			swap1 = head_ptr;
			for (int j = 0; j < count - 1; j++) {
				if (swap1->data.getLastName() > swap1->link->data.getLastName()) {
					Stu* swap2 = swap1->link;
					swap1->link = swap2->link;
					swap2->link = swap1;
					if (swap1 == head_ptr) {
						head_ptr = swap2;
						swap1 = swap2;
					}
					else {
						swap1 = swap2;
						temp->link = swap2;
					}
				}
				temp = swap1;
				swap1 = swap1->link;
			}
		}
	}
	if (sortSel == 2) {
		for (int i = count; i > 1; i--) {
			Stu* temp = NULL, * swap1;
			swap1 = head_ptr;
			for (int j = 0; j < count - 1; j++) {
				if (swap1->data.getStuID() > swap1->link->data.getStuID()) {
					Stu* swap2 = swap1->link;
					swap1->link = swap2->link;
					swap2->link = swap1;
					if (swap1 == head_ptr) {
						head_ptr = swap2;
						swap1 = swap2;
					}
					else {
						swap1 = swap2;
						temp->link = swap2;
					}
				}
				temp = swap1;
				swap1 = swap1->link;
			}
		}
	}
	if (sortSel == 3) {
		for (int i = count; i > 1; i--) {
			Stu* temp = NULL, * swap1;
			swap1 = head_ptr;
			for (int j = 0; j < count - 1; j++) {
				if (swap1->data.getIntendedMajor() > swap1->link->data.getIntendedMajor()) {
					Stu* swap2 = swap1->link;
					swap1->link = swap2->link;
					swap2->link = swap1;
					if (swap1 == head_ptr) {
						head_ptr = swap2;
						swap1 = swap2;
					}
					else {
						swap1 = swap2;
						temp->link = swap2;
					}
				}
				temp = swap1;
				swap1 = swap1->link;
			}
		}
	}
	if (sortSel == 4) {
		for (int i = count; i > 1; i--) {
			Stu* temp = NULL, * swap1;
			swap1 = head_ptr;
			for (int j = 0; j < count - 1; j++) {
				if (swap1->data.getStatus() > swap1->link->data.getStatus()) {
					Stu* swap2 = swap1->link;
					swap1->link = swap2->link;
					swap2->link = swap1;
					if (swap1 == head_ptr) {
						head_ptr = swap2;
						swap1 = swap2;
					}
					else {
						swap1 = swap2;
						temp->link = swap2;
					}
				}
				temp = swap1;
				swap1 = swap1->link;
			}
		}
	}
}