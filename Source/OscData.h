/*
  ==============================================================================

    OscData.h
    Created: 4 Nov 2021 2:02:00am
    Author:  pacau

  ==============================================================================
*/

#pragma once
#include<JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay(juce::dsp::ProcessSpec spec);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& audioBlock);
    void setWaveFrequency(const int midiMessage);
    void setWaveType(const int choice);
private:
};