#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "pMixAudioEngine.h"

class PMixPluginAudioProcessor  : public AudioProcessor
{
public:

  PMixPluginAudioProcessor();
  ~PMixPluginAudioProcessor();

  void prepareToPlay (double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

  void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

  AudioProcessorEditor* createEditor() override;
  bool hasEditor() const override;

  const String getName() const override;

  int getNumParameters() override;
  float getParameter (int index) override;
  void setParameter (int index, float newValue) override;

  const String getParameterName (int index) override;
  const String getParameterText (int index) override;

  const String getInputChannelName (int channelIndex) const override;
  const String getOutputChannelName (int channelIndex) const override;
  bool isInputChannelStereoPair (int index) const override;
  bool isOutputChannelStereoPair (int index) const override;

  bool acceptsMidi() const override;
  bool producesMidi() const override;
  bool silenceInProducesSilenceOut() const override;
  double getTailLengthSeconds() const override;

  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram (int index) override;
  const String getProgramName (int index) override;
  void changeProgramName (int index, const String& newName) override;

  void getStateInformation (MemoryBlock& destData) override;
  void setStateInformation (const void* data, int sizeInBytes) override;
  
  PMixAudioEngine& getAudioEngine() { return audioEngine; }
  
private:
  PMixAudioEngine audioEngine;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PMixPluginAudioProcessor)
};



#endif  // PLUGINPROCESSOR_H_INCLUDED
