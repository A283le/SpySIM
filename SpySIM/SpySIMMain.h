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
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
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
        void OnRadioBox1Select(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)
        void Draw(int difficulty);
        void DrawIsoGrid(wxPoint& point);
        void DrawIsoRow(wxPoint& point, int difficulty);
        void DrawIsoSquare(wxPoint& point);

        void KeyMove(wxKeyEvent& event);


        //(*Identifiers(SpySIMFrame)
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_PANEL2;
        static const long ID_RADIOBOX1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        int tile_size, num_tiles;
        wxPoint *player;

        //(*Declarations(SpySIMFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxRadioBox* RadioBox1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SPYSIMMAIN_H
