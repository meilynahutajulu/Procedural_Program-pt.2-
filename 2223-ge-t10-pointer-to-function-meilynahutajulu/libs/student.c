#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

// void assign_t assignment(struct student_t _student, 
//                          struct dorm_t *_dorm, int std_idx)

//     for(int i = 0; i < std_idx, i++){
//         if(strcmp(_student))
//     }

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
  if(_students[i].gender == 0){
  printf("%s|%s|%s|male|unassigned\n", _students[i].id, _students[i].name, _students[i].year);
  } 
  if(_students[i].gender == 1){
  printf("%s|%s|%s|female|unassigned\n", _students[i].id, _students[i].name, _students[i].year);
  }
    } else {
  if(_students[i].gender == 0){
  printf("%s|%s|%s|male|%s\n", _students[i].id, _students[i].name, _students[i].year, _students[i].dorm->name);
  } 
  if(_students[i].gender == 1){
  printf("%s|%s|%s|female|%s\n", _students[i].id, _students[i].name, _students[i].year, _students[i].dorm->name);
  }
    }
    }

}
   void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)
   {
        if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *_Dorm2, char *_id, char *_dn)
{
    if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num = _dorm->residents_num + 1;
            _Dorm2->residents_num = _Dorm2->residents_num - 1;
        }
    } 
}