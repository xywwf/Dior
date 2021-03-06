#include "dior.h"

/**
   Yixin Luo
   2016/5/1
   垃圾回收部分
**/
/**
   回收atom
**/
/*
void free_atom(atom *exp) {
  if (exp == NULL)
    return;
  if (IS(BOOLEAN, exp)) {
    free(exp);
  } else if (IS(NUMBER, exp)) {
    free(exp);
  } else if (IS(STRING, exp)) {
    free(GET_VALUE(STRING, exp));
    free(exp);
  } else if (IS(CHARACTER, exp)) {
    free(exp);
  } else if (IS(PAIR, exp)) {
    free(CAR(exp));
    free(CDR(exp));
    free(exp);
  } else if (IS(SYMBOL, exp)) {
    free(GET_VALUE(SYMBOL, exp));
    free(exp);
  } else if (IS(FUNCTION, exp)) {
    free(DATA(exp).FUNCTION.params);
    free(DATA(exp).FUNCTION.body);
    free(exp);
  }
}
*/

void Mark(atom *exp) {
  if (exp == NULL)
    return;
  exp->gc_flag = 1;
  Mark(CAR(exp));
  Mark(CDR(exp));
}

void Sweep(atom *exp) {
  if (exp == NULL)
    return;
  Sweep(CAR(exp));
  Sweep(CDR(exp));
  if (exp->gc_flag == 1) {
    exp->gc_flag = 0;
  } else {
    free(exp);
  }
}
