#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"


struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
void print_students(struct student_t *_students,
                    unsigned short int _student_size);
                    void print_student_detail(struct student_t *_students,
                    unsigned short int _student_size); 

void assign_student(struct student_t *_student, struct dorm_t *_dorm, int ids, int idd);

int std_index_finder (char *_student, int idx_s, struct student_t *_std);

int dorm_index_finder (char *_dorm, int idx_d, struct dorm_t *dorm);

#endif