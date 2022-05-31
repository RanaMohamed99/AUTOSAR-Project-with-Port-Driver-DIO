/******************************************************************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Rana Mohamed
 *****************************************************************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION      (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION      (3U)

   
/* Pre-compile option for Development Error Detect */
#define PORT_Dev_Error_Detect                 (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                 (STD_OFF)

/* Pre-compile option for presence of Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API            (STD_ON)   

   
/* Number of Pins in the Mcu (MCU DEPENDENT) */
#define PORT_NUMBER_OF_PORT_PINS              (Port_PinType)(43U)

   
/* Ports Defenitions */
   
#define PORT_A                                 (0U)
#define PORT_B                                 (1U)
#define PORT_C                                 (2U)
#define PORT_D                                 (3U)
#define PORT_E                                 (4U)
#define PORT_F                                 (5U)  

   
/* Pins Definition */

/*Port A Pins */
#define PORT_A_PIN0                  (Port_PinType)0
#define PORT_A_PIN1                  (Port_PinType)1
#define PORT_A_PIN2                  (Port_PinType)2
#define PORT_A_PIN3                  (Port_PinType)3
#define PORT_A_PIN4                  (Port_PinType)4
#define PORT_A_PIN5                  (Port_PinType)5
#define PORT_A_PIN6                  (Port_PinType)6
#define PORT_A_PIN7                  (Port_PinType)7 

/*Port B Pins */
#define PORT_B_PIN0                  (Port_PinType)0
#define PORT_B_PIN1                  (Port_PinType)1
#define PORT_B_PIN2                  (Port_PinType)2
#define PORT_B_PIN3                  (Port_PinType)3
#define PORT_B_PIN4                  (Port_PinType)4
#define PORT_B_PIN5                  (Port_PinType)5
#define PORT_B_PIN6                  (Port_PinType)6
#define PORT_B_PIN7                  (Port_PinType)7 

/*Port C Pins */
#define PORT_C_PIN0                  (Port_PinType)0
#define PORT_C_PIN1                  (Port_PinType)1
#define PORT_C_PIN2                  (Port_PinType)2
#define PORT_C_PIN3                  (Port_PinType)3
#define PORT_C_PIN4                  (Port_PinType)4
#define PORT_C_PIN5                  (Port_PinType)5
#define PORT_C_PIN6                  (Port_PinType)6
#define PORT_C_PIN7                  (Port_PinType)7 

/*Port D Pins */
#define PORT_D_PIN0                  (Port_PinType)0
#define PORT_D_PIN1                  (Port_PinType)1
#define PORT_D_PIN2                  (Port_PinType)2
#define PORT_D_PIN3                  (Port_PinType)3
#define PORT_D_PIN4                  (Port_PinType)4
#define PORT_D_PIN5                  (Port_PinType)5
#define PORT_D_PIN6                  (Port_PinType)6
#define PORT_D_PIN7                  (Port_PinType)7

/*Port E Pins */
#define PORT_E_PIN0                  (Port_PinType)0
#define PORT_E_PIN1                  (Port_PinType)1
#define PORT_E_PIN2                  (Port_PinType)2
#define PORT_E_PIN3                  (Port_PinType)3
#define PORT_E_PIN4                  (Port_PinType)4
#define PORT_E_PIN5                  (Port_PinType)5

/*Port F Pins */
#define PORT_F_PIN0                  (Port_PinType)0
#define PORT_F_PIN1                  (Port_PinType)1
#define PORT_F_PIN2                  (Port_PinType)2
#define PORT_F_PIN3                  (Port_PinType)3
#define PORT_F_PIN4                  (Port_PinType)4

   
/* Ports Direction 
* INPUT  -> 0
* OUTPUT -> 1      
*/ 

/*Port A Pins direction for PBcfg.c , all intialized as input*/
#define PORT_A_PIN0_DIRECTION                   (INPUT)
#define PORT_A_PIN1_DIRECTION                   (INPUT)
#define PORT_A_PIN2_DIRECTION                   (INPUT)
#define PORT_A_PIN3_DIRECTION                   (INPUT)
#define PORT_A_PIN4_DIRECTION                   (INPUT)
#define PORT_A_PIN5_DIRECTION                   (INPUT)
#define PORT_A_PIN6_DIRECTION                   (INPUT)
#define PORT_A_PIN7_DIRECTION                   (INPUT)

