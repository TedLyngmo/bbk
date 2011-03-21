#include "DialogAbout.h"

#include <wx/mimetype.h>
#include <wx/filefn.h>

BEGIN_EVENT_TABLE( DialogAbout, wxDialog )
	EVT_PAINT(DialogAbout::OnPaint)
	EVT_LEFT_DOWN(DialogAbout::OnLeftDown)
END_EVENT_TABLE()

#ifdef UNIX
#define DA_WIDTH 500
#define DA_HEIGHT 600
#endif
#ifdef WIN32
#define DA_WIDTH 420
#define DA_HEIGHT 600
#endif

DialogAbout::DialogAbout(wxWindow *parent)
: wxDialog(parent, wxID_ANY, wxString(wxT("Om TPTEST 5")), wxDefaultPosition, wxSize( DA_WIDTH, DA_HEIGHT ) )
{
	m_Sizer = new wxGridBagSizer( 5, 5 );

	wxImage::AddHandler( new wxJPEGHandler );
	wxImage logo;


	/* No logo 
	if( wxFile::Exists( wxT("GHNlogo.jpg") ) &&
	    logo.LoadFile(wxT("GHNlogo.jpg"), wxBITMAP_TYPE_JPEG ) )
	{
		m_ghnLogo = new wxBitmap( logo );
	}
	else
	{
	  wxMessageDialog( this, wxT("Could not load GHN logo!") ) ;
		this->m_ghnLogo = NULL;
	}
	*/

	wxString strAbout;
	strAbout << TPTEST_VERSION_STRING << wxT("\n\n");
	strAbout << wxT("TPTEST 5 �r utvecklat av Gatorhole AB (www.gatorhole.com)") << wxT("\n");
	strAbout << wxT("p� uppdrag av II-Stiftelsen (www.iis.se), Konsumentverket (www.kov.se)") << wxT("\n");
	strAbout << wxT("och Post- och Telestyrelsen (www.pts.se).") << wxT("\n\n");

	strAbout << wxT("Stiftelsen Internetinfrastruktur (II-stiftelsen), Konsumentverket, \n");
	strAbout << wxT("Post- och Telestyrelsen, IT-kommissionen, IP Performance Sverige AB,\n");
	strAbout << wxT("Autonomica AB eller Netnod Internet Exchange AB ansvarar inte f�r att de\n");
	strAbout << wxT("testresultat som levereras av TPTEST �r korrekta. Stiftelsen \n");
	strAbout << wxT("Internetinfrastruktur (II-stiftelsen), Konsumentverket, Post- och Telestyrelsen,\n");
	strAbout << wxT("IT-kommissionen, IP Performance Sverige AB, Autonomica AB eller Netnod\n");
	strAbout << wxT("Internet Exchange AB ansvarar inte f�r drifts�kerhet och tillg�nglighet avseende\n");
	strAbout << wxT("m�tservrar eller masterserver, och inte heller f�r att TPTEST fortl�pande finns\n");
	strAbout << wxT("tillg�ngligt, f�r att det fortl�pande finns anv�ndarst�d eller f�r uppdateringar\n");
	strAbout << wxT("av programmet.\n");
	strAbout << wxT("\n");
	strAbout << wxT("Varje anv�ndare ansvarar sj�lv f�r att programmet �r korrekt konfigurerat f�r den\n");
	strAbout << wxT("egna datorn. Stiftelsen Internetinfrastruktur (II-stiftelsen), Konsumentverket,\n");
	strAbout << wxT("Post- och Telestyrelsen, IT-kommissionen, IP Performance Sverige AB, \n");
	strAbout << wxT("Autonomica AB eller Netnod Internet Exchange AB tar inte ansvar f�r \n");
	strAbout << wxT("klientprogrammets funktion i den individuella driftmilj�n eller f�r fel som\n");
	strAbout << wxT("programmet orsakar i operativsystem, andra applikationer eller h�rdvara, inte\n");
	strAbout << wxT("heller f�r skada som anv�ndaren orsakar p� andra datorer genom anv�ndningen \n");
	strAbout << wxT("av TPTEST.");

	m_stxtAbout =
		new wxStaticText( this, 
			-1, 
			strAbout,
			wxDefaultPosition,
			wxDefaultSize,
			wxALIGN_CENTRE );

	m_btnOk = new wxButton(this, wxID_CANCEL, wxT("&Ok")  );
	
	m_Sizer->Add( m_stxtAbout, wxGBPosition( 0, 0 ), wxDefaultSpan, wxALIGN_CENTER | wxALL, 10 );
	m_Sizer->Add( m_btnOk, wxGBPosition( 1,  0 ), wxDefaultSpan, wxALIGN_CENTER | wxALL, 10 );

	this->SetSizer( m_Sizer );
	m_Sizer->SetSizeHints( this );
}

DialogAbout::~DialogAbout(void)
{
  /* No logo
	delete m_ghnLogo;
  */
	delete m_stxtAbout;
	delete m_btnOk;
}

void DialogAbout::OnLeftDown( wxMouseEvent &event )
{
	if( event.m_x > 320 &&
		event.m_x < 400 &&
		event.m_y > 330 &&
		event.m_y < 354 )
	{
	  wxString strHelpURL = wxT("http://www.ghn.se");
	  
	  wxMimeTypesManager manager;
	  wxFileType * filetype = manager.GetFileTypeFromExtension( wxT("html") );
	  wxString command = filetype->GetOpenCommand( strHelpURL );
	  wxExecute(command);
	}

	event.Skip();
}

void DialogAbout::OnPaint( wxPaintEvent &WXUNUSED(event) )
{
  wxPaintDC dc(this);
  /* No logo  
  if( this->m_ghnLogo != NULL )
    {
      dc.DrawBitmap( *this->m_ghnLogo, 320, 330 );
    }	
  */
}
