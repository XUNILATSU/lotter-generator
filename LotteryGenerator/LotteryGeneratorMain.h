/***************************************************************
 * Name:      LotteryGeneratorMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2024-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef LOTTERYGENERATORMAIN_H
#define LOTTERYGENERATORMAIN_H

//(*Headers(LotteryGeneratorFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class LotteryGeneratorFrame: public wxFrame
{
    public:

        LotteryGeneratorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~LotteryGeneratorFrame();

    private:

        //(*Handlers(LotteryGeneratorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(LotteryGeneratorFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        //(*Declarations(LotteryGeneratorFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl6;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LOTTERYGENERATORMAIN_H