/*Port B Pins direction for PBcfg.c , all intialized as input*/
#define PORT_B_PIN0_DIRECTION                   (INPUT)
#define PORT_B_PIN1_DIRECTION                   (INPUT)
#define PORT_B_PIN2_DIRECTION                   (INPUT)
#define PORT_B_PIN3_DIRECTION                   (INPUT)
#define PORT_B_PIN4_DIRECTION                   (INPUT)
#define PORT_B_PIN5_DIRECTION                   (INPUT)
#define PORT_B_PIN6_DIRECTION                   (INPUT)
#define PORT_B_PIN7_DIRECTION                   (INPUT) 

/*Port C Pins direction for PBcfg.c , all intialized as input*/
#define PORT_C_PIN0_DIRECTION                   (INPUT)
#define PORT_C_PIN1_DIRECTION                   (INPUT)
#define PORT_C_PIN2_DIRECTION                   (INPUT)
#define PORT_C_PIN3_DIRECTION                   (INPUT)
#define PORT_C_PIN4_DIRECTION                   (INPUT)
#define PORT_C_PIN5_DIRECTION                   (INPUT)
#define PORT_C_PIN6_DIRECTION                   (INPUT)
#define PORT_C_PIN7_DIRECTION                   (INPUT)

/*Port D Pins direction for PBcfg.c , all intialized as input*/
#define PORT_D_PIN0_DIRECTION                   (INPUT)
#define PORT_D_PIN1_DIRECTION                   (INPUT)
#define PORT_D_PIN2_DIRECTION                   (INPUT)
#define PORT_D_PIN3_DIRECTION                   (INPUT)
#define PORT_D_PIN4_DIRECTION                   (INPUT)
#define PORT_D_PIN5_DIRECTION                   (INPUT)
#define PORT_D_PIN6_DIRECTION                   (INPUT)
#define PORT_D_PIN7_DIRECTION                   (INPUT)

/*Port E Pins direction for PBcfg.c , all intialized as input*/
#define PORT_E_PIN0_DIRECTION                   (INPUT)
#define PORT_E_PIN1_DIRECTION                   (INPUT)
#define PORT_E_PIN2_DIRECTION                   (INPUT)
#define PORT_E_PIN3_DIRECTION                   (INPUT)
#define PORT_E_PIN4_DIRECTION                   (INPUT)
#define PORT_E_PIN5_DIRECTION                   (INPUT)

/*Port F Pins direction for PBcfg.c , all intialized as input*/
#define PORT_F_PIN0_DIRECTION                   (INPUT)  
#define PORT_F_PIN1_DIRECTION                   (OUTPUT) /* LED pin as output */  
#define PORT_F_PIN2_DIRECTION                   (INPUT)
#define PORT_F_PIN3_DIRECTION                   (INPUT)
#define PORT_F_PIN4_DIRECTION                   (INPUT) /* Button pin as input */  
   
   
/* Ports Resistiors 
* OFF    -> 0
* PULLUP -> 1 
* PULLDOWN -> 2
*/    
   
/*Port A Pins resistance for PBcfg.c , all intialized as OFF*/
#define PORT_A_PIN0_RESISTORS                   (OFF)
#define PORT_A_PIN1_RESISTORS                   (OFF)
#define PORT_A_PIN2_RESISTORS                   (OFF)
#define PORT_A_PIN3_RESISTORS                   (OFF)
#define PORT_A_PIN4_RESISTORS                   (OFF)
#define PORT_A_PIN5_RESISTORS                   (OFF)
#define PORT_A_PIN6_RESISTORS                   (OFF)
#define PORT_A_PIN7_RESISTORS                   (OFF)

/*Port B Pins resistance for PBcfg.c , all intialized as OFF*/
#define PORT_B_PIN0_RESISTORS                   (OFF)
#define PORT_B_PIN1_RESISTORS                   (OFF)
#define PORT_B_PIN2_RESISTORS                   (OFF)
#define PORT_B_PIN3_RESISTORS                   (OFF)
#define PORT_B_PIN4_RESISTORS                   (OFF)
#define PORT_B_PIN5_RESISTORS                   (OFF)
#define PORT_B_PIN6_RESISTORS                   (OFF)
#define PORT_B_PIN7_RESISTORS                   (OFF) 

