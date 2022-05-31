 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Rana Mohamed
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_Pin * Port_PortPins = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;


/*******************************************************************************
* Service Name: Port_Init.
* Service ID[hex]: 0x00.
* Sync/Async: Synchronous.
* Reentrancy: Non reentrant.
* Parameters (in): ConfigPtr - Pointer to post-build configuration data.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Function to Initialize the Port Driver module.
*******************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
  volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
  volatile uint32 delay = 0;
  uint8 channel;
  Port_PortPins= ConfigPtr->Ports;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif

for(channel=0;channel<PORT_NUMBER_OF_PORT_PINS;channel++)
{          
 switch(Port_PortPins[channel].port_num)
    {
        case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    
    /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (1<<Port_PortPins[channel].port_num);
    delay = SYSCTL_REGCGC2_REG;
    
    if( ((Port_PortPins[channel].port_num == 3) && (Port_PortPins[channel].pin_num == 7)) || ((Port_PortPins[channel].port_num == 5) && (Port_PortPins[channel].pin_num == 0)) ) /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                                  /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , Port_PortPins[channel].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }
    else if( (Port_PortPins[channel].port_num == 2) && (Port_PortPins[channel].pin_num <= 3) ) /* PC0 to PC3 */
    {
        /* Do Nothing ...  this is the JTAG pins */
        continue;
    }
    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }         
    
    /* Start Checking the Mode of the channels */
    
    if(Port_PortPins[channel].mode == PORT_PIN_MODE_DIO)/* Check if the Mode is DIO activated*/
    {
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[channel].pin_num);       /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[channel].pin_num);              /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
      *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_PortPins[channel].pin_num) * 4));    /* Clear the PMCx bits for this pin */
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Port_PortPins[channel].pin_num);             /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */ 
    
      if(Port_PortPins[channel].direction == OUTPUT)
      {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(Port_PortPins[channel].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[channel].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[channel].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
      } /* end of if direction == OUTPUT */
      else if(Port_PortPins[channel].direction == INPUT)
      {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(Port_PortPins[channel].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[channel].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(Port_PortPins[channel].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[channel].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[channel].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[channel].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
      } /* end of if direction == INPUT */
      else
      {
        /* Do Nothing */
      }
      
    } /* end if of DIO Mode  */
    
  else if(Port_PortPins[channel].mode ==  PORT_PIN_MODE_ADC)/* Check if the Mode is ADC activated*/
   {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortPins[channel].pin_num);     /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */  
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[channel].pin_num);           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_PortPins[channel].pin_num) * 4)); /* Clear the PMCx bits for this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[channel].pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */ 
            
        if(Port_PortPins[channel].direction == OUTPUT)
      {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(Port_PortPins[channel].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[channel].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[channel].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
      } /* end of if direction == OUTPUT */
      else if(Port_PortPins[channel].direction == INPUT)
      {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(Port_PortPins[channel].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[channel].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(Port_PortPins[channel].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[channel].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[channel].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[channel].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
      } /* end of if direction == INPUT */
      else
      {
        /* Do Nothing */
      }         
  } /* end of else if ADC */
    else if(((Port_PortPins[channel].mode) >  PORT_PIN_MODE_DIO)&&((Port_PortPins[channel].mode) <  PORT_PIN_MODE_ADC)) /* Check if other Modes are activated*/
   {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[channel].pin_num);                           /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[channel].pin_num);                                    /* enable Alternative function for this pin by Setting the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_PortPins[channel].pin_num) * 4));                        /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= ((Port_PortPins[channel].mode) << ((Port_PortPins[channel].pin_num) * 4));      /* Set the PMCx bits for this pin to the selected Alternate function in the configurations */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Port_PortPins[channel].pin_num);                               /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */ 
        if(Port_PortPins[channel].direction == OUTPUT)
      {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(Port_PortPins[channel].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[channel].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[channel].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
      } /* end of if direction == OUTPUT */
      else if(Port_PortPins[channel].direction == INPUT)
      {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(Port_PortPins[channel].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[channel].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(Port_PortPins[channel].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[channel].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[channel].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[channel].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
      } /* end of if direction == INPUT */
      else
      {
        /* Do Nothing */
      }             
   }/* end of else if of remaining modes */
   else
   {
     /* No action required */
   }
          
      Port_Status = PORT_INITIALIZED;         
}/* End of for Loop*/
}/*End of Port_Init */
  

