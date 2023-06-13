// 12S22031 - Ioka Purba
// 12S22039 - Meilyna Hutajulu

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade)
{
     char *txt; 
    if(_grade == GRADE_NONE){
       txt = "None";
    }
    else if(_grade == GRADE_T){
       txt = "T";
    }
    else if(_grade == GRADE_E){ 
       txt = "E";
    }
    else if(_grade == GRADE_D){
       txt = "D"; 
    }  
    else if(_grade == GRADE_C){
       txt = "C";
    } 
    else if(_grade == GRADE_BC){
       txt = "BC";
    }
    else if(_grade == GRADE_B){
       txt = "B";
    }
    else if(_grade == GRADE_AB){
       txt = "AB";
    }
    else if(_grade == GRADE_A){
       txt = "A";
    }
    
    return txt;  
}

float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    float prf;
    if(_grade == 0){
        prf = 0.00;
    }
    if(_grade == 1){
        prf = 0.00;
    }
    if(_grade == 2){
        prf = 0.00;
    }
    if(_grade == 3){
        prf = 1.00;
    }
    if(_grade == 4){
        prf = 2.00;
    }
    if(_grade == 5){
        prf = 2.50;
    }
    if(_grade == 6){
        prf = 3.00;
    }
    if(_grade == 7){
        prf = 3.50;
    }
    if(_grade == 8){
        prf = 4.00;
    }
    prf = prf * _credit;

    return prf;
}

void print_course(struct course_t _course) {
    printf("%s|%s|%hu|", _course.code, _course.name, _course.credit);
    printf("%s\n", grade_to_text(_course.passing_grade));
}

void print_courses(struct course_t *_courses, unsigned short int _course_size)
{
    for(int i = 0; i < _course_size; i++){
        print_course(_courses[i]);
    }
}

void print_student(struct student_t _student)
{
  printf("%s|%s|%s|%s|%.2f\n", _student.id, _student.name, _student.year, _student.study_program, _student.gpa);
}

void print_students(struct student_t *_students,
                    unsigned short int _student_size)
{
    for(int i = 0; i < _student_size; i++){
        print_student(_students[i]);
    }
}

void print_enrollment(struct enrollment_t _enrollment)
{
    printf("%s|%s|", _enrollment.course.code, _enrollment.student.id);
    printf("%s", grade_to_text(_enrollment.grade));
    printf("|%.2f\n", calculate_performance(_enrollment.grade, _enrollment.course.credit));
}

void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size)
{
    for(int i = 0; i < _enrollment_size; i++){
        print_enrollment(_enrollments[i]);
    }
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade)
{
    struct course_t crs;
    strcpy(crs.code, _code);
    strcpy(crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;
    return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program)
{
    struct student_t std;
    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    strcpy(std.study_program, _study_program);
    std.gpa = 0.00;
    return std;
}

struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester)
{
    struct enrollment_t emt;
    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;
    emt.grade = 0.00;
    return emt;
}

void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size)
{
    float total = 0.00;
   float GPA_ = 0.00;
   float kredit = 0;
   for(int a = 0; a < _enrollment_size; a++){
    
      total = total + calculate_performance(_enrollments[a].grade, _enrollments[a].course.credit);
      kredit = kredit + _enrollments[a].course.credit;

     
   }  

   GPA_ = total / kredit;
    _student->gpa = GPA_;
}

void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade)
{
    for(int x = 0; x < _enrollment_size; x++){
        if(strcmp(_enrollments[x].course.code, _course.code) == 0 && strcmp(_enrollments[x].student.id, _student.id) == 0){
        _enrollments[x].grade = _grade;
        }
    }
}

struct student_t find_student_by_id(struct student_t *_students,
                                    unsigned short int _student_size,
                                    char *_id)
{
    struct student_t std;
    for(int i = 0; i < _student_size; i++){
       if(strcmp(_students[i].id, _id) == 0){
        print_student(_students[i]);
       }
    }
    return std;
}
struct course_t find_course_by_code(struct course_t *_courses,
                                    unsigned short int _course_size,
                                    char *_code)
{
    struct course_t crs;
    for(int i = 0; i < _course_size; i++){
        if(strcmp(_courses[i].code, _code) == 0){
          print_course(_courses[i]);
        }
    }
    return crs;
}