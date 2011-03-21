#include "Mainframe.h"

#ifdef WIN32
#include <shlobj.h>
#endif

#include <wx/menuitem.h>
#include <wx/mimetype.h>
#include <wx/filefn.h>
#include <wx/stdpaths.h>

//#include "redirect.h"

#include "AdvancedModePanel.h"
#include "SimpleModePanel.h"
#include "AvailabilityModePanel.h"
#include "RTTPacketlossModePanel.h"
#include "ThroughputModePanel.h"
#include "ReportDialog.h"
#include "RepeatDialog.h"
#include "HistorySettingDialog.h"

// Tills vidare
wxChar *error_messages[] = {			     \
  wxT("Kontrollkanalen st�ngdes ov�ntat"),	     \
  wxT("M�tningen tog f�r l�ng tid och avslutades"),  \
  wxT("Kunde inte �ppna kontrollkanalen"),	     \
  wxT("Kunde inte tolka svar fr�n servern"),	     \
  wxT("Kunde inte tolka svar fr�n servern"),	     \
  wxT("Servern avbr�t m�tningen"),		     \
  wxT("Felaktig typ av m�tning"),		     \
  wxT("Kunde ej genomf�ra NAT-�ppning"),	     \
  wxT("Kunde ej �ppna UDP socket"),		     \
  wxT("M�tningen avslutades av anv�ndaren"),	     \
  wxT("Masterservern �r upptagen"),		     \
  wxT("Kunde ej tolka svar fr�n masterservern"),     \
  wxT("Masterservern nekade oss uppkoppling"),	     \
  wxT("Felaktigt autenticeringsv�rde"),		     \
  wxT("NAT-�ppning misslyckades"),		     \
  wxT("Kunde ej �ppna TCP-socket f�r testdata"),	 \
  wxT("Kunde ej ansluta TCP-f�rbindelse f�r testdata"),	    \
  wxT("F�r m�nga m�tservrar i svaret fr�n masterservern"),  \
  wxT("M�tserver har inget namn"),			    \
  wxT("M�tserver anv�nder ok�nt protokoll"),		    \
  wxT("Kunde ej sl� upp IP-adress f�r m�tserver"),	    \
  wxT("Kunde ej ansluta till m�tserver"),		    \
  wxT("Felaktigt v�lkomstmeddelande fr�n m�tserver"),	    \
  wxT("Felaktigt autenticeringsv�rde"),			    \
  wxT("Inget autenticeringsv�rde"),			    \
  wxT("M�ttypen accepteras inte av m�tservern"),	    \
  wxT("Ingen eller felaktig m�ttyp"),			    \
  wxT("M�ttid saknas"),					    \
  wxT("Antal datapaket i m�tningen saknas"),		    \
  wxT("Paketstorlek saknas"),				    \
  wxT("Ingen UDP-s�ndport angiven i svar fr�n m�tserver"),	   \
  wxT("Ingen UDP-mottagningsport angiven i svar fr�n m�tserver"),  \
  wxT("Timeout-parameter saknas f�r m�tning"),			   \
  wxT("Antal TCP bytes att �verf�ra saknas"),			   \
  wxT("M�tservern �r upptagen"),				   \
  wxT("M�tservern nekade m�tning"),				   \
  wxT("Kunde ej initiera namnuppslagning"),			   \
  wxT("Namnuppslagning misslyckades"),				   \
  wxT("Dataf�rbindelsen st�ngdes ov�ntat"),			   \
  wxT("Kunde ej ta emot inkommande TCP-f�rbindelse"),		   \
  wxT("Felaktigt TEST-kommando"),				   \
  wxT("Klienten avbr�t m�tningen"),				   \
  wxT("Utbyte av m�tresultat misslyckades"),	\
  wxT("")					\
} ; 




