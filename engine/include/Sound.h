#pragma once

#include <string>

namespace lunk {
	class SoundSample;

	class SoundSampleDeleter {
	public:
		void operator()(SoundSample *);
	};

	class Sound {
	public:
		Sound();

		void initialize();

		void cleanup();

		SoundSample *loadSample(const std::string filename);

		void playSampleOnce(SoundSample *sample);

		void playSampleRepeated(SoundSample *sample);

		void setVolume(double volume);

		void setSampleVolume(SoundSample *sample, double volume);
	};
}