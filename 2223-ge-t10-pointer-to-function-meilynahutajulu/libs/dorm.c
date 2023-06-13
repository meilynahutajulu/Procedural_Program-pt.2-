#include "dorm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_dorm(struct dorm_t *_dorm,
                    unsigned short int _dorm_size){
    
    for(int i = 0; i < _dorm_size; i++){
       if(_dorm[i].gender == 0){
        
  printf("%s|%d|male\n", _dorm[i].name, _dorm[i].capacity);
        }  
       if(_dorm[i].gender == 1){
   
  printf("%s|%d|female\n", _dorm[i].name, _dorm[i].capacity);
        } 
    }
}
  

  void print_dorm_detail(struct dorm_t *_dorm,
                    unsigned short int _dorm_size){
    
    for(int i = 0; i < _dorm_size; i++){
       if(_dorm[i].gender == 0){ 
        if( _dorm[i].residents_num == '\0'){
  printf("%s|%d|male|0\n", _dorm[i].name, _dorm[i].capacity);
        } else {
 printf("%s|%d|male|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }
       }  
       if(_dorm[i].gender == 1){
        if( _dorm[i].residents_num == '\0'){
  printf("%s|%d|female|0\n", _dorm[i].name, _dorm[i].capacity);
        } else {
 printf("%s|%d|female|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }
       } 
    }
  }