#ifndef SSD_CONFIG_H
#define SSD_CONFIG_H



/*Choose SSD Type:   -SSD_COMMON_CATHODE
					 -SSD_COMMON_ANODE
					 */
#define SSD1_TYPE   SSD_COMMON_CATHODE
#define SSD2_TYPE   SSD_COMMON_CATHODE


/*Choose SSD Port:   -GPIO_PortA
					 -GPIO_PortB
					 -GPIO_PortC
					 */
#define SSD1_DATA_PORT  GPIO_PortA
#define SSD2_DATA_PORT  GPIO_PortB

/*Choose SSD PortPosition:   -GPIO_Lower_Byte
					 		 -GPIO_Higher_Byte
					 */
#define SSD1_BYTE  GPIO_Lower_Byte
#define SSD2_BYTE  GPIO_Lower_Byte




#endif