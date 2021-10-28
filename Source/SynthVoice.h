/*
  ==============================================================================

    SynthVoice.h
    Created: 14 Oct 2021 12:34:13pm
    Author:  pacau

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"

#include "AdsrData.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
    void updateGain(const float gain);
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;
    

private :
    juce::dsp::Oscillator<float> osc{ [](float x) { return std::sin(x); } };
    juce::dsp::Gain<float> voiceGain;
    int totalNumOutputChannels;
    AdsrData adsr;
    
    juce::AudioBuffer<float> oscBuffer;
    bool isPrepared{ false };
};