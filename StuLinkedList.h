/*********************************************************
*  file name: StuLinkedList.h
*  programmer name: Jack Kwok
*  date created:4/16/2020
*  date of last revision:4/16/2020
*  details of the revision: None
*  short description: linked list structure for students
**********************************************************/

// The Node definition as a structure: 
#include <cstdlib>
#include <iostream>
#include "Student.h"
using namespace std;
using namespace team3Kwok;

//struct of the linked list
struct Stu
{
	Student data;
	Stu* link;
};

// FUNCTIONS for the linked list toolkit - prototypes 
size_t list_length(const Stu* head_ptr);
void list_head_insert(Stu*& head_ptr, const Student& entry);
void list_insert(Stu* previous_ptr, Student& entry);
Stu* list_search(Stu* head_ptr, const string& targetName);
const Stu* list_search(const Stu* head_ptr, const string& targetName);
Stu* list_locate(Stu* head_ptr, std::size_t position);
const Stu* list_locate(const Stu* head_ptr, std::size_t position);
void list_head_remove(Stu*& head_ptr);
void list_remove(Stu* head_ptr, const string& entry);
void list_clear(Stu*& head_ptr);
void list_copy(const Stu* source_ptr, Stu*& head_ptr, Stu*& tail_ptr);
void list_sort(Stu*& head_ptr, int sortSel);
