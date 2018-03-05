/***************************************************************
 * Name:      LineDrawApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-02-14
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#include "LineDrawApp.h"

//(*AppHeaders
#include "LineDrawMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LineDrawApp);

bool LineDrawApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LineDrawDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
        