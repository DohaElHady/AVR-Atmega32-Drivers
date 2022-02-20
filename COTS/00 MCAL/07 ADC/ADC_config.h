#ifndef		ADC_CONFIG_H
#define		ADC_CONFIG_H

/*********************************************************************/
/*		Vref Can be :		 							   */
/*							ADC_AVCC							 */
/*							ADC_INTERNAL				   */
/*							ADC_AREF							 */
/*********************************************************************/

#define		ADC_VOLTAGE_REF						ADC_AVCC

/*********************************************************************/
/*																	     */
/*		ADC_PRESCALLER Can be :		 		     */
/*							ADC_DIV_2							   */
/*							ADC_DIV_4							   */
/*							ADC_DIV_8							   */
/*							ADC_DIV_16							 */
/*							ADC_DIV_32							 */
/*							ADC_DIV_64							 */
/*							ADC_DIV_128							 */

/*********************************************************************/

#define		ADC_PRESCALLER						ADC_DIV_128

#endif