/*Port C Pins resistance for PBcfg.c , all intialized as OFF*/
#define PORT_C_PIN0_RESISTORS                   (OFF)
#define PORT_C_PIN1_RESISTORS                   (OFF)
#define PORT_C_PIN2_RESISTORS                   (OFF)
#define PORT_C_PIN3_RESISTORS                   (OFF)
#define PORT_C_PIN4_RESISTORS                   (OFF)
#define PORT_C_PIN5_RESISTORS                   (OFF)
#define PORT_C_PIN6_RESISTORS                   (OFF)
#define PORT_C_PIN7_RESISTORS                   (OFF)

/*Port D Pins resistance for PBcfg.c , all intialized as OFF*/
#define PORT_D_PIN0_RESISTORS                   (OFF)
#define PORT_D_PIN1_RESISTORS                   (OFF)
#define PORT_D_PIN2_RESISTORS                   (OFF)
#define PORT_D_PIN3_RESISTORS                   (OFF)
#define PORT_D_PIN4_RESISTORS                   (OFF)
#define PORT_D_PIN5_RESISTORS                   (OFF)
#define PORT_D_PIN6_RESISTORS                   (OFF)
#define PORT_D_PIN7_RESISTORS                   (OFF)

/*Port E Pins resistance for PBcfg.c , all intialized as OFF */
#define PORT_E_PIN0_RESISTORS                   (OFF)
#define PORT_E_PIN1_RESISTORS                   (OFF)
#define PORT_E_PIN2_RESISTORS                   (OFF)
#define PORT_E_PIN3_RESISTORS                   (OFF)
#define PORT_E_PIN4_RESISTORS                   (OFF)
#define PORT_E_PIN5_RESISTORS                   (OFF)

/*Port F Pins resistance for PBcfg.c , all intialized as OFF*/
#define PORT_F_PIN0_RESISTORS                   (OFF)
#define PORT_F_PIN1_RESISTORS                   (OFF) /*  resistance disabled for LED */
#define PORT_F_PIN2_RESISTORS                   (OFF)
#define PORT_F_PIN3_RESISTORS                   (OFF)
#define PORT_F_PIN4_RESISTORS                   (PULL_UP)   /*pull up resistance for button */    
  

/* Modes in AUTOSAR SWS for Channels Modes*/  
/* Alternative Modes Definiton */ 


/* ADC doesnt have a specifeied number in the table of modes,thus let it be 15*/    
#define PORT_PIN_MODE_ADC                       (15U)
/*Dio is number 1 in the table of modes in Data sheet*/
#define PORT_PIN_MODE_DIO                       (0U) 

#define ALTERNATIVE_MODE_0                      (0U)
#define ALTERNATIVE_MODE_1                      (1U)
#define ALTERNATIVE_MODE_2                      (2U)
#define ALTERNATIVE_MODE_3                      (3U)
#define ALTERNATIVE_MODE_4                      (4U)
#define ALTERNATIVE_MODE_5                      (5U)
#define ALTERNATIVE_MODE_6                      (6U)
#define ALTERNATIVE_MODE_7                      (7U)
#define ALTERNATIVE_MODE_8                      (8U)
#define ALTERNATIVE_MODE_9                      (9U)
#define ALTERNATIVE_MODE_10                     (10U)
#define ALTERNATIVE_MODE_11                     (11U)
#define ALTERNATIVE_MODE_12                     (12U)
#define ALTERNATIVE_MODE_13                     (13U)
#define ALTERNATIVE_MODE_14                     (14U)  
   
   
/* Port A pins Modes for PBcfg.c , all intialized as DIO*/
   
#define PORT_A_PIN0_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_A_PIN1_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_A_PIN2_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_A_PIN3_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_A_PIN4_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_A_PIN5_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_A_PIN6_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_A_PIN7_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
   
/* Port B pins Modes for PBcfg.c , all intialized as DIO*/
   
#define PORT_B_PIN0_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_B_PIN1_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_B_PIN2_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_B_PIN3_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_B_PIN4_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_B_PIN5_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_B_PIN6_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_B_PIN7_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0   
   
/* Port C pins Modes for PBcfg.c , all intialized as DIO */
   
