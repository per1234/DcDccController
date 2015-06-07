//-------------------------------------------------------------------
#ifndef __functionHandle_H__
#define __functionHandle_H__
//-------------------------------------------------------------------

#include "ButtonsCommanderButton.hpp"

//-------------------------------------------------------------------

// This class describes a function handle.

class FunctionHandle
{
	private:
		int functionNumber;
		ButtonsCommanderButton *pButton;

	public:
		FunctionHandle();
		FunctionHandle(int inFunctionNumber, ButtonsCommanderButton *inpButton);
		
		bool Loop();
};

//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------
