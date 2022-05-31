 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Rana Mohamed
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (120U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


/*
 * Macros for Port Status
 */
#define PORT_NOT_INITIALIZED            (0U)
#define PORT_INITIALIZED                (1U)



/* Standard AUTOSAR types */
#include "Std_Types.h"


/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

   
/* Dio Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

   
/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

   
/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

   
/* Non AUTOSAR files */
#include "Common_Macros.h"

   
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Port Init */
#define PORT_INIT_SID                  (uint8)0x00

/* Service ID for Port Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID     (uint8)0x01

/* Service ID for Port Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION    (uint8)0x02

/* Service ID for Port Get Version Info */
#define PORT_GET_VERSION_INFO_SID      (uint8)0x03

/* Service ID for Port Set Pin Mode */
#define PORT_SET_PIN_MODE_SID          (uint8)0x04

   
/*******************************************************************************
 *                      DET Error Codes                                        *
 ******************************************************************************/

/* DET code to report Invalid Port Pin ID */
#define PORT_E_PARAM_PIN               (uint8)0x0A

/* DET Code to report Port Pin not configured as changeable  */
#define PORT_E_DIRECTION_UNCHANGEABLE  (uint8)0x0B

/* DET code to report API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG            (uint8)0x0C

/* API Port_SetPinMode service called when mode is invalid. */
#define PORT_E_PARAM_INVALID_MODE      (uint8)0x0D

/* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE       (uint8)0x0E

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define PORT_E_PARAM_POINTER           (uint8)0x10

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define PORT_E_UNINIT                  (uint8)0x0F

   
/*******************************************************************************
 *                              Module Data Types                              *
 ******************************************************************************/

/*  Type definition for Port_PinType used by the PORT APIs       */
typedef  uint8 Port_PinType;  

/*  Type definition for Port_PinModeType used by the PORT APIs   */
typedef  uint8 Port_PinModeType;


/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
   OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;


/* Description: Structure to configure each individal PIN:
 *	1. The PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. The Number of the pin in the PORT.
 *      3. The Direction of pin  -->  INPUT or OUTPUT.
 *      4. The Internal Resistor --> Disable, Pull up or Pull down.
 *      5. The Pin Mode  --> DIO, ADC ,UART ,SPI ,I2C.
 *      6. The intial value.
 *      7. The Pin Direction is Changeable --> STD_ON or STD_OFF.
 *      8. The Pin Mode is Changeable --> STD_ON or STD_OFF.   
 */
typedef struct 
{
    uint8 port_num; 
    uint8 pin_num; 
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Port_PinModeType mode;
    uint8 Pin_dirChangeable;
    uint8 Pin_modChangeable;
}Port_Pin;

typedef struct
{
  Port_Pin Ports[PORT_NUMBER_OF_PORT_PINS];
}Port_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/*  Function to Initialize the Port Driver module.*/
void Port_Init( const Port_ConfigType* ConfigPtr );

/* Function to set the port pin direction.*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif

/* Function that refreshes port direction.*/
void Port_RefreshPortDirection( void );

/* Function that returns the version information of this module.*/
#if (PORT_VERSION_INFO_API == STD_OFF)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

/* Function that sets the port pin mode.*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /*PORT_H*/