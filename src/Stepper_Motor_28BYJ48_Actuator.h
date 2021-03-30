#ifndef STEPPER_MOTOR_28BYJ48_ACTUATOR_H
#define STEPPER_MOTOR_28BYJ48_ACTUATOR_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include <stdint.h>

/* Realized interfaces */
#include "Stepper_Motor_Requests.h"

/* Required interfaces */
#include "Discrete_Output.h"


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    uint8_t Current_Step;
} Stepper_Motor_28BYJ48_Actuator_Var;

typedef struct {
    
    /* Variable attributes */
    Stepper_Motor_28BYJ48_Actuator_Var* var_attr;

    /* Required interfaces */
    const Discrete_Output* ULN2003_Pin_1;
    const Discrete_Output* ULN2003_Pin_2;
    const Discrete_Output* ULN2003_Pin_3;
    const Discrete_Output* ULN2003_Pin_4;
    
} Stepper_Motor_28BYJ48_Actuator;


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Stepper_Motor_28BYJ48_Actuator__Motor_Actuation__Step_Clockwise(
    const Stepper_Motor_28BYJ48_Actuator* Me );
void Stepper_Motor_28BYJ48_Actuator__Motor_Actuation__Step_Counterclockwise(
    const Stepper_Motor_28BYJ48_Actuator* Me );

#endif