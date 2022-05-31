/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Rana Mohamed
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration={
   PORT_A,PORT_A_PIN0,PORT_A_PIN0_DIRECTION,PORT_A_PIN0_RESISTORS,PORT_A_PIN0_INITIAL_VALUE,PORT_A_PIN0_ALTERNATIVE_MODE,PORT_A_PIN0_DIRECTION_CHANGEABLE,PORT_A_PIN0_MODE_CHANGEABLE,\
   PORT_A,PORT_A_PIN1,PORT_A_PIN1_DIRECTION,PORT_A_PIN1_RESISTORS,PORT_A_PIN1_INITIAL_VALUE,PORT_A_PIN1_ALTERNATIVE_MODE,PORT_A_PIN1_DIRECTION_CHANGEABLE,PORT_A_PIN1_MODE_CHANGEABLE,\
   PORT_A,PORT_A_PIN2,PORT_A_PIN2_DIRECTION,PORT_A_PIN2_RESISTORS,PORT_A_PIN2_INITIAL_VALUE,PORT_A_PIN2_ALTERNATIVE_MODE,PORT_A_PIN2_DIRECTION_CHANGEABLE,PORT_A_PIN2_MODE_CHANGEABLE,\
   PORT_A,PORT_A_PIN3,PORT_A_PIN3_DIRECTION,PORT_A_PIN3_RESISTORS,PORT_A_PIN3_INITIAL_VALUE,PORT_A_PIN3_ALTERNATIVE_MODE,PORT_A_PIN3_DIRECTION_CHANGEABLE,PORT_A_PIN3_MODE_CHANGEABLE,\
   PORT_A,PORT_A_PIN4,PORT_A_PIN4_DIRECTION,PORT_A_PIN4_RESISTORS,PORT_A_PIN4_INITIAL_VALUE,PORT_A_PIN4_ALTERNATIVE_MODE,PORT_A_PIN4_DIRECTION_CHANGEABLE,PORT_A_PIN4_MODE_CHANGEABLE,\
   PORT_A,PORT_A_PIN5,PORT_A_PIN5_DIRECTION,PORT_A_PIN5_RESISTORS,PORT_A_PIN5_INITIAL_VALUE,PORT_A_PIN5_ALTERNATIVE_MODE,PORT_A_PIN5_DIRECTION_CHANGEABLE,PORT_A_PIN5_MODE_CHANGEABLE,\
   PORT_A,PORT_A_PIN6,PORT_A_PIN6_DIRECTION,PORT_A_PIN6_RESISTORS,PORT_A_PIN6_INITIAL_VALUE,PORT_A_PIN6_ALTERNATIVE_MODE,PORT_A_PIN6_DIRECTION_CHANGEABLE,PORT_A_PIN6_MODE_CHANGEABLE,\
   PORT_A,PORT_A_PIN7,PORT_A_PIN7_DIRECTION,PORT_A_PIN7_RESISTORS,PORT_A_PIN7_INITIAL_VALUE,PORT_A_PIN7_ALTERNATIVE_MODE,PORT_A_PIN7_DIRECTION_CHANGEABLE,PORT_A_PIN7_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN0,PORT_B_PIN0_DIRECTION,PORT_B_PIN0_RESISTORS,PORT_B_PIN0_INITIAL_VALUE,PORT_B_PIN0_ALTERNATIVE_MODE,PORT_B_PIN0_DIRECTION_CHANGEABLE,PORT_B_PIN0_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN1,PORT_B_PIN1_DIRECTION,PORT_B_PIN1_RESISTORS,PORT_B_PIN1_INITIAL_VALUE,PORT_B_PIN1_ALTERNATIVE_MODE,PORT_B_PIN1_DIRECTION_CHANGEABLE,PORT_B_PIN1_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN2,PORT_B_PIN2_DIRECTION,PORT_B_PIN2_RESISTORS,PORT_B_PIN2_INITIAL_VALUE,PORT_B_PIN2_ALTERNATIVE_MODE,PORT_B_PIN2_DIRECTION_CHANGEABLE,PORT_B_PIN2_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN3,PORT_B_PIN3_DIRECTION,PORT_B_PIN3_RESISTORS,PORT_B_PIN3_INITIAL_VALUE,PORT_B_PIN3_ALTERNATIVE_MODE,PORT_B_PIN3_DIRECTION_CHANGEABLE,PORT_B_PIN3_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN4,PORT_B_PIN4_DIRECTION,PORT_B_PIN4_RESISTORS,PORT_B_PIN4_INITIAL_VALUE,PORT_B_PIN4_ALTERNATIVE_MODE,PORT_B_PIN4_DIRECTION_CHANGEABLE,PORT_B_PIN4_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN5,PORT_B_PIN5_DIRECTION,PORT_B_PIN5_RESISTORS,PORT_B_PIN5_INITIAL_VALUE,PORT_B_PIN5_ALTERNATIVE_MODE,PORT_B_PIN5_DIRECTION_CHANGEABLE,PORT_B_PIN5_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN6,PORT_B_PIN6_DIRECTION,PORT_B_PIN6_RESISTORS,PORT_B_PIN6_INITIAL_VALUE,PORT_B_PIN6_ALTERNATIVE_MODE,PORT_B_PIN6_DIRECTION_CHANGEABLE,PORT_B_PIN6_MODE_CHANGEABLE,\
   PORT_B,PORT_B_PIN7,PORT_B_PIN7_DIRECTION,PORT_B_PIN7_RESISTORS,PORT_B_PIN7_INITIAL_VALUE,PORT_B_PIN7_ALTERNATIVE_MODE,PORT_B_PIN7_DIRECTION_CHANGEABLE,PORT_B_PIN7_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN0,PORT_C_PIN0_DIRECTION,PORT_C_PIN0_RESISTORS,PORT_C_PIN0_INITIAL_VALUE,PORT_C_PIN0_ALTERNATIVE_MODE,PORT_C_PIN0_DIRECTION_CHANGEABLE,PORT_C_PIN0_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN1,PORT_C_PIN1_DIRECTION,PORT_C_PIN1_RESISTORS,PORT_C_PIN1_INITIAL_VALUE,PORT_C_PIN1_ALTERNATIVE_MODE,PORT_C_PIN1_DIRECTION_CHANGEABLE,PORT_C_PIN1_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN2,PORT_C_PIN2_DIRECTION,PORT_C_PIN2_RESISTORS,PORT_C_PIN2_INITIAL_VALUE,PORT_C_PIN2_ALTERNATIVE_MODE,PORT_C_PIN2_DIRECTION_CHANGEABLE,PORT_C_PIN2_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN3,PORT_C_PIN3_DIRECTION,PORT_C_PIN3_RESISTORS,PORT_C_PIN3_INITIAL_VALUE,PORT_C_PIN3_ALTERNATIVE_MODE,PORT_C_PIN3_DIRECTION_CHANGEABLE,PORT_C_PIN3_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN4,PORT_C_PIN4_DIRECTION,PORT_C_PIN4_RESISTORS,PORT_C_PIN4_INITIAL_VALUE,PORT_C_PIN4_ALTERNATIVE_MODE,PORT_C_PIN4_DIRECTION_CHANGEABLE,PORT_C_PIN4_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN5,PORT_C_PIN5_DIRECTION,PORT_C_PIN5_RESISTORS,PORT_C_PIN5_INITIAL_VALUE,PORT_C_PIN5_ALTERNATIVE_MODE,PORT_C_PIN5_DIRECTION_CHANGEABLE,PORT_C_PIN5_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN6,PORT_C_PIN6_DIRECTION,PORT_C_PIN6_RESISTORS,PORT_C_PIN6_INITIAL_VALUE,PORT_C_PIN6_ALTERNATIVE_MODE,PORT_C_PIN6_DIRECTION_CHANGEABLE,PORT_C_PIN6_MODE_CHANGEABLE,\
   PORT_C,PORT_C_PIN7,PORT_C_PIN7_DIRECTION,PORT_C_PIN7_RESISTORS,PORT_C_PIN7_INITIAL_VALUE,PORT_C_PIN7_ALTERNATIVE_MODE,PORT_C_PIN7_DIRECTION_CHANGEABLE,PORT_C_PIN7_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN0,PORT_D_PIN0_DIRECTION,PORT_D_PIN0_RESISTORS,PORT_D_PIN0_INITIAL_VALUE,PORT_D_PIN0_ALTERNATIVE_MODE,PORT_D_PIN0_DIRECTION_CHANGEABLE,PORT_D_PIN0_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN1,PORT_D_PIN1_DIRECTION,PORT_D_PIN1_RESISTORS,PORT_D_PIN1_INITIAL_VALUE,PORT_D_PIN1_ALTERNATIVE_MODE,PORT_D_PIN1_DIRECTION_CHANGEABLE,PORT_D_PIN1_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN2,PORT_D_PIN2_DIRECTION,PORT_D_PIN2_RESISTORS,PORT_D_PIN2_INITIAL_VALUE,PORT_D_PIN2_ALTERNATIVE_MODE,PORT_D_PIN2_DIRECTION_CHANGEABLE,PORT_D_PIN2_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN3,PORT_D_PIN3_DIRECTION,PORT_D_PIN3_RESISTORS,PORT_D_PIN3_INITIAL_VALUE,PORT_D_PIN3_ALTERNATIVE_MODE,PORT_D_PIN3_DIRECTION_CHANGEABLE,PORT_D_PIN3_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN4,PORT_D_PIN4_DIRECTION,PORT_D_PIN4_RESISTORS,PORT_D_PIN4_INITIAL_VALUE,PORT_D_PIN4_ALTERNATIVE_MODE,PORT_D_PIN4_DIRECTION_CHANGEABLE,PORT_D_PIN4_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN5,PORT_D_PIN5_DIRECTION,PORT_D_PIN5_RESISTORS,PORT_D_PIN5_INITIAL_VALUE,PORT_D_PIN5_ALTERNATIVE_MODE,PORT_D_PIN5_DIRECTION_CHANGEABLE,PORT_D_PIN5_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN6,PORT_D_PIN6_DIRECTION,PORT_D_PIN6_RESISTORS,PORT_D_PIN6_INITIAL_VALUE,PORT_D_PIN6_ALTERNATIVE_MODE,PORT_D_PIN6_DIRECTION_CHANGEABLE,PORT_D_PIN6_MODE_CHANGEABLE,\
   PORT_D,PORT_D_PIN7,PORT_D_PIN7_DIRECTION,PORT_D_PIN7_RESISTORS,PORT_D_PIN7_INITIAL_VALUE,PORT_D_PIN7_ALTERNATIVE_MODE,PORT_D_PIN7_DIRECTION_CHANGEABLE,PORT_D_PIN7_MODE_CHANGEABLE,\
   PORT_E,PORT_E_PIN0,PORT_E_PIN0_DIRECTION,PORT_E_PIN0_RESISTORS,PORT_E_PIN0_INITIAL_VALUE,PORT_E_PIN0_ALTERNATIVE_MODE,PORT_E_PIN0_DIRECTION_CHANGEABLE,PORT_E_PIN0_MODE_CHANGEABLE,\
   PORT_E,PORT_E_PIN1,PORT_E_PIN1_DIRECTION,PORT_E_PIN1_RESISTORS,PORT_E_PIN1_INITIAL_VALUE,PORT_E_PIN1_ALTERNATIVE_MODE,PORT_E_PIN1_DIRECTION_CHANGEABLE,PORT_E_PIN1_MODE_CHANGEABLE,\
   PORT_E,PORT_E_PIN2,PORT_E_PIN2_DIRECTION,PORT_E_PIN2_RESISTORS,PORT_E_PIN2_INITIAL_VALUE,PORT_E_PIN2_ALTERNATIVE_MODE,PORT_E_PIN2_DIRECTION_CHANGEABLE,PORT_E_PIN2_MODE_CHANGEABLE,\
   PORT_E,PORT_E_PIN3,PORT_E_PIN3_DIRECTION,PORT_E_PIN3_RESISTORS,PORT_E_PIN3_INITIAL_VALUE,PORT_E_PIN3_ALTERNATIVE_MODE,PORT_E_PIN3_DIRECTION_CHANGEABLE,PORT_E_PIN3_MODE_CHANGEABLE,\
   PORT_E,PORT_E_PIN4,PORT_E_PIN4_DIRECTION,PORT_E_PIN4_RESISTORS,PORT_E_PIN4_INITIAL_VALUE,PORT_E_PIN4_ALTERNATIVE_MODE,PORT_E_PIN4_DIRECTION_CHANGEABLE,PORT_E_PIN4_MODE_CHANGEABLE,\
   PORT_E,PORT_E_PIN5,PORT_E_PIN5_DIRECTION,PORT_E_PIN5_RESISTORS,PORT_E_PIN5_INITIAL_VALUE,PORT_E_PIN5_ALTERNATIVE_MODE,PORT_E_PIN5_DIRECTION_CHANGEABLE,PORT_E_PIN5_MODE_CHANGEABLE,\
   PORT_F,PORT_F_PIN0,PORT_F_PIN0_DIRECTION,PORT_F_PIN0_RESISTORS,PORT_F_PIN0_INITIAL_VALUE,PORT_F_PIN0_ALTERNATIVE_MODE,PORT_F_PIN0_DIRECTION_CHANGEABLE,PORT_F_PIN0_MODE_CHANGEABLE,\
   PORT_F,PORT_F_PIN1,PORT_F_PIN1_DIRECTION,PORT_F_PIN1_RESISTORS,PORT_F_PIN1_INITIAL_VALUE,PORT_F_PIN1_ALTERNATIVE_MODE,PORT_F_PIN1_DIRECTION_CHANGEABLE,PORT_F_PIN1_MODE_CHANGEABLE,\
   PORT_F,PORT_F_PIN2,PORT_F_PIN2_DIRECTION,PORT_F_PIN2_RESISTORS,PORT_F_PIN2_INITIAL_VALUE,PORT_F_PIN2_ALTERNATIVE_MODE,PORT_F_PIN2_DIRECTION_CHANGEABLE,PORT_F_PIN2_MODE_CHANGEABLE,\
   PORT_F,PORT_F_PIN3,PORT_F_PIN3_DIRECTION,PORT_F_PIN3_RESISTORS,PORT_F_PIN3_INITIAL_VALUE,PORT_F_PIN3_ALTERNATIVE_MODE,PORT_F_PIN3_DIRECTION_CHANGEABLE,PORT_F_PIN3_MODE_CHANGEABLE,\
   PORT_F,PORT_F_PIN4,PORT_F_PIN4_DIRECTION,PORT_F_PIN4_RESISTORS,PORT_F_PIN4_INITIAL_VALUE,PORT_F_PIN4_ALTERNATIVE_MODE,PORT_F_PIN4_DIRECTION_CHANGEABLE,PORT_F_PIN4_MODE_CHANGEABLE
};