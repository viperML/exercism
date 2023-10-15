#include "grade_school.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void init_roster(roster_t *roster) {
  roster->count = 0;
  return;
}

int cmp_roster(const void *p1, const void *p2) {
  student_t *s1 = (student_t *)p1;
  student_t *s2 = (student_t *)p2;

  if (s1->grade > s2->grade) {
    return 1;
  } else if (s1->grade < s2->grade) {
    return -1;
  } else {
    return strcmp(s1->name, s2->name);
  }
}

bool add_student(roster_t *roster, char *name, int grade) {
  for (size_t i = 0; i < roster->count; i++) {
    char *name_cmp = roster->students[i].name;
    int res = strcmp(name, name_cmp);
    if (res == 0) {
      return false;
    }
  }

  student_t student;

  student.grade = grade;
  if (!strcpy(student.name, name)) {
    return false;
  }

  roster->students[roster->count] = student;

  roster->count++;

  qsort(roster->students, roster->count, sizeof(student_t), cmp_roster);

  return true;
}

roster_t get_grade(roster_t *roster, int desired_grade) {
  roster_t result;
  init_roster(&result);

  for (size_t i = 0; i < roster->count; i++) {
    student_t *s = &roster->students[i];

    if (s->grade == desired_grade) {
      add_student(&result, s->name, s->grade);
    }
  }

  return result;
}
