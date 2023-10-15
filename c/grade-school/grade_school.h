#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

int cmp_roster(const void *p1, const void *p2);

void init_roster(roster_t* roster);
bool add_student(roster_t* roster, char* name, int grade);
roster_t get_grade(roster_t* roster, int desired_grade);


#endif
