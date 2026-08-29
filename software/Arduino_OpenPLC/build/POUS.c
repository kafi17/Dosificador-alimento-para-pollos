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
  __INIT_LOCATED(BOOL,__IX0_4,data__->BOTON_ARRANQUE,retain)
  __INIT_LOCATED_VALUE(data__->BOTON_ARRANQUE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_2,data__->BOTON_PARADA,retain)
  __INIT_LOCATED_VALUE(data__->BOTON_PARADA,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->MOTOR_CINTA,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR_CINTA,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->VALVULA1_IN1,retain)
  __INIT_LOCATED_VALUE(data__->VALVULA1_IN1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->VALVULA1_IN2,retain)
  __INIT_LOCATED_VALUE(data__->VALVULA1_IN2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_6,data__->VALVULA3_IN2,retain)
  __INIT_LOCATED_VALUE(data__->VALVULA3_IN2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0,data__->SENSOR_IR_1,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR_IR_1,__BOOL_LITERAL(FALSE))
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON4,retain);
  TP_init__(&data__->TP0,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  if (!(__GET_LOCATED(data__->BOTON_ARRANQUE,))) {
    __SET_LOCATED(data__->,MOTOR_CINTA,,__BOOL_LITERAL(TRUE));
  };
  if (!(__GET_LOCATED(data__->SENSOR_IR_1,))) {
    __SET_LOCATED(data__->,MOTOR_CINTA,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON0.,IN,,!(__GET_LOCATED(data__->SENSOR_IR_1,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  if (__GET_VAR(data__->TON0.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN1,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON0.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN2,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON2.,IN,,(!(__GET_LOCATED(data__->VALVULA1_IN2,)) && __GET_LOCATED(data__->VALVULA1_IN1,)));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 0.3, 0, 0, 0));
  TON_body__(&data__->TON2);
  if (__GET_VAR(data__->TON2.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON2.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN2,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON4.,IN,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON4);
  if (__GET_VAR(data__->TON4.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN2,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON4.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN1,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON1.,IN,,(__GET_LOCATED(data__->VALVULA1_IN2,) && !(__GET_LOCATED(data__->VALVULA1_IN1,))));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 0.5, 0, 0, 0));
  TON_body__(&data__->TON1);
  if (__GET_VAR(data__->TON1.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN2,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON1.Q,)) {
    __SET_LOCATED(data__->,VALVULA1_IN1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON4.Q,)) {
    __SET_LOCATED(data__->,MOTOR_CINTA,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP0);
  if (__GET_VAR(data__->TP0.Q,)) {
    __SET_LOCATED(data__->,MOTOR_CINTA,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





