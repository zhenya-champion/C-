#pragma once

#include <iostream>
class Object
{
public:
	Object(void);
	virtual void Show() = 0; virtual void Input() = 0; virtual ~Object(void);
};
class Object
{

	virtual void HandleEvent(const TEvent& e) = 0;
};

