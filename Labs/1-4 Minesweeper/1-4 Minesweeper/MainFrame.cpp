// Lab 1.4 - Minesweeper
// Kevin Moniz

#include "MainFrame.h"

//wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
//wxEND_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Minesweeper.xem", wxPoint(200, 200), wxSize(800, 800)) {
	Buttons = new wxButton * [BoardWidth * BoardHeight];
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxGridSizer* gridSizer = new wxGridSizer(BoardWidth, BoardHeight, 0, 0);
	Mines = new int[BoardWidth * BoardHeight];

	for (int x = 0; x < BoardWidth; x++) {
		for (int y = 0; y < BoardHeight; y++) {
			int index = y * BoardWidth + x;
			Buttons[index] = new wxButton(this, 10000 + index);
			Buttons[index]->SetFont(font);
			gridSizer->Add(Buttons[index], 1, wxEXPAND|wxALL);
			Buttons[index]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnButtonClicked, this);
			Mines[index] = 0;
		}
	}

	this->SetSizer(gridSizer);
	gridSizer->Layout();
}

MainFrame::~MainFrame() {
	delete[] Buttons;
}

void MainFrame::OnButtonClicked(wxCommandEvent &eventName) {
	unsigned int x = (eventName.GetId() - 10000) % BoardWidth;
	unsigned int y = (eventName.GetId() - 10000) / BoardWidth;
	unsigned int index = y * BoardWidth + x;

	if (FirstClick) {
		int mines = BoardWidth * BoardHeight / 3;
		while (mines) {
			int randX = rand() % BoardWidth;
			int randY = rand() % BoardHeight;
			int randIndex = randY * BoardWidth + randX;
			//if (Mines[randIndex] == 0 && randX != x && randY != y) {
			if (Mines[randIndex] == 0 && randIndex != index) {
				Mines[randIndex] = -1;
				mines--;
			}
		}
		FirstClick = false;
	}
	Buttons[index]->Enable(false);

	if (Mines[index] == -1) {
		wxMessageBox("You have died.");
		FirstClick = true;
		for (int x = 0; x < BoardWidth; x++) {
			for (int y = 0; y < BoardHeight; y++) {
				int index = y * BoardWidth + x;
				Mines[index] = 0;
				Buttons[index]->SetLabel("");
				Buttons[index]->Enable(true);
			}
		}
	}
	else {
		int mineCount = 0;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (x + i >= 0 && x + i < BoardWidth && y + j < BoardHeight) {
					if (Mines[(y + j) * BoardWidth + (x + i)] == -1)
						mineCount++;
				}
			}
		}
		if (mineCount > 0) {
			Buttons[index]->SetLabel(std::to_string(mineCount));
		}
	}

	eventName.Skip();
}
