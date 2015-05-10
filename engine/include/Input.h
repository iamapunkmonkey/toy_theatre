#pragma once

namespace lunk {
	class Vec2;

	enum class Key {
		UNKNOWN = 0,
		RETURN = '\r',
		ESCAPE = '\033',
		BACKSPACE = '\b',
		TAB = '\t',
		SPACE = ' ',
		EXCLAIM = '!',
		QUOTEDBL = '"',
		HASH = '#',
		PERCENT = '%',
		DOLLAR = '$',
		AMPERSAND = '&',
		QUOTE = '\'',
		LEFTPAREN = '(',
		RIGHTPAREN = ')',
		ASTERISK = '*',
		PLUS = '+',
		COMMA = ',',
		MINUS = '-',
		PERIOD = '.',
		SLASH = '/',
		NUM_0 = '0',
		NUM_1 = '1',
		NUM_2 = '2',
		NUM_3 = '3',
		NUM_4 = '4',
		NUM_5 = '5',
		NUM_6 = '6',
		NUM_7 = '7',
		NUM_8 = '8',
		NUM_9 = '9',
		COLON = ':',
		SEMICOLON = ';',
		LESS = '<',
		EQUALS = '=',
		GREATER = '>',
		QUESTION = '?',
		AT = '@',
		LEFTBRACKET = '[',
		BACKSLASH = '\\',
		RIGHTBRACKET = ']',
		CARET = '^',
		UNDERSCORE = '_',
		BACKQUOTE = '`',
		A = 'a',
		B = 'b',
		C = 'c',
		D = 'd',
		E = 'e',
		F = 'f',
		G = 'g',
		H = 'h',
		I = 'i',
		J = 'j',
		K = 'k',
		L = 'l',
		M = 'm',
		N = 'n',
		O = 'o',
		p = 'p',
		Q = 'q',
		R = 'r',
		S = 's',
		T = 't',
		U = 'u',
		V = 'v',
		W = 'w',
		X = 'x',
		Y = 'y',
		Z = 'z',
		RIGHT = 1073741903,
		LEFT = 1073741904,
		DOWN = 1073741905,
		UP = 1073741906
	};

	enum class MouseButton {
		LEFT, MIDDLE, RIGHT, NONE
	};

	class Input {
	public:
		virtual Vec2 getMousePosition() = 0;

		virtual bool keyWasPressed(Key key) = 0;

		virtual bool keyWasReleased(Key key) = 0;

		virtual bool keyIsDown(Key key) = 0;

		virtual bool mouseButtonIsDown(MouseButton button) = 0;

		virtual bool windowClosedRequest() = 0;

		virtual void update() = 0;

		virtual ~Input() { }
	};
}