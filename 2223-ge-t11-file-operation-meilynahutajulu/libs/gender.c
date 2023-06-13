#include "gender.h"

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
