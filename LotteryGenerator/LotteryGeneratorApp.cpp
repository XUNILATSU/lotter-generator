/***************************************************************
 * Name:      LotteryGeneratorApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2024-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#include "LotteryGeneratorApp.h"

//(*AppHeaders
#include "LotteryGeneratorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LotteryGeneratorApp);

bool LotteryGeneratorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LotteryGeneratorFrame* Frame = new LotteryGeneratorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
