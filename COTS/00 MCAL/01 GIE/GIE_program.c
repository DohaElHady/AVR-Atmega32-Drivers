#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"GIE_interface.h"
#include		"GIE_private.h"

void		GIE_voidEnable(void)
{
	SET_BIT (SREG_REG,GIE_BIT);
}
void		GIE_voidDisable(void)
{
	CLR_BIT (SREG_REG,GIE_BIT);
}
