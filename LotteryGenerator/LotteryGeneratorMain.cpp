/***************************************************************
 * Name:      LotteryGeneratorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2024-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#include "LotteryGeneratorMain.h"
#include <wx/msgdlg.h>
#include <ctime>
#include <cstdlib>
#include <set>
//(*InternalHeaders(LotteryGeneratorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(LotteryGeneratorFrame)
const long LotteryGeneratorFrame::ID_STATICTEXT1 = wxNewId();
const long LotteryGeneratorFrame::ID_TEXTCTRL1 = wxNewId();
const long LotteryGeneratorFrame::ID_BUTTON1 = wxNewId();
const long LotteryGeneratorFrame::ID_BUTTON2 = wxNewId();
const long LotteryGeneratorFrame::ID_TEXTCTRL2 = wxNewId();
const long LotteryGeneratorFrame::ID_TEXTCTRL3 = wxNewId();
const long LotteryGeneratorFrame::ID_TEXTCTRL4 = wxNewId();
const long LotteryGeneratorFrame::ID_TEXTCTRL5 = wxNewId();
const long LotteryGeneratorFrame::ID_TEXTCTRL6 = wxNewId();
const long LotteryGeneratorFrame::idMenuQuit = wxNewId();
const long LotteryGeneratorFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(LotteryGeneratorFrame,wxFrame)
    //(*EventTable(LotteryGeneratorFrame)
    //*)
END_EVENT_TABLE()

LotteryGeneratorFrame::LotteryGeneratorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(LotteryGeneratorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(422,450));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Mega Millions"), wxPoint(24,8), wxSize(160,28), 0, _T("ID_STATICTEXT1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,64), wxSize(24,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Generate"), wxPoint(296,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Clear"), wxPoint(296,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(48,64), wxSize(24,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(80,64), wxSize(24,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(112,64), wxSize(24,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(144,64), wxSize(24,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(176,64), wxSize(24,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LotteryGeneratorFrame::OnTextCtrl1Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LotteryGeneratorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LotteryGeneratorFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LotteryGeneratorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LotteryGeneratorFrame::OnAbout);
    //*)
}

LotteryGeneratorFrame::~LotteryGeneratorFrame()
{
    //(*Destroy(LotteryGeneratorFrame)
    //*)
}

void LotteryGeneratorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void LotteryGeneratorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void LotteryGeneratorFrame::OnButton1Click(wxCommandEvent& event)
{
   /* int randomNumber = std::rand() % 70 + 1;
    int randomNumber2 = std::rand() % 70 + 1;
    int randomNumber3 = std::rand() % 70 + 1;
    int randomNumber4 = std::rand() % 70 + 1;
    int randomNumber5 = std::rand() % 70 + 1;
    int randomNumber6 = std::rand() % 25 + 1;
    TextCtrl1->SetValue(wxString::Format(wxT("%d"), randomNumber));
    TextCtrl2->SetValue(wxString::Format(wxT("%d"), randomNumber2));
    TextCtrl3->SetValue(wxString::Format(wxT("%d"), randomNumber3));
    TextCtrl4->SetValue(wxString::Format(wxT("%d"), randomNumber4));
    TextCtrl5->SetValue(wxString::Format(wxT("%d"), randomNumber5));
    TextCtrl6->SetValue(wxString::Format(wxT("%d"), randomNumber6));*/
     std::set<int> generatedNumbers;

    while (generatedNumbers.size() < 5) {
        int randomNumber = std::rand() % 70 + 1;
        generatedNumbers.insert(randomNumber);
    }


        int powerBall = std::rand() % 25 + 1;
        generatedNumbers.insert(powerBall);


    std::set<int>::iterator it = generatedNumbers.begin();

    TextCtrl1->SetValue(wxString::Format(wxT("%d"), *it++));
    TextCtrl2->SetValue(wxString::Format(wxT("%d"), *it++));
    TextCtrl3->SetValue(wxString::Format(wxT("%d"), *it++));
    TextCtrl4->SetValue(wxString::Format(wxT("%d"), *it++));
    TextCtrl5->SetValue(wxString::Format(wxT("%d"), *it++));
    TextCtrl6->SetValue(wxString::Format(wxT("%d"), powerBall));
}

void LotteryGeneratorFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void LotteryGeneratorFrame::OnButton2Click(wxCommandEvent& event)
{
    TextCtrl1->Clear();
}
