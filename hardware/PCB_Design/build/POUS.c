void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_0,data__->BOTON_ARRANQUE,retain)
  __INIT_LOCATED_VALUE(data__->BOTON_ARRANQUE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1,data__->BOTON_PARADA,retain)
  __INIT_LOCATED_VALUE(data__->BOTON_PARADA,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->MOTOR1,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_5,data__->MOTOR2,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_6,data__->MOTOR3,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_7,data__->MOTOR4,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->MOTOR5,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR5,__BOOL_LITERAL(FALSE))
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP1,retain);
  TP_init__(&data__->TP2,retain);
  TP_init__(&data__->TP3,retain);
  TP_init__(&data__->TP4,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TP0.,IN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
  TP_body__(&data__->TP0);
  if (__GET_VAR(data__->TP0.Q,)) {
    __SET_LOCATED(data__->,MOTOR1,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TP1.,IN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 0, 12, 0, 0, 0));
  TP_body__(&data__->TP1);
  if (__GET_VAR(data__->TP1.Q,)) {
    __SET_LOCATED(data__->,MOTOR2,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TP2.,IN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 0, 14, 0, 0, 0));
  TP_body__(&data__->TP2);
  if (__GET_VAR(data__->TP2.Q,)) {
    __SET_LOCATED(data__->,MOTOR3,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TP3.,IN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TP3.,PT,,__time_to_timespec(1, 0, 16, 0, 0, 0));
  TP_body__(&data__->TP3);
  if (__GET_VAR(data__->TP3.Q,)) {
    __SET_LOCATED(data__->,MOTOR4,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TP4.,IN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TP4.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
  TP_body__(&data__->TP4);
  __SET_LOCATED(data__->,MOTOR5,,__GET_VAR(data__->TP4.Q,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





