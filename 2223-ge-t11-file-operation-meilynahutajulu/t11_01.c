// 12S22031 - Ioka Purba
// 12S22039 - Meilyna Hutajulu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main() {
  char input[100];
  int y = 0;
  int std = 0;  
  int dx = 0; 
  char dorm_inf[100];
  char std_fil[100];  
//   struct dorm_t dorm[100];
   struct student_t *student = (struct student_t *) malloc(100 * sizeof(struct student_t));
   struct dorm_t *dorm = (struct dorm_t *) malloc(100 * sizeof(struct dorm_t));
  
    FILE *dorm_file;
    dorm_file = fopen("storage/dorm-repository.txt", "r");
    FILE *student_file;
    student_file = fopen("storage/student-repository.txt", "r");
if(dorm_file == NULL){
    printf("Nothing\n");
}if(dorm_file != NULL){
    while(fgets(dorm_inf, 100, dorm_file)){
char *name_dorm = strtok(dorm_inf, "|");
        strcpy(dorm[dx].name, name_dorm);
    char *capacity = strtok(NULL, "|");
        dorm[dx].capacity = atoi(capacity);
    char *dorm3 = strtok(NULL, "|");
    if(strcmp(dorm3, "female") == 0){
        dorm[dx].gender = 1;
    }else if(strcmp(dorm3, "male") == 0){
        dorm[dx].gender = 0; 
    }
    dx++;
    
} 
if(student_file != NULL){
    while(fgets(std_fil, 100, student_file)){
      char *tokstd1 = strtok(std_fil, "|");
      char *tokstd2 = strtok(NULL, "|");
      char *tokstd3 = strtok(NULL, "|");
      char *tokstd4 = strtok(NULL, "|");
      strcpy(student[std].id, tokstd1);
      strcpy(student[std].name, tokstd2);
      strcpy(student[std].year, tokstd3);
      if(strcmp(tokstd4, "male\n") == 0){
        student[std].gender = 0;
      } else if(strcmp(tokstd4, "female\n") == 0){
        student[std].gender = 1;
      }
      std++;   
      
}
}    
fclose(dorm_file);
fclose(student_file);
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

if(strcmp(input, "dorm-print-all-detail") == 0){
    print_dorm_detail(dorm, dx);
}
if(strcmp(input, "student-print-all-detail") == 0){
      print_student_detail(student, std);
}if(strcmp(input, "---") == 0){
    y = y + 1;
}
} 
}
free(student);
free(dorm);

    return 0;
}
