#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv){
  
  char input[100];
  char *tok;
  int y = 0;
  int std = 0;
  int crs = 0;

  struct course_t course[100];
  struct student_t student[100];
  enum grade_t GRADE;

  while(y == 0){
    
    input[0] = '\0';
        int k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            input[k] = i;
            input[++k] = '\0';
        }
    tok = strtok(input, "#");
    if(strcmp(tok, "create-student") == 0){
      char *tokstd1 = strtok(NULL, "#");
      char *tokstd2 = strtok(NULL, "#");
      char *tokstd3 = strtok(NULL, "#");
      char *tokstd4 = strtok(NULL, "#");
      strcpy(student[std].id, tokstd1);
      strcpy(student[std].name, tokstd2);
      strcpy(student[std].year, tokstd3);
      strcpy(student[std].study_program, tokstd4);

      create_student(tokstd1, tokstd2, tokstd3, tokstd4);

      std++;
    } else if(strcmp(tok, "print-students") == 0){
        print_students(student, std);
    } else if(strcmp(tok, "create-course") == 0){
      char *tokcrs1 = strtok(NULL, "#");
      char *tokcrs2 = strtok(NULL, "#");
      char *tokcrs3 = strtok(NULL, "#");
      char *tokcrs4 = strtok(NULL, "#");
      strcpy(course[crs].code, tokcrs1);
      strcpy(course[crs].name, tokcrs2);
      course[crs].credit = atoi(tokcrs3);
      unsigned short credit = atoi(tokcrs3);
      if(strcmp(tokcrs4, "A") == 0){
        course[crs].passing_grade = 8;
        // strcpy(course[crs].passing_grade, "GRADE_A");
        create_course(tokcrs1, tokcrs2, credit, GRADE_A);
      } else if(strcmp(tokcrs4, "AB") == 0){
        course[crs].passing_grade = 7;
        // strcpy(course[crs].passing_grade, "GRADE_AB");
        create_course(tokcrs1, tokcrs2, credit, GRADE_AB);
      }else if(strcmp(tokcrs4, "B") == 0){
        course[crs].passing_grade = 6;
        // strcpy(course[crs].passing_grade, "GRADE_B");
        create_course(tokcrs1, tokcrs2, credit, GRADE_B);
      } else if(strcmp(tokcrs4, "BC") == 0){
        course[crs].passing_grade = 5;
        // strcpy(course[crs].passing_grade, "GRADE_BC");
        create_course(tokcrs1, tokcrs2, credit, GRADE_BC);
      } else if(strcmp(tokcrs4, "C") == 0){
        course[crs].passing_grade = 4;
        // strcpy(course[crs].passing_grade, "GRADE_C");
        create_course(tokcrs1, tokcrs2, credit, GRADE_C);
      } else if(strcmp(tokcrs4, "D") == 0){
        course[crs].passing_grade = 3;
        // strcpy(course[crs].passing_grade, "GRADE_D");
        create_course(tokcrs1, tokcrs2, credit, GRADE_D);
      } else if(strcmp(tokcrs4, "E") == 0){
        course[crs].passing_grade = 2;
        // strcpy(course[crs].passing_grade, "GRADE_E");
        create_course(tokcrs1, tokcrs2, credit, GRADE_E);
      } else if(strcmp(tokcrs4, "NONE") == 0){
        course[crs].passing_grade = 0;
        // strcpy(course[crs].passing_grade, "GRADE_NONE");
        create_course(tokcrs1, tokcrs2, credit, GRADE_NONE);
      } else if(strcmp(tokcrs4, "T") == 0){
        course[crs].passing_grade = 1;
        // strcpy(course[crs].passing_grade, "GRADE_T");
        create_course(tokcrs1, tokcrs2, credit, GRADE_T);
      }
      //create_course(tokcrs1, tokcrs2, credit, tokcrs4);
      crs++;
    } else if(strcmp(tok, "print-courses") == 0){
      print_courses(course , crs);
    } else if(strcmp(tok, "find-student-by-id") == 0){
      char *tokFS = strtok(NULL, "#");
      find_student_by_id(student, std, tokFS);
    } else if(strcmp(tok, "---") == 0){
      y = y + 1;
    } else if(strcmp(tok, "find-course-by-code") == 0){
      char *tokCRS = strtok(NULL, "#");
      find_course_by_code(course, crs, tokCRS);
  }
  }
  return 0;
  } 