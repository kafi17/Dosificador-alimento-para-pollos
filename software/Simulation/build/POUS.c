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
  __INIT_VAR(data__->BOTON_ARRANQUE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTON_PARADA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTOR1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVULA1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_IR_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_PESO_1,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  if (__GET_VAR(data__->BOTON_ARRANQUE,)) {
    __SET_VAR(data__->,MOTOR1,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->BOTON_PARADA,)) {
    __SET_VAR(data__->,MOTOR1,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON1.,IN,,((!(__GET_VAR(data__->VALVULA1,)) && __GET_VAR(data__->SENSOR_PESO_1,)) || __GET_VAR(data__->SENSOR_PESO_1,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  if (__GET_VAR(data__->TON1.Q,)) {
    __SET_VAR(data__->,MOTOR1,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON0.,IN,,(((!(__GET_VAR(data__->MOTOR1,)) && !(__GET_VAR(data__->SENSOR_PESO_1,))) && __GET_VAR(data__->SENSOR_IR_1,)) || (!(__GET_VAR(data__->SENSOR_PESO_1,)) && __GET_VAR(data__->SENSOR_IR_1,))));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  if (__GET_VAR(data__->TON0.Q,)) {
    __SET_VAR(data__->,VALVULA1,,__BOOL_LITERAL(TRUE));
  };
  if ((!(__GET_VAR(data__->SENSOR_PESO_1,)) && __GET_VAR(data__->SENSOR_IR_1,))) {
    __SET_VAR(data__->,MOTOR1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->SENSOR_PESO_1,)) {
    __SET_VAR(data__->,VALVULA1,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





