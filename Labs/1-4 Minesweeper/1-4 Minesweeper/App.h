// Lab 1.4 - Minesweeper
// Kevin Moniz

#pragma once
#include "wx/wx.h"

class MainFrame;

class App : public wxApp
{

private:
	MainFrame* mainFrame;

public:
	virtual bool OnInit();

};
