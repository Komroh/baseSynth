/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BaseSynthAudioProcessorEditor::BaseSynthAudioProcessorEditor(BaseSynthAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);

    using SlidderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using ComboBoxAttachment = juce::AudioProcessorValueTreeState::ComboBoxAttachment;
    oscAttachment = std::make_unique<ComboBoxAttachment>(audioProcessor.valueTree, "OSC", oscSelector);
    attackAttachment = std::make_unique<SlidderAttachment>(audioProcessor.valueTree, "ATK", attackSlider);
    decaykAttachment = std::make_unique<SlidderAttachment>(audioProcessor.valueTree, "DEC", decaySlider);
    sustainAttachment = std::make_unique<SlidderAttachment>(audioProcessor.valueTree, "SUS", sustainSlider);
    releasekAttachment = std::make_unique<SlidderAttachment>(audioProcessor.valueTree, "REL", releaseSlider);
    gainAttachment = std::make_unique<SlidderAttachment>(audioProcessor.valueTree, "GAN", gainSlider);

    setSliderParams(attackSlider);
    setSliderParams(decaySlider);
    setSliderParams(sustainSlider);
    setSliderParams(releaseSlider);
    setSliderParams(gainSlider);
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
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 5 - padding;
    const auto sliderHeight = bounds.getWidth() / 5 - padding;
    const auto sliderStartX = 0;
    const auto sliderStartY = bounds.getHeight() / 2 - (sliderHeight / 2);
    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    gainSlider.setBounds(releaseSlider.getRight() + (2*padding), sliderStartY, sliderWidth, sliderHeight);
}

void BaseSynthAudioProcessorEditor::setSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}
