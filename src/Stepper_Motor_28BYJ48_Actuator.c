#include "Stepper_Motor_28BYJ48_Actuator.h"

#include "Arduino.h"

/*============================================================================*/
/* Macros */
/*============================================================================*/
#define NUMBER_OF_STEPS 4


/*============================================================================*/
/* Attributes access */
/*============================================================================*/
#define My_Current_Step (Me->var_attr->Current_Step)


/*============================================================================*/
/* Private methods declaration */
/*============================================================================*/
static void Set_Step( const Stepper_Motor_28BYJ48_Actuator* Me );


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Stepper_Motor_28BYJ48_Actuator__Motor_Actuation__Step_Clockwise(
    const Stepper_Motor_28BYJ48_Actuator* Me )
{
    My_Current_Step += 1 ;
    if ( My_Current_Step == NUMBER_OF_STEPS )
    {
        My_Current_Step = 0;
    }
    Set_Step( Me );
}
/*----------------------------------------------------------------------------*/
void Stepper_Motor_28BYJ48_Actuator__Motor_Actuation__Step_Counterclockwise(
    const Stepper_Motor_28BYJ48_Actuator* Me )
{
    if ( My_Current_Step == 0 )
    {
        My_Current_Step = NUMBER_OF_STEPS;
    }
    My_Current_Step -= 1;
    Set_Step( Me );
}


/*============================================================================*/
/* Private methods definition */
/*============================================================================*/
static void Set_Step( const Stepper_Motor_28BYJ48_Actuator* Me )
{
    switch (My_Current_Step)
    {
        case 0:  /* blue - A */
            Me->ULN2003_Pin_1->Set_Level(IO_LEVEL_HIGH);
            Me->ULN2003_Pin_2->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_3->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_4->Set_Level(IO_LEVEL_LOW);
            break;
        case 1:  /* orange - D */
            Me->ULN2003_Pin_1->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_2->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_3->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_4->Set_Level(IO_LEVEL_HIGH);
            break;
        case 2:  /*  yellow - C */
            Me->ULN2003_Pin_1->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_2->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_3->Set_Level(IO_LEVEL_HIGH);
            Me->ULN2003_Pin_4->Set_Level(IO_LEVEL_LOW);
            break;
        case 3:  /* pink - B */
            Me->ULN2003_Pin_1->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_2->Set_Level(IO_LEVEL_HIGH);
            Me->ULN2003_Pin_3->Set_Level(IO_LEVEL_LOW);
            Me->ULN2003_Pin_4->Set_Level(IO_LEVEL_LOW);
            break;
    }    
}