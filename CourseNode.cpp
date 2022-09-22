#include "course.h"
#include "CourseNode.h"
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;
using namespace team3Belashov;

size_t list_length(const CourseNode* head_ptr){
	assert(head_ptr != NULL);
	const CourseNode* cursor = head_ptr;
	size_t answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link){
		answer++;
	}
	return answer;
}
void list_head_insert(CourseNode*& head_ptr, const Course& entry){
	CourseNode* temp;
	temp = new CourseNode;
	temp->data = entry;
	temp->link = head_ptr;
	head_ptr = temp;
}
void list_insert(CourseNode* previous_ptr, Course& entry){
	CourseNode* temp = new CourseNode;
	temp->data = entry;
	temp->link = previous_ptr->link;
	previous_ptr->link = temp;
}
CourseNode* list_search(CourseNode* head_ptr, const string& targetName){
	assert(head_ptr != NULL);
	CourseNode* cursor = head_ptr;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link){
		//looks by the Course's Course Number
		if (cursor->data.getCourseNumber() == targetName){
			return cursor;
		}
	}
	return cursor;
}
const CourseNode* list_search(const CourseNode* head_ptr, const string& targetName) {
	assert(head_ptr != NULL);
	const CourseNode* cursor = head_ptr;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link){
		//looks by the Course's last name
		if (cursor->data.getCourseNumber() == targetName){
			return cursor;
		}
	}
	return cursor;
}
CourseNode* list_locate(CourseNode* head_ptr, std::size_t position){
	if (head_ptr == NULL || position <= 0)
		return NULL;
	CourseNode* cursor = head_ptr;
	for (int i = 1; i < position && cursor != NULL; i++){
		cursor = cursor->link;
	}
	return cursor;
}
const CourseNode* list_locate(const CourseNode* head_ptr, std::size_t position){
	if (head_ptr == NULL || position <= 0)
		return NULL;
	const CourseNode* cursor = head_ptr;
	for (int i = 1; i < position && cursor != NULL; i++){
		cursor = cursor->link;
	}
	return cursor;
}
void list_head_remove(CourseNode*& head_ptr) {
	CourseNode* remove = head_ptr;
	head_ptr = head_ptr->link;
	delete remove;
}
void list_remove(CourseNode* head_ptr, const string& entry) {
	assert(head_ptr != NULL);
	CourseNode* cursor;
	//search by course number
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link) {
		if (cursor->link->data.getCourseNumber() == entry) {
			CourseNode* temp;
			temp = cursor->link;
			cursor->link = temp->link;
			delete temp;
		}
		cursor = cursor->link;
	}
}
void list_copy(const CourseNode* source_ptr, CourseNode*& head_ptr, CourseNode*& tail_ptr){
	head_ptr = tail_ptr = NULL;
	if (source_ptr == NULL)
		return;
	head_ptr = new CourseNode;
	head_ptr->data = source_ptr->data;
	tail_ptr = head_ptr;
	for (source_ptr = source_ptr->link, source_ptr != NULL; source_ptr = source_ptr->link;){
		tail_ptr->link = new CourseNode;
		tail_ptr->link->data = source_ptr->data;
		tail_ptr = tail_ptr->link;
	}
}
void list_clear(CourseNode*& head_ptr){
	while (head_ptr != NULL)
	{
		list_head_remove(head_ptr);
	}
}