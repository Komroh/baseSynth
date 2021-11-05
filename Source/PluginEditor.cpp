/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BaseSynthAudioProcessorEditor::BaseSynthAudioProcessorEditor(BaseSynthAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p), adsrUi(audioProcessor.valueTree), osc(audioProcessor.valueTree, "OSC1")
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);

    
   
    gainAttachment = std::make_unique<SlidderAttachment>(audioProcessor.valueTree, "GAN", gainSlider);

    addAndMakeVisible(adsrUi);
    addAndMakeVisible(osc);
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(gainSlider);

}

BaseSynthAudioProcessorEditor::~BaseSynthAudioProcessorEditor()
{
}

//==============================================================================
void BaseSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);

    
}

void BaseSynthAudioProcessorEditor::resized()
{
    osc.setBounds(10,10,100,30);
    adsrUi.setBounds(getWidth()/2, 0, getWidth()/2, getHeight());
    
    gainSlider.setBounds(80, 60, 20, getLocalBounds().getHeight()/2);
}