BEGIN_EVENT_TABLE( MainFrame, wxFrame )
	EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
	EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
	EVT_MENU(wxID_MENU_SERVERLIST, MainFrame::OnEditServerList)
	EVT_MENU(wxID_TOGGLE_MODE, MainFrame::OnToggleMode)
	EVT_MENU(wxID_MENU_REPORT, MainFrame::OnReport)
	EVT_MENU(wxID_MENU_REPEAT, MainFrame::OnRepeat)
	EVT_MENU(wxID_MENU_HISTORY, MainFrame::OnHistorySetting)
	EVT_MENU(wxID_MENU_EXPORT_STANDARD, MainFrame::OnExportStandard)
	EVT_MENU(wxID_MENU_EXPORT_AVAILABILITY, MainFrame::OnExportAvailability)
	EVT_MENU(wxID_MENU_EXPORT_RTTPACKETLOSS, MainFrame::OnExportRTTPacketloss)
	EVT_MENU(wxID_MENU_EXPORT_THROUGHPUT, MainFrame::OnExportThroughput)
	EVT_MENU(wxID_MENU_PREFERENCES, MainFrame::OnPreferences)
	EVT_MENU(wxID_HELP, MainFrame::OnManual)

	EVT_TIMER(wxID_MAIN_TIMER, MainFrame::OnTimer)
	EVT_TIMER(wxID_REPEAT_TIMER, MainFrame::OnRepeatTimer)
END_EVENT_TABLE()

MainFrame* MainFrame::s_Instance = 0;

#ifdef WIN32
#define MFRAME_W 700
#define MFRAME_H 550
#define DISABLE_RESIZE & ~ (wxRESIZE_BORDER | wxRESIZE_BOX)
#endif
#ifdef UNIX
#define MFRAME_W 685
#define MFRAME_H 490
#define DISABLE_RESIZE
#endif