#define PORT_C_PIN0_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_C_PIN1_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_C_PIN2_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_C_PIN3_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_C_PIN4_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_C_PIN5_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_C_PIN6_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_C_PIN7_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0 
   
/* Port D pins Modes for PBcfg.c , all intialized as DIO*/
   
#define PORT_D_PIN0_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_D_PIN1_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_D_PIN2_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_D_PIN3_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_D_PIN4_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_D_PIN5_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_D_PIN6_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_D_PIN7_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0 
   
/* Port E pins Modes for PBcfg.c , all intialized as DIO*/
   
#define PORT_E_PIN0_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_E_PIN1_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_E_PIN2_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_E_PIN3_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_E_PIN4_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_E_PIN5_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0

   
/* Port F pins Modes for PBcfg.c , all intialized as DIO*/
   
#define PORT_F_PIN0_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_F_PIN1_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_F_PIN2_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_F_PIN3_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0
#define PORT_F_PIN4_ALTERNATIVE_MODE                  ALTERNATIVE_MODE_0   


/* Ports Initial Value */

/* Port A Initial value for PBcfg.c , all intialized as LOW*/
#define PORT_A_PIN0_INITIAL_VALUE                     (STD_LOW)
#define PORT_A_PIN1_INITIAL_VALUE                     (STD_LOW)
#define PORT_A_PIN2_INITIAL_VALUE                     (STD_LOW)
#define PORT_A_PIN3_INITIAL_VALUE                     (STD_LOW)
#define PORT_A_PIN4_INITIAL_VALUE                     (STD_LOW)
#define PORT_A_PIN5_INITIAL_VALUE                     (STD_LOW)
#define PORT_A_PIN6_INITIAL_VALUE                     (STD_LOW)
#define PORT_A_PIN7_INITIAL_VALUE                     (STD_LOW)   
   
/* Port B Initial value for PBcfg.c , all intialized as LOW*/
#define PORT_B_PIN0_INITIAL_VALUE                     (STD_LOW)
#define PORT_B_PIN1_INITIAL_VALUE                     (STD_LOW)
#define PORT_B_PIN2_INITIAL_VALUE                     (STD_LOW)
#define PORT_B_PIN3_INITIAL_VALUE                     (STD_LOW)
#define PORT_B_PIN4_INITIAL_VALUE                     (STD_LOW)
#define PORT_B_PIN5_INITIAL_VALUE                     (STD_LOW)
#define PORT_B_PIN6_INITIAL_VALUE                     (STD_LOW)
#define PORT_B_PIN7_INITIAL_VALUE                     (STD_LOW)     
 
/* Port C Initial value for PBcfg.c , all intialized as LOW*/
#define PORT_C_PIN0_INITIAL_VALUE                     (STD_LOW)
#define PORT_C_PIN1_INITIAL_VALUE                     (STD_LOW)
#define PORT_C_PIN2_INITIAL_VALUE                     (STD_LOW)
#define PORT_C_PIN3_INITIAL_VALUE                     (STD_LOW)
#define PORT_C_PIN4_INITIAL_VALUE                     (STD_LOW)
#define PORT_C_PIN5_INITIAL_VALUE                     (STD_LOW)
#define PORT_C_PIN6_INITIAL_VALUE                     (STD_LOW)
#define PORT_C_PIN7_INITIAL_VALUE                     (STD_LOW)     
   
/* Port D Initial value for PBcfg.c , all intialized as LOW*/
#define PORT_D_PIN0_INITIAL_VALUE                     (STD_LOW)
#define PORT_D_PIN1_INITIAL_VALUE                     (STD_LOW)
#define PORT_D_PIN2_INITIAL_VALUE                     (STD_LOW)
#define PORT_D_PIN3_INITIAL_VALUE                     (STD_LOW)
#define PORT_D_PIN4_INITIAL_VALUE                     (STD_LOW)
#define PORT_D_PIN5_INITIAL_VALUE                     (STD_LOW)
#define PORT_D_PIN6_INITIAL_VALUE                     (STD_LOW)
#define PORT_D_PIN7_INITIAL_VALUE                     (STD_LOW)
   