/*******************************************************************************
* Service Name: Port_SetPinDirection.
* Service ID[hex]: 0x01.
* Sync/Async: Synchronous.
* Reentrancy: Reentrant.
* Parameters (in): Port Pin ID number,Port Pin Direction.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Function to set the port pin direction.
*******************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{  
  boolean error = FALSE;
  volatile uint32 *PortGpio_Ptr = NULL_PTR;
  
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port configuration is intialized */
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID ,
		     PORT_E_UNINIT);
                error = TRUE;
	}
	else
        {
          /* No action required */
        }
        /* Check if the used channel is within the valid range */
	if (Pin < PORT_NUMBER_OF_PORT_PINS)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID , PORT_E_PARAM_PIN);
                error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
        if(Port_PortPins[Pin].Pin_dirChangeable == STD_OFF)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID , PORT_E_DIRECTION_UNCHANGEABLE);
                error = TRUE;
        }
        else
	{
		/* No Action Required */
	}
#endif
 if(error == FALSE)
   {
        switch(Port_PortPins[Pin].port_num)
       {
         case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	 case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	 case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	 case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
         case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
         case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
       }
      if(Direction == INPUT)
      {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[Pin].pin_num);   /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */ 
      }
      else if(Direction == OUTPUT)
      {   
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[Pin].pin_num);        /* Set the corresponding bit in the GPIODIR register to configure it as output pin */ 
      }
      else
      {
        /* No Action Required */
      }
      
   } /*end of if error == FALSE */ 
  
}/* End of Port_SetPinDirection */ 

#endif



/*******************************************************************************
* Service Name: Port_RefreshPortDirection.
* Service ID[hex]: 0x02.
* Sync/Async: Synchronous.
* Reentrancy: Non-Reentrant.
* Parameters (in): None.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Function that refreshes port direction.
*******************************************************************************/
void Port_RefreshPortDirection( void )
{
  boolean error = FALSE;
  volatile uint32 *PortGpio_Ptr = NULL_PTR;
  uint8 channel;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port configuration is intialized */
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID,
		     PORT_E_UNINIT);
                error = TRUE;
	}
	else
        {
          /* No action required */
        }
     
#endif
 if(error == FALSE)
 {
   for(channel=0; channel < PORT_NUMBER_OF_PORT_PINS; channel++)
    {
         switch(Port_PortPins[channel].port_num)
       {
          case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		   break;
	  case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		   break;
	  case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		   break;
	  case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
	 	   break;
          case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		   break;
          case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		   break;
       }
      if(Port_PortPins[channel].Pin_dirChangeable == STD_ON)
        {
          /* Do Nothing as these pins are excluded */
        }
      else if(Port_PortPins[channel].Pin_dirChangeable == STD_OFF)
      {
        if(Port_PortPins[channel].direction == INPUT)
         {
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);   /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */ 
          }
        else if(Port_PortPins[channel].direction == OUTPUT)
         {   
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[channel].pin_num);        /* Set the corresponding bit in the GPIODIR register to configure it as output pin */ 
         }
        else
         {
             /* No Action Required */
         }  
      } /*End of end if port direction check to be excluded.*/
      else
      {
        /* No Action Required */
      }  /*End of else  of the if checking the port direction changaeable or not.*/
      
    }/*End of Foor Loop */   
   
 }/*End if error == False */
 
  else
   {
       /* No Action Required */
   }/*End of else of if error is false .*/  
   
} /* end of Port_RefreshPortDirection */



/*******************************************************************************
* Service Name: Port_GetVersionInfo.
* Service ID[hex]: 0x03.
* Sync/Async: Synchronous.
* Reentrancy: Non-Reentrant.
* Parameters (in): None.
* Parameters (inout): None.
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None.
* Description: Function that returns the version information of this module.
*******************************************************************************/

#if (PORT_VERSION_INFO_API == STD_OFF)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  boolean error = FALSE;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port configuration is intialized */
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID ,
		     PORT_E_PARAM_POINTER);
                error = TRUE;
	}
	else
        {
          /* No action required */
        }
     
#endif
  
  if(error == FALSE)
     {
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;               /* set the Id for the company in the AUTOSAR in vendorID */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;               /* set the Port Module Id in the moduleid*/
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION; /* set the Software Major Version Id in the sw_major_version*/
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION; /* set the Software Minor Version Id in the sw_minor_version*/
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION; /* set the Software Patch Version Id in the sw_patch_version*/
 
     } /* end if error == False */ 
  
  
  
} /*end of Port_GetVersionInfo */
#endif
  

/*******************************************************************************
* Service Name: Port_SetPinMode.
* Service ID[hex]: 0x04.
* Sync/Async: Synchronous.
* Reentrancy: Reentrant.
* Parameters (in):Port Pin ID number, New Port Pin mode to be set on port pin.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Function that sets the port pin mode.
*******************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
boolean error = FALSE;
volatile uint32 *PortGpio_Ptr = NULL_PTR;
  
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port configuration is intialized */
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_UNINIT);
                error = TRUE;
	}
	else
        {
          /* No action required */
        }
        /* Check if the used channel is within the valid range */
	if (Pin < PORT_NUMBER_OF_PORT_PINS)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID , PORT_E_PARAM_PIN);
                error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
        if((Mode >  PORT_PIN_MODE_DIO)|| (Mode <  PORT_PIN_MODE_ADC) )
        {
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID , PORT_E_PARAM_INVALID_MODE);
                error = TRUE;
        }
        else
        {
          /* No Action Required */
        }
        if(Port_PortPins[Pin].Pin_modChangeable == STD_OFF)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID , PORT_E_MODE_UNCHANGEABLE);
                error = TRUE;
        }
        else
	{
		/* No Action Required */
	}
#endif
 if(error == FALSE)
  {
        switch(Port_PortPins[Pin].port_num)
       {
         case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	 case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	 case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	 case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
         case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
         case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
       }
       
    if(Mode == PORT_PIN_MODE_DIO)/* Check if the Mode is DIO activated*/
    {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[Pin].pin_num);       /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[Pin].pin_num);              /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_PortPins[Pin].pin_num) * 4));    /* Clear the PMCx bits for this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortPins[Pin].pin_num);          /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
    }
    else if(Mode == PORT_PIN_MODE_ADC)/* Check if the Mode is ADC activated*/
    {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortPins[Pin].pin_num);     /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */  
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[Pin].pin_num);           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_PortPins[Pin].pin_num) * 4)); /* Clear the PMCx bits for this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[Pin].pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */ 
    }
    else if((Mode >  PORT_PIN_MODE_DIO)&&(Mode <  PORT_PIN_MODE_ADC))/* Check if other Modes are activated*/
    {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[Pin].pin_num);            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[Pin].pin_num);                     /* enable Alternative function for this pin by Setting the corresponding bit in GPIOAFSEL register */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((Port_PortPins[Pin].pin_num) * 4));         /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= ((Mode) << ((Port_PortPins[Pin].pin_num) * 4));              /* Set the PMCx bits for this pin to the selected Alternate function in the configurations */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Port_PortPins[Pin].pin_num);                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */ 
    }/* end of else if of remaining modes */
    else
	{
		/* No Action Required */
	}
      
 } /*end of if error == FALSE */

}/*end of Port_SetPinMode */




     
     
     
     
     
     