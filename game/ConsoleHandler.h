#pragma once

#include <thread>
#include <iostream>
#include <string>
#include "World.h"


class ConsoleHandler {
public:
	ConsoleHandler(World *world) {
		std::thread{[&]() {
			while (!started) {
				std::this_thread::yield();
			}

			while (!stopped) {
				std::string cmd;
				int n;
				std::cin >> cmd;

				//Insert commands here
			}
		}}.detach();
	}

	void start() {
		started = true;
	}

	void stop() {
		stopped = true;
	}


private:
	bool started = false;
	bool stopped = false;
};