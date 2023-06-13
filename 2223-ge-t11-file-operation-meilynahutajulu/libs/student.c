#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

void print_students(struct student_t *_students,
                    unsigned short int _student_size)
{   
    
    
    for(int i = 0; i < _student_size; i++){
  if(_students[i].gender == 0){
  printf("%s|%s|%s|male\n", _students[i].id, _students[i].name, _students[i].year);
  } 
  if(_students[i].gender == 1){
  printf("%s|%s|%s|female\n", _students[i].id, _students[i].name, _students[i].year);
  }
    }
}

void print_student_detail(struct student_t *_students,
                    unsigned short int _student_size)
{   

    for(int i = 0; i < _student_size; i++){
      if(_students[i].dorm == NULL){
  if(_students[i].gender != 1){
  printf("%s|%s|%s|male|unassigned\n", _students[i].id, _students[i].name, _students[i].year);
  } else{
  printf("%s|%s|%s|female|unassigned\n", _students[i].id, _students[i].name, _students[i].year);
  } 
  }  
  else {
  if(_students[i].gender != 1){
  printf("%s|%s|%s|male|%s\n", _students[i].id, _students[i].name, _students[i].year, _students[i].dorm->name);
  } else  if(_students[i].gender == 1){
  printf("%s|%s|%s|female|%s\n", _students[i].id, _students[i].name, _students[i].year, _students[i].dorm->name);
  }
    }
      }
}

void assign_student(struct student_t *_student, struct dorm_t *_dorm, int ids, int idd)
   {
        if (_dorm[idd].residents_num <  _dorm[idd].capacity){
        if (_student[ids].gender == _dorm[idd].gender){
            _student[ids].dorm = &_dorm[idd];
            _dorm[idd].residents_num++;
        }
    }
} 

int std_index_finder (char *_student, int idx_s, struct student_t *_std){
   for (short i = 0; i < idx_s; i++)
            {
                if (strcmp(_std[i].id, _student) == 0)
                {
                    idx_s = i;
                }
 }
 return idx_s;
}

int dorm_index_finder (char *_dorm, int idx_d, struct dorm_t *dorm){
   for (short i = 0; i < idx_d; i++)
            {
                if (strcmp(dorm[i].name, _dorm) == 0)
                {
                    idx_d = i;
                }
 }
 return idx_d;
}