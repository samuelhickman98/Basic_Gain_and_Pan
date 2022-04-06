/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicGainandPanPluginAudioProcessorEditor::BasicGainandPanPluginAudioProcessorEditor (BasicGainandPanPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 400);
    
    mPanSlider.setSliderStyle(juce::Slider::LinearVertical);
    mPanSlider.setRange(0.0, 1.0);
    mPanSlider.setValue(0.5);
    addAndMakeVisible(&mPanSlider);
    mPanSlider.addListener(this);
    
    mGainSlider.setSliderStyle(juce::Slider::LinearVertical);
    mGainSlider.setRange(0.0, 1.0);
    mGainSlider.setValue(0.5);
    addAndMakeVisible(&mGainSlider);
    mGainSlider.addListener(this);
    
    addAndMakeVisible(&mGainLabel);
    mGainLabel.setText("Gain", juce::dontSendNotification);
    mGainLabel.attachToComponent(&mGainSlider, true);
    mGainLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    mGainLabel.setJustificationType(juce::Justification::centredTop);
    
    addAndMakeVisible(&mPanLabel);
    mPanLabel.setText("Pan", juce::dontSendNotification);
    mPanLabel.attachToComponent(&mPanSlider, true);
    mPanLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    mPanLabel.setJustificationType(juce::Justification::centredTop);
}

BasicGainandPanPluginAudioProcessorEditor::~BasicGainandPanPluginAudioProcessorEditor()
{
    mGainSlider.removeListener(this);
    mPanSlider.removeListener(this);
}

void BasicGainandPanPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if(slider == &mPanSlider)
    {
   audioProcessor.mPanSliderValue = mPanSlider.getValue();
    }
    else if(slider == &mGainSlider)
    {
    audioProcessor.mGainSliderValue = mGainSlider.getValue();
}
}

//==============================================================================
void BasicGainandPanPluginAudioProcessorEditor::paint (juce::Graphics& g)
    {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::grey);

    g.setColour (juce::Colours::black);
    g.setFont (30.0f);
    g.drawFittedText ("Sam Hickman's Gain & Pan", getLocalBounds(), juce::Justification::centred, 1);
    }

void BasicGainandPanPluginAudioProcessorEditor::resized()
    {
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mGainSlider.setBounds(50, 150, 100, 200);
    mPanSlider.setBounds(600, 150, 100, 200);
    }