MainFrame::MainFrame(TheApp *theapp)
  :wxFrame( NULL, wxID_MAINFRAME, wxT("TPTEST 5.0"), 
	    wxDefaultPosition, wxSize( MFRAME_W, MFRAME_H ), 
			wxMINIMIZE_BOX | 
			wxCLOSE_BOX | 
			wxSIMPLE_BORDER | 
			wxSYSTEM_MENU |
			wxCAPTION |
			wxCLIP_CHILDREN |
	        wxFRAME_EX_METAL DISABLE_RESIZE )
{
	MainFrame::s_Instance = this;

	m_PanelMain = NULL;

	m_app = theapp;

	m_timer = new wxTimer(this, wxID_MAIN_TIMER);
	m_timerRepeat = new wxTimer(this, wxID_REPEAT_TIMER);

// Init member variables

	m_RepeatActive = false;
	m_Mode = MODE_SIMPLE;

    m_AdvancedPanel = new AdvancedModePanel( this );
	m_SimplePanel = new SimpleModePanel( this );
	m_dlgReport = new ReportDialog(this);

    m_AdvancedPanel->Show(false);
	m_SimplePanel->Show(false);
	m_dlgReport->Show(false);

	/*
wxMemoryInputStream istream(myimage_png, sizeof myimage_png);
  wxImage myimage_img(istream, wxBITMAP_TYPE_PNG);
*/


// Create the GUI controls

	m_menuFile = new wxMenu();
	m_menuConf = new wxMenu();
	m_menuHelp = new wxMenu();

	m_menuFile_Export = new wxMenu();

	m_menuHelp->Append(	wxID_HELP, 
				wxT("M&anual\tF1"),
				wxT("Visa dokumentation f�r programmet"));

	m_menuHelp->Append(	wxID_ABOUT, 
				wxT("O&m TPTest 5\tF2"),
				wxT("Visa information om programmet"));

	m_menuFile->AppendCheckItem(	wxID_TOGGLE_MODE,
						wxT("A&vancerat l�ge\tAlt-A"),
						wxT("Skifta mellan Avancerat och Standard l�ge"));

	m_menuConf->Append(	wxID_MENU_HISTORY,
						wxT("H&istorik\tAlt-H"),
						wxT("Inst�llningar f�r m�tv�rdeshistorik"));

	m_menuConf->Append(	wxID_MENU_REPEAT,
						wxT("R&epetera\tAlt-P"),
						wxT("St�ll in hur ofta du vill repetera ett test"));

	m_menuConf->Append(	wxID_MENU_SERVERLIST,
						wxT("S&erverlistan\tAlt-S"),
						wxT("Editera Serverlistan"));


#ifdef MACOSX
	m_menuConf->Append(	wxID_MENU_PREFERENCES,
						wxT("I&nst�llningar\tAlt-N"),
						wxT("Inst�llningar"));
#endif

	wxMenuItem *miExport = new wxMenuItem( m_menuFile, wxID_MENU_EXPORT, wxT("Exportera resultat"), wxT("Spara resultat som fil") );
	miExport->SetSubMenu( m_menuFile_Export );

	m_menuFile->Append(	miExport );

	m_menuFile->AppendSeparator();

	m_menuFile->Append(	wxID_MENU_REPORT,
				wxT("R&apport\tAlt-R"),
				wxT("Unders�ker din dator och rapporterar status"));
	
	m_menuFile->AppendSeparator();
	
	m_menuFile->Append(	wxID_EXIT,
				wxT("A&vsluta\tAlt-X"),
				wxT("Avsluta programmet"));
	
	// Export menu
	m_menuFile_Export->Append(wxID_MENU_EXPORT_STANDARD,
				  wxT("E&nkelt l�ge\tAlt-1"),
				  wxT(""));
	
	m_menuFile_Export->Append(
				  wxID_MENU_EXPORT_AVAILABILITY,
				  wxT("T&illg�nglighet\tAlt-2"),
						wxT(""));

	m_menuFile_Export->Append(
						wxID_MENU_EXPORT_RTTPACKETLOSS,
						wxT("S&varstider och paketf�rluster\tAlt-3"),
						wxT(""));

	m_menuFile_Export->Append(
						wxID_MENU_EXPORT_THROUGHPUT,
						wxT("G&enomstr�mning\tAlt-4"),
						wxT(""));


	m_menuBar = new wxMenuBar();
	m_menuBar->Append( m_menuFile, wxT("&Arkiv"));
	m_menuBar->Append( m_menuConf, wxT("A&lternativ"));
	m_menuBar->Append( m_menuHelp, wxT("&Hj�lp"));

	SetMenuBar(m_menuBar); 

	m_PanelMain =  m_SimplePanel;
	m_PanelMain->Show(true);

	// The main sizer that sets the size of the main panel
	m_SizerMain = new wxBoxSizer( wxVERTICAL );

	m_SizerMain->Add(	m_PanelMain,
				1,
				wxEXPAND | wxALL,
				0 );

    this->SetSizer( m_SizerMain );

}

MainFrame::~MainFrame(void)
{
  delete m_timer;
  delete m_timerRepeat;
}

// event handlers
void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true is to force the frame to close
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	DialogAbout dlg( this );
	dlg.ShowModal();
}

void MainFrame::OnToggleMode(wxCommandEvent& event)
{
	if( m_timerRepeat->IsRunning() )
	{
	  wxMessageBox( wxT("Du kan inte �ndra mellan enkelt och avancerat l�ge n�r repeterade tester utf�rs") );
	  return;
	}

	m_PanelMain->Show(false);

	m_SizerMain->Detach( m_PanelMain );

	if( m_Mode == MODE_SIMPLE )
	{
		// Because we have two different instances of SimpleModePanel
		m_AdvancedPanel->m_PageSimple->RefreshResultList();
		m_AdvancedPanel->m_PageSimple->RefreshSettingsList();
		m_PanelMain = m_AdvancedPanel;
		m_Mode = MODE_ADVANCED;
	}
	else
	{
		// Because we have two different instances of SimpleModePanel
		m_SimplePanel->RefreshResultList();
		m_SimplePanel->RefreshSettingsList();
		m_PanelMain = m_SimplePanel;
		m_Mode = MODE_SIMPLE;
	}

	m_PanelMain->Show(true);

	m_SizerMain->Add( m_PanelMain,
			  1,
			  wxEXPAND | wxALL,
			  0 );

    this->SetSizer( m_SizerMain );

	m_SizerMain->SetMinSize( m_PanelMain->GetSize() );
	m_SizerMain->Fit( this );
}



