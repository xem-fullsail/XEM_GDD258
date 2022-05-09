// Lab 1.4 - Minesweeper
// Kevin Moniz

#pragma once
#include "wx/wx.h"


class MainFrame : public wxFrame
{

public:
	MainFrame();
	~MainFrame();

	unsigned int BoardWidth = 10;
	unsigned int BoardHeight = 10;
	wxButton** Buttons;
	int* Mines = nullptr;
	bool FirstClick = true;

	void OnButtonClicked(wxCommandEvent& eventName);

};
