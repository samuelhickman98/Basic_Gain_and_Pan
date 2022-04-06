/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BasicGainandPanPluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener
{
public:
    BasicGainandPanPluginAudioProcessorEditor (BasicGainandPanPluginAudioProcessor&);
    ~BasicGainandPanPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicGainandPanPluginAudioProcessor& audioProcessor;

    juce::Slider mGainSlider;
    juce::Slider mPanSlider;
    
    juce::Label mGainLabel;
    juce::Label mPanLabel;
    
    
    void sliderValueChanged(juce::Slider *slider) override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR
    (BasicGainandPanPluginAudioProcessorEditor)
};
