/***************************************************************
 * Name:      SpySIMMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-03-31
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#ifndef SPYSIMMAIN_H
#define SPYSIMMAIN_H

//(*Headers(SpySIMFrame)
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

class SpySIMFrame: public wxFrame
{
    public:

        SpySIMFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SpySIMFrame();

    private:

        //(*Handlers(SpySIMFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(SpySIMFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(SpySIMFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SPYSIMMAIN_H
    