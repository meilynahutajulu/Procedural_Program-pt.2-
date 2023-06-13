#include "academic.h"
#include <stdio.h>
#include <string.h>

int main(int _argc, char **_argv) {
  
  char input[100];
  char *tok; 
  int y = 0;
  int std = 0;
  int crs = 0; 

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
    }
    if(strcmp(tok, "print-students") == 0){
        print_students(student, std);
    }
    if(strcmp(tok, "find-student-by-id") == 0){
      char *tokFS = strtok(NULL, "#");
      find_student_by_id(student, std, tokFS);
    }
    if(strcmp(tok, "---") == 0){
      y = y + 1;
    }
  }
  return 0;
}    