#include "gender.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */ 
char *gender_to_text(enum gender_t _gender)
{
     char *txt; 
    if(_gender == GENDER_MALE){
       txt = "male";
    }
    else if(_gender == GENDER_FEMALE){
       txt = "female";
    }
    
    return txt;  
}