void MainFrame::OnTimer( wxTimerEvent& event )
{
	TestMarshall *tm = TestMarshall::GetInstance();
	const char *cstr = tm->GetProgressString();

	bool Ok =
		this->m_dlgProgress->Update( tm->GetProgress(), 
									  FROMCSTR(cstr) );

	if( tm->GetCompletedStatus() || !Ok )
	{
		this->m_timer->Stop();

		if( tm->GetLastError() > 0 )
		{
			this->PostTest();
			wxString msg;
			if( tm->GetLastError() >= 2001 && tm->GetLastError() <= 2043 )
			  msg << error_messages[tm->GetLastError()-2001] << wxT("\n\n");

			msg << wxT("Felkod: ") << tm->GetLastError() << wxT("\n");
			msg << wxT("(") << wxString(tm->GetProgressString(), wxConvUTF8) << wxT(")");
			wxMessageBox( msg, wxString( wxT("Ett fel har uppst�tt") ) );
		}
		else
		{
		  this->m_dlgProgress->Update( tm->GetProgress(), wxT("V�nligen v�nta (detta kan ta upp till en minut)...") );
		  this->m_dlgProgress->SetTitle( wxT("Avslutar test") );

			this->m_resultfunc( this->m_ResultPageInstance, !Ok );

			if( Ok )
			{
				ResultLog *rlog = ResultLog::GetInstance();
				rlog->SaveResults();
			}

			this->PostTest();
		}


		if( !Ok )
		{
			this->AbortRepeatTimer();
		}
	}
}

void MainFrame::OnRepeatTimer( wxTimerEvent& event )
{
	AppConfig *ac = AppConfig::GetInstance();
	wxString rep_ena;
	wxString rep_int;
	wxString rep_time;
	ac->GetValue( wxString( wxT("REPEAT_ENABLED") ), rep_ena );
	ac->GetValue( wxString( wxT("REPEAT_TIME") ), rep_time );
	ac->GetValue( wxString( wxT("REPEAT_INTERVAL") ), rep_int );
	long time;
	rep_time.ToLong( &time );
	long interval;
	rep_int.ToLong( &interval );

	long now = wxDateTime::GetTimeNow();

	// if test is running we trigger the repeat timer again in 2 seconds
	if( this->m_timer->IsRunning() )
	{
		m_timerRepeat->Start( 2000, true );
	}
	// If total repeat time has passed just return
	else if( rep_ena == wxT("YES") && m_RepeatActive && m_RepeatStarted + ( time*60*60 ) < now )
	{
		m_RepeatActive = false;
		((TestPanel*)m_ResultPageInstance)->PostTest(false,true);
		return;
	}
	// Normal case - time to run a test!
	else if( !this->m_timer->IsRunning() )
	{
		((TestPanel*)m_ResultPageInstance)->PreStartTest();
		this->m_executefunc(m_ResultPageInstance);
	}


}
void MainFrame::PreStartTest(void* pobj, void (*resultfunc)(void*,bool), bool (*executefunc)(void* pobj))
{
	this->SetCursor( *wxHOURGLASS_CURSOR );

	// Get the config values for test repeat
	AppConfig *ac = AppConfig::GetInstance();
	wxString rep_ena;
	wxString rep_int;
	wxString rep_time;

	ac->GetValue( wxString(wxT("REPEAT_ENABLED")), rep_ena );
	ac->GetValue( wxString(wxT("REPEAT_INTERVAL")), rep_int );
	ac->GetValue( wxString(wxT("REPEAT_TIME")), rep_time );

	long time;
	rep_time.ToLong( &time );
	long interval;
	rep_int.ToLong( &interval );

	//	long now = wxDateTime::GetTimeNow();
	
	wxString header;
	if( rep_ena == wxT("YES") )
	{
		m_timerRepeat->Start( interval*1000*60, true );
		header = wxT("Utf�r repeterande test");
		if( !m_RepeatActive )
		{
			m_RepeatStarted = (long)wxDateTime::GetTimeNow();
		}
		m_RepeatActive = true;
	}
	else
	{
	  header = wxT("Utf�r test");
	  m_RepeatActive = false;
	}

	this->m_dlgProgress = 
		new wxProgressDialog(
				header, 
				wxString( wxT("Var god v�nta...") ),
				101,
				this,
				wxPD_CAN_ABORT | wxPD_APP_MODAL );

#ifdef WIN32
	this->m_dlgProgress->SetSize(350, 160);
	this->m_dlgProgress->Show();
#endif
#ifdef UNIX
	this->m_dlgProgress->SetSize(400, 160);
	this->m_dlgProgress->ShowModal();
#endif

	// set the callback functions
	m_resultfunc = resultfunc;
	m_ResultPageInstance = pobj;
	m_executefunc = executefunc;
}

void MainFrame::StartTest(void)
{
	m_timer->Start(1);
}

void MainFrame::PostTest()
{
	// Get the config values for test repeat
	AppConfig *ac = AppConfig::GetInstance();
	wxString rep_ena;
	wxString rep_int;
	wxString rep_time;

	ac->GetValue( wxString( wxT("REPEAT_ENABLED") ), rep_ena );
	ac->GetValue( wxString( wxT("REPEAT_INTERVAL") ), rep_int );
	ac->GetValue( wxString( wxT("REPEAT_TIME") ), rep_time );

	long time;
	rep_time.ToLong( &time );
	long interval;
	rep_int.ToLong( &interval );

	long now = wxDateTime::GetTimeNow();

	if( m_RepeatActive && m_RepeatStarted + ( time*60*60 ) < now + interval*60 )
	{
		this->m_timerRepeat->Stop();
		this->m_RepeatActive = false;
	}



	delete this->m_dlgProgress;
	this->m_dlgProgress = NULL;
	((TestPanel*)m_ResultPageInstance)->PostTest(false,true);
	this->SetCursor( *wxSTANDARD_CURSOR );
}

void MainFrame::OnEditServerList(wxCommandEvent& WXUNUSED(event))
{
  m_dlgServerList = new ServerListDialog( this );
  m_dlgServerList->Show();
}


MainFrame* MainFrame::GetInstance(void)
{
  return MainFrame::s_Instance;
}

void MainFrame::OnReport(wxCommandEvent& WXUNUSED(event))
{
  m_dlgReport->Init();
  m_dlgReport->Show();
  m_dlgReport->Run();
}

void MainFrame::OnRepeat(wxCommandEvent& WXUNUSED(event))
{
  RepeatDialog rep(this);
  rep.ShowModal();
}

void MainFrame::OnHistorySetting(wxCommandEvent& WXUNUSED(event))
{
  HistorySettingDialog hist(this);
  hist.ShowModal();
}

bool MainFrame::IsRepeatActive(void)
{
	return this->m_RepeatActive;
}

void MainFrame::AbortRepeatTimer(void)
{
	this->m_RepeatActive = false;
	return this->m_timerRepeat->Stop();
}

void MainFrame::RefreshPanels(void)
{
	m_SimplePanel->RefreshSettingsList();
	m_AdvancedPanel->m_PageSimple->RefreshSettingsList();
	m_AdvancedPanel->m_PageAvailability->RefreshSettingsList();
	m_AdvancedPanel->m_PageRTTPacketloss->RefreshSettingsList();
	m_AdvancedPanel->m_PageThroughput->RefreshSettingsList();
}

void MainFrame::OnExportStandard(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog dialog
                 (
                    this,
                    wxT("Spara Resultat"),
                    wxEmptyString,
                    wxT("TPTEST 5 resultat Enkelt l�ge"),
                    wxT("|"),
					wxSAVE | wxOVERWRITE_PROMPT | wxCHANGE_DIR 
				);

	wxString dir;
#ifdef WIN32
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, wxStringBuffer(dir, MAX_PATH));
	if(SUCCEEDED(result)) // or FAILED(result)
	{
			// Do something
	} 
#endif
	dialog.SetDirectory(dir);

    if (dialog.ShowModal() == wxID_OK)
    {
      ResultLog *rlog = ResultLog::GetInstance();
      rlog->SaveStandardResults( dialog.GetPath(), true );
    }
}

void MainFrame::OnExportAvailability(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog dialog
                 (
                    this,
                    wxT("Spara Resultat"),
					wxEmptyString,
                    wxT("TPTEST 5 resultat Tillg�nglighet"),
                    wxT("|"),
					wxSAVE | wxOVERWRITE_PROMPT | wxCHANGE_DIR 
				);

	wxString dir;
#ifdef WIN32
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, wxStringBuffer(dir, MAX_PATH));
	if(SUCCEEDED(result)) // or FAILED(result)
	{
			// Do something
	} 
#endif
	dialog.SetDirectory(dir);

    if (dialog.ShowModal() == wxID_OK)
    {
		ResultLog *rlog = ResultLog::GetInstance();
		rlog->SaveAvailabilityResults( dialog.GetPath(), true );
	}
}

void MainFrame::OnExportRTTPacketloss(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog dialog
                 (
                    this,
                    wxT("Spara Resultat"),
                    wxEmptyString,
                    wxT("TPTEST 5 resultat Svarstider och Paketf�rluster"),
                    wxT("|"),
					wxSAVE | wxOVERWRITE_PROMPT | wxCHANGE_DIR 
				);

	wxString dir;
#ifdef WIN32
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, wxStringBuffer(dir, MAX_PATH));
	if(SUCCEEDED(result)) // or FAILED(result)
	{
			// Do something
	} 
#endif
	dialog.SetDirectory(dir);

    if (dialog.ShowModal() == wxID_OK)
    {
		ResultLog *rlog = ResultLog::GetInstance();
		rlog->SaveRTTPacketlossResults( dialog.GetPath(), true );
	}
}

void MainFrame::OnExportThroughput(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog dialog
                 (
                    this,
                    wxT("Spara Resultat"),
                    wxEmptyString,
                    wxT("TPTEST 5 resultat Genomstr�mning"),
                    wxT("|"),
					wxSAVE | wxOVERWRITE_PROMPT | wxCHANGE_DIR 
				);

	wxString dir;
#ifdef WIN32
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, wxStringBuffer(dir, MAX_PATH));
	if(SUCCEEDED(result)) // or FAILED(result)
	{
			// Do something
	} 
#endif
	dialog.SetDirectory(dir);

    if (dialog.ShowModal() == wxID_OK)
    {
		ResultLog *rlog = ResultLog::GetInstance();
		rlog->SaveThroughputResults( dialog.GetPath(), true );
	}
}

void MainFrame::OnPreferences(wxCommandEvent& WXUNUSED(event))
{
  wxMessageBox( wxT(""),
		   wxT("Inst�llningar g�rs under menyn alternativ."),
		   wxICON_INFORMATION | wxOK );
}

void MainFrame::EnableMenu( bool enable )
{
	this->m_menuBar->EnableTop( 0, enable );
	this->m_menuBar->EnableTop( 1, enable );
	this->m_menuBar->EnableTop( 2, enable );
}

bool MainFrame::IsPagesLocked(void)
{
	return this->IsRepeatActive() || this->m_timer->IsRunning();
}

void MainFrame::OnManual( wxCommandEvent& WXUNUSED(event) )
{
  wxString strHelpURL;
  
  strHelpURL << wxStandardPaths::Get().GetResourcesDir();
  strHelpURL << wxT("/");
  strHelpURL << wxT("help.html");
  
  wxMimeTypesManager manager;
  wxFileType * filetype = manager.GetFileTypeFromExtension( wxT("html") );
  wxString command = filetype->GetOpenCommand( strHelpURL );
  wxExecute(command);
  delete filetype;
}

