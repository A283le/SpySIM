/***************************************************************
 * Name:      SpySIMMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-03-31
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#include "SpySIMMain.h"
#include <wx/msgdlg.h>
#include "wx/wx.h"
#include "wx/sizer.h"
#include <math.h>

//(*InternalHeaders(SpySIMFrame)
#include <wx/string.h>
#include <wx/intl.h>
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

//(*IdInit(SpySIMFrame)
const long SpySIMFrame::ID_BUTTON1 = wxNewId();
const long SpySIMFrame::ID_PANEL1 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT1 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT2 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT3 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT4 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT5 = wxNewId();
const long SpySIMFrame::ID_PANEL2 = wxNewId();
const long SpySIMFrame::ID_RADIOBOX1 = wxNewId();
const long SpySIMFrame::idMenuQuit = wxNewId();
const long SpySIMFrame::idMenuAbout = wxNewId();
const long SpySIMFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SpySIMFrame,wxFrame)
    //(*EventTable(SpySIMFrame)
    //*)
END_EVENT_TABLE()

SpySIMFrame::SpySIMFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SpySIMFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(534,397));
    Button1 = new wxButton(this, ID_BUTTON1, _("Play"), wxPoint(432,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(288,296), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Timer: "), wxPoint(312,72), wxSize(200,17), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Current Floor: "), wxPoint(312,104), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Score: "), wxPoint(320,136), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("How to Play:"), wxPoint(320,168), wxSize(176,144), 0, _T("ID_STATICTEXT4"));
    Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(0,328), wxSize(368,64), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Stats go in here"), wxPoint(128,32), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("Easy"),
    	_("Medium"),
    	_("Hard")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Difficulty"), wxPoint(312,8), wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
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
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpySIMFrame::OnButton1Click);
    Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnRadioBox1Select);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnAbout);
    //*)
}

SpySIMFrame::~SpySIMFrame()
{
    //(*Destroy(SpySIMFrame)
    //*)
}

void SpySIMFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SpySIMFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SpySIMFrame::OnRadioBox1Select(wxCommandEvent& event)
{
    wxSize panel_size = Panel1->GetClientSize();
    int selection = RadioBox1->GetSelection();

    if(selection == 0)
        tile_size = panel_size.GetWidth() / (15 + panel_size.GetWidth()*0.05); // 15 *5
    else if(selection == 1)
        tile_size = panel_size.GetWidth() / (10 + panel_size.GetWidth()*0.05); // 10 *5
    else if(selection == 2)
        tile_size = panel_size.GetWidth() / (5 + panel_size.GetWidth()*0.05); // 5 *5

    Draw(selection);

    // easy     75
    // medium   50
    // hard     25
}

void SpySIMFrame::OnButton1Click(wxCommandEvent& event)
{
}

void SpySIMFrame::Draw(int difficulty)
{
    wxSize panel_size = Panel1->GetClientSize();
    wxPoint *center = new wxPoint(panel_size.GetWidth()/2,panel_size.GetHeight()/2);
    wxPoint *bob = new wxPoint(*center);
    bob->x += tile_size;
    bob->y += tile_size;

    DrawIsoSquare(*center);
    DrawIsoSquare(*bob);
}

void SpySIMFrame::DrawIsoSquare(wxPoint& point)
{
    wxClientDC dc(Panel1);
    dc.Clear();
    dc.SetBrush(*wxBLACK_BRUSH);

    wxSize panel_size = Panel1->GetClientSize();
    wxPoint *center = new wxPoint(point);
    wxPoint *slave = new wxPoint(*center);
    slave->x += tile_size;
    dc.DrawLine(*center,*slave);

    wxPoint *center2 = new wxPoint(*center);
    center2->y -= tile_size * 0.5; // 0.5 is sin(30 degrees)
    center2->x += tile_size * 0.86602540378443864676372317075294; // cosine of 30 degrees

    dc.DrawLine(*center,*center2);

    wxPoint *center3 = new wxPoint(*slave);
    center3->y -= tile_size * 0.5; // 0.5 is sin(30 degrees)
    center3->x += tile_size * 0.86602540378443864676372317075294; // cosine of 30 degrees

    dc.DrawLine(*slave,*center3);
    dc.DrawLine(*center2,*center3);
}