/* Port E Initial value for PBcfg.c , all intialized as LOW*/
#define PORT_E_PIN0_INITIAL_VALUE                     (STD_LOW)
#define PORT_E_PIN1_INITIAL_VALUE                     (STD_LOW)
#define PORT_E_PIN2_INITIAL_VALUE                     (STD_LOW)
#define PORT_E_PIN3_INITIAL_VALUE                     (STD_LOW)
#define PORT_E_PIN4_INITIAL_VALUE                     (STD_LOW)
#define PORT_E_PIN5_INITIAL_VALUE                     (STD_LOW)
   
/* Port F Initial value for PBcfg.c , all intialized as LOW*/
#define PORT_F_PIN0_INITIAL_VALUE                     (STD_LOW)
#define PORT_F_PIN1_INITIAL_VALUE                     (STD_LOW) /* led inital value off  */
#define PORT_F_PIN2_INITIAL_VALUE                     (STD_LOW)
#define PORT_F_PIN3_INITIAL_VALUE                     (STD_LOW)
#define PORT_F_PIN4_INITIAL_VALUE                     (STD_HIGH) /* button intialized as released so its input is high */ 

   
/* Ports Direction Changeable*/  
   
/* Port A Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_A_PIN0_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_A_PIN1_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_A_PIN2_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_A_PIN3_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_A_PIN4_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_A_PIN5_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_A_PIN6_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_A_PIN7_DIRECTION_CHANGEABLE              (STD_OFF)   
   
/* Port B Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_B_PIN0_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_B_PIN1_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_B_PIN2_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_B_PIN3_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_B_PIN4_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_B_PIN5_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_B_PIN6_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_B_PIN7_DIRECTION_CHANGEABLE              (STD_OFF)     
 
/* Port C Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_C_PIN0_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_C_PIN1_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_C_PIN2_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_C_PIN3_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_C_PIN4_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_C_PIN5_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_C_PIN6_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_C_PIN7_DIRECTION_CHANGEABLE              (STD_OFF)     
   
/* Port D Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_D_PIN0_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_D_PIN1_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_D_PIN2_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_D_PIN3_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_D_PIN4_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_D_PIN5_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_D_PIN6_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_D_PIN7_DIRECTION_CHANGEABLE              (STD_OFF)
   
/* Port E Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_E_PIN0_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_E_PIN1_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_E_PIN2_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_E_PIN3_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_E_PIN4_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_E_PIN5_DIRECTION_CHANGEABLE              (STD_OFF)
   
/* Port F Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_F_PIN0_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_F_PIN1_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_F_PIN2_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_F_PIN3_DIRECTION_CHANGEABLE              (STD_OFF)
#define PORT_F_PIN4_DIRECTION_CHANGEABLE              (STD_OFF)

/* Ports Mode Changeable*/
   
/* Port A Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_A_PIN0_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_A_PIN1_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_A_PIN2_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_A_PIN3_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_A_PIN4_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_A_PIN5_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_A_PIN6_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_A_PIN7_MODE_CHANGEABLE                   (STD_OFF)   
   
/* Port B Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_B_PIN0_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_B_PIN1_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_B_PIN2_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_B_PIN3_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_B_PIN4_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_B_PIN5_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_B_PIN6_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_B_PIN7_MODE_CHANGEABLE                   (STD_OFF)     
 
/* Port C Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_C_PIN0_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_C_PIN1_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_C_PIN2_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_C_PIN3_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_C_PIN4_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_C_PIN5_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_C_PIN6_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_C_PIN7_MODE_CHANGEABLE                   (STD_OFF)     
   
/* Port D Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_D_PIN0_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_D_PIN1_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_D_PIN2_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_D_PIN3_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_D_PIN4_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_D_PIN5_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_D_PIN6_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_D_PIN7_MODE_CHANGEABLE                   (STD_OFF)
   
/* Port E Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_E_PIN0_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_E_PIN1_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_E_PIN2_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_E_PIN3_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_E_PIN4_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_E_PIN5_MODE_CHANGEABLE                   (STD_OFF)
   
/* Port F Direction Changable for PBcfg.c , all intialized as OFF*/
#define PORT_F_PIN0_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_F_PIN1_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_F_PIN2_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_F_PIN3_MODE_CHANGEABLE                   (STD_OFF)
#define PORT_F_PIN4_MODE_CHANGEABLE                   (STD_OFF)  
   
   
   
   
   
#endif /* PORT_CFG_H */