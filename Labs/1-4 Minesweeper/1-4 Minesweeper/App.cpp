// Lab 1.4 - Minesweeper
// Kevin Moniz

#include "App.h"
#include "MainFrame.h"


wxIMPLEMENT_APP(App);


bool App::OnInit() {
	mainFrame = new MainFrame();
	mainFrame->Show();
	return true;
}
