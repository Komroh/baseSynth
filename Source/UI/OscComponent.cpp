/*
  ==============================================================================

    OscComponent.cpp
    Created: 5 Nov 2021 2:01:17am
    Author:  pacau

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& valueTree, juce::String waveSelectorId)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    juce::StringArray choices{ "Sine", "Saw", "Square" };
    oscSelector.addItemList(choices, 1);
    using ComboBoxAttachment = juce::AudioProcessorValueTreeState::ComboBoxAttachment;
    oscAttachment = std::make_unique<ComboBoxAttachment>(valueTree, waveSelectorId, oscSelector);
    addAndMakeVisible(oscSelector);
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll(juce::Colours::black);
}

void OscComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    oscSelector.setBounds(0, 0, 90, 20);

}
