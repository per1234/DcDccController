//-------------------------------------------------------------------
#ifndef __potentiometer_H__
#define __potentiometer_H__
//-------------------------------------------------------------------

#ifdef VISUALSTUDIO
#include "VStudioLcdUI\arduino2.hpp"
#else
#include "arduino2.hpp"
#endif
#include "ButtonsCommanderButton.hpp"

//-------------------------------------------------------------------

#define POTENTIOMETER(list, nb)	((ButtonsCommanderPotentiometer *) list[nb])

class ButtonsCommanderPotentiometer : public ButtonsCommanderButton
{
 private:
	int currentValue;
	int pin;
	int moveAccuracy;
	int mini, maxi;
	
 public:
	ButtonsCommanderPotentiometer(int inMinimum, int inMaximum);

	inline bool IsAnalog() const { return true; }
	inline int GetPosition() const { return this->currentValue; }

	void Setup(int inPin, int inMoveAccuracy = 1);
	void SetMinMax(int inMini, int inMaxi) { this->mini = inMini; this->maxi = inMaxi; }
	bool Loop();
};

//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------