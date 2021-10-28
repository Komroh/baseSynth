/*
  ==============================================================================

    AdsrComponent.h
    Created: 28 Oct 2021 1:10:54am
    Author:  pacau

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent(juce::AudioProcessorValueTreeState& valueTree);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void setSliderParams(juce::Slider& slider);

private:


    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    using SlidderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    std::unique_ptr<SlidderAttachment> attackAttachment;
    std::unique_ptr<SlidderAttachment> decaykAttachment;
    std::unique_ptr<SlidderAttachment> sustainAttachment;
    std::unique_ptr<SlidderAttachment> releasekAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
