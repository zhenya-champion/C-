#pragma once
#include <iostream>

using namespace std;

class Dialog :
	public Dialog
{
public:
	Dialog(void);
public:
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent (TEvent& event); 
	virtual void ClearEvent (TEvent& event);
	int Valid();

	void EndExec();
protected:
	int EndState;
};

