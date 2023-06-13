// 12S22031 - Ioka Purba
// 12S22039 - Meilyna Hutajulu

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int _argc, char **_argv) {
  
  char input[100];
  char *tok;
  int y = 0;
  int std = 0;  
  int dx = 0;
  int idx_s, idx_d = 0;

//   struct dorm_t dorm[100];
   struct student_t *student = (struct student_t *) malloc(100 * sizeof(struct student_t));
   struct dorm_t *dorm = (struct dorm_t *) malloc(100 * sizeof(struct dorm_t));

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
    if(strcmp(tok, "dorm-add") == 0){
        char *dorm1 = strtok(NULL, "#");
        char *dorm2 = strtok(NULL, "#");
        char *dorm3 = strtok(NULL, "#");
        strcpy(dorm[dx].name, dorm1);
        dorm[dx].capacity = atoi(dorm2);
        if(strcmp(dorm3, "male") == 0){
        dorm[dx].gender = 0;
      } else if(strcmp(dorm3, "female") == 0){
        dorm[dx].gender = 1;
      }
        dx++;
    }
    
    if (strcmp(tok, "assign-student") == 0)
        {
            char *id = strtok(NULL, "#");
            char *id_dorm = strtok(NULL, "#");
            for (short i = 0; i < dx; i++)
            {
                if (strcmp(student[i].id, id) == 0)
                {
                    idx_s = i;
                }
                
            }
            for (short i = 0; i < std; i++)
            {
                if (strcmp(dorm[i].name, id_dorm) == 0)
                {
                    idx_d = i;
                }
            }
            
            assign_student(&student[idx_s], &dorm[idx_d], id, id_dorm);
        }



    if(strcmp(tok, "student-add") == 0){
      char *tokstd1 = strtok(NULL, "#");
      char *tokstd2 = strtok(NULL, "#");
      char *tokstd3 = strtok(NULL, "#");
      char *tokstd4 = strtok(NULL, "#");
      strcpy(student[std].id, tokstd1);
      strcpy(student[std].name, tokstd2);
      strcpy(student[std].year, tokstd3);
      if(strcmp(tokstd4, "male") == 0){
        student[std].gender = 0;
      } else if(strcmp(tokstd4, "female") == 0){
        student[std].gender = 1;
      }
     
 
      std++;
    } else if(strcmp(tok, "student-print-all") == 0){
        print_students(student, std);
    } else if(strcmp(tok, "student-print-all-detail") == 0){
        print_student_detail(student, std);
    } else if(strcmp(tok, "---") == 0){
      y = y + 1; 
    } else if(strcmp(tok, "dorm-print-all") == 0){
        print_dorm(dorm, dx);
    
    } else if(strcmp(tok, "dorm-print-all-detail") == 0){
        print_dorm_detail(dorm, dx);
    }
     
  }
  
  free(student);
  free(dorm);

  return 0; 
}