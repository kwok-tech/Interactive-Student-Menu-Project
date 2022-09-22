#include "course.h"
#include <cstdlib>
#include <string>
using namespace team3Belashov;

	struct CourseNode {
		Course data;
		CourseNode* link;
	};
	
	size_t list_length(const CourseNode* head_ptr);
	void list_head_insert(CourseNode*& head_ptr, const Course& entry);
	void list_insert(CourseNode* previous_ptr, Course& entry);
	CourseNode* list_search(CourseNode* head_ptr, const string& targetName);
	const CourseNode* list_search(const CourseNode* head_ptr, const string& targetName);
	CourseNode* list_locate(CourseNode* head_ptr, std::size_t position);
	const CourseNode* list_locate(const CourseNode* head_ptr, std::size_t position);
	void list_head_remove(CourseNode*& head_ptr);
	void list_remove(CourseNode* head_ptr, const string& entry);
	void list_clear(CourseNode*& head_ptr);
	void list_copy(const CourseNode* source_ptr, CourseNode*& head_ptr, CourseNode*& tail_ptr);


