/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include"UI/AdsrComponent.h"
#include"UI/OscComponent.h"

//==============================================================================
/**
*/
class BaseSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    BaseSynthAudioProcessorEditor (BaseSynthAudioProcessor&);
    ~BaseSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:


    
    juce::Slider gainSlider;
    

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BaseSynthAudioProcessor& audioProcessor;
    AdsrComponent adsrUi;
    OscComponent osc;
    using SlidderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
  
   
    std::unique_ptr<SlidderAttachment> gainAttachment;

   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseSynthAudioProcessorEditor)
};
