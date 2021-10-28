/*
  ==============================================================================

    AdsrData.cpp
    Created: 28 Oct 2021 1:12:01am
    Author:  pacau

  ==============================================================================
*/

#include "AdsrData.h"


void AdsrData::updateADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;
    setParameters(adsrParams);
}