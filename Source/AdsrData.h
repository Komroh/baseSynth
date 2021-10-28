/*
  ==============================================================================

    AdsrData.h
    Created: 28 Oct 2021 1:12:01am
    Author:  pacau

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public :
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
    
private :
    juce::ADSR::Parameters adsrParams;
};