#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

using namespace std;

class Display
{
	public:
		Display(int width, int height, const string& title);
		virtual ~Display();

		void Clear(float r, float g, float b, float a);
		void Update();
		bool IsClosed();

	private:
		SDL_Window* m_window;
		SDL_GLContext m_GLContext;
		bool m_IsClosed;

		Display(const Display& other) {}
		Display& operator=(const Display& other) {}
		
};

#endif
