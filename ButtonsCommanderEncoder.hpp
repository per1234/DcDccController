//-------------------------------------------------------------------
#ifndef __buttonsCommanderEncoder_H__
#define __buttonsCommanderEncoder_H__
//-------------------------------------------------------------------

#ifdef UAD_VC
#include "VStudio/arduino2.hpp"
#else
#include "arduino2.hpp"
#endif
#include "ButtonsCommanderPush.hpp"

//-------------------------------------------------------------------

#define ENCODER(list, nb)	((ButtonsCommanderEncoder *) list[nb])

class ButtonsCommanderEncoder : public ButtonsCommanderButton
{
 private:
	int currentValue;
	GPIO_pin_t pin1;
	GPIO_pin_t pin2;
	int moveAccuracy;
	int mini, maxi;
	int lastEncoded;
	bool lastWasPositive;	// true : positive direction...

	bool pin1Set;
	bool pin2Set;

public:
	ButtonsCommanderPush *pPush;
	
 public:
	ButtonsCommanderEncoder(int inStartingCurrentValue, int inMinimum, int inMaximum);

	inline bool IsAnalog() const { return true; }
	inline int GetPosition() const { return this->currentValue; }
	inline int GetEncoded() const { return this->lastEncoded; }
	inline bool WasLastPositive() const { return this->lastWasPositive; }

	void Setup(int inPin1, int inPin2, int inMoveAccuracy = 1);
	void SetMinMax(int inMini, int inMaxi) { this->mini = inMini; this->maxi = inMaxi; }
	bool Loop();
};

//-------------------------------------------------------------------

//===================================================================
// -> DO NOT WRITE ANYTHING BETWEEN HERE...
// 		This section is reserved for automated code generation
// 		This process tries to detect all user-created
// 		functions in main_sketch.cpp, and inject their  
// 		declarations into this file.
// 		If you do not want to use this automated process,  
//		simply delete the lines below, with "&MM_DECLA" text 
//===================================================================
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_BEG@---------------------
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_END@---------------------
// -> ...AND HERE. This space is reserved for automated code generation!
//===================================================================


//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------