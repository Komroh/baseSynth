/*
  ==============================================================================

    SynthSound.h
    Created: 14 Oct 2021 12:35:26pm
    Author:  Pacaud Maxime

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


 class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override{ return true; }
    bool appliesToChannel(int midiChannel) override { return true; }

private:

};

