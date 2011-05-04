/*
 * $Id: tptest.h,v 1.4 2002/09/26 14:49:03 rlonn Exp $
 * $Source: /cvsroot-fuse/tptest/apps/windows/clients/gui/tptest.h,v $
 *
 * TPTEST 3.0 (C) Copyright II-Stiftelsen 2002
 *
 * tptest.h - header file
 *
 * Written by
 *  Ragnar L�nn <prl@gatorhole.com>
 *  Hans N�st�n
 *
 * This file is part of the TPTEST system.
 * See the file LICENSE for copyright notice.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by       
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.       
 *
 * You should have received a copy of the GNU General Public License       
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307  USA.
 *
 */

#ifndef _TPTEST_H_
#define _TPTEST_H_

#define MASTERSERVER 	"testledare.ip-performance.se"
#define MASTERPORT	1640
#define MASTERUDPPORT	3240

#define CLIENTINFO		"TPTEST 3.0.3"

// Comment this out if you want to compile a Swedish-language version of TPTEST
#define ENGLISH

#define REPORT

/*
 * Diversified constants.
 */

#define DEFAULT_PKTS_SEC 5
#define DEFAULT_PKT_SIZE 1024
#define DEFAULT_BITRATE 64000
#define TEXTBUF		100
#define MIN_PKT_SIZE ( sizeof( struct tpHeader ) + IP_UDP_SIZE )
#define MAX_PKT_SIZE 65535
#define MIN_BITRATE ( MIN_PKT_SIZE * 8 )
#define MAX_BITRATE ( MAX_PKT_SIZE * MAX_PKT_RATE * 8 )
#define START_TCP_BYTES		51200
#define DEFAULT_TCPBYTES	(START_TCP_BYTES * 2)
#define DEFAULT_TESTTIME	10
#define CSHWAIT	250

#define INVALID_TESTMODE	(-3)
#define TEST_TIMEOUT		(-2)
#define TEST_ERROR			(-1)
#define NOSUCHHOST			(-4)
#define LOOKUPINITFAIL		(-5)
#define QUERYMASTERINITFAIL	(-6)
#define QUERYMASTERFAIL		(-7)

#define TEST_WAITING		0
#define TEST_RUNNING		1
#define TEST_FINISHED		2

#define MYSTATE_IDLE			0
#define MYSTATE_STDTEST			1
#define MYSTATE_AUTOTEST		2
#define MYSTATE_SINGLETEST		3
#define MYSTATE_GETSERVERLIST	4


/*
 * Prototypes.
 */

void Initialize();
void UpdateTextWindow();
void ClearTextWindow();
void tptest();
void UpdateServerList();
int ServerSelected();
void CheckPULStatus();

void Report(char *);
void ReportStats();
void update_progressbar();
void fill_progressbar();
char *Long64ToString( _int64 );
void stripcrlf(char *);
void EnableInputWindows(bool);
void PrintReport();

HWND WINAPI CreateTT(HWND);

/*
 * Version integers.
 */
int MajorVersion;
int MinorVersion;

/*
 * Global data areas.
 */

struct outtext_struct {
	char line[100];
	struct outtext_struct *next;
} *outtext, *servers;

/* more globals */

int state;

char Info[2000];
char tmp[200];

char StatsPF = 0;

double LastBytesPerSecondRcv = 0.0;

PRINTDLG pd;

double BestUDPRcvRate = 0.0;
double BestUDPSendRate = 0.0;
double BestTCPRcvRate = 0.0;
double BestTCPSendRate = 0.0;

#ifdef DEBUGFILE
FILE *dbg = NULL;
char fname[30];
#endif

// User supplied variables
char SelectedMaster[100] = MASTERSERVER;
int SelectedMasterPort = MASTERPORT;

// 
// Static text

// Obsolete
#define UPGRADE_URL "http://tptest.iis.se/"



// Static test bitrates. When 0 is encountered, the bitrate is
// increased by 10Mbps for each new test
int TestSpeed[] = {\
	30000,\
	56000,\
	64000,\
	128000,\
	256000,\
	384000,\
	512000,\
	640000,\
	768000,\
	1000000,\
	1536000,\
	2000000,\
	3000000,\
	4000000,\
	5000000,\
	6000000,\
	8000000,\
	9000000,\
	10000000,\
	11000000,\
	12000000,\
	15000000,\
	20000000,\
	25000000,\
	30000000,\
	35000000,\
	40000000,\
	45000000,\
	50000000,\
	0\
};

#define CSH_SERVERLIST	1
#define CSH_RADIO1		2
#define CSH_RADIO2		3
#define CSH_RADIO3		4
#define CSH_MAXTCP		5
#define CSH_MAXUDP		6
#define CSH_TCPSEND		7
#define CSH_TCPRCV		8
#define CSH_UDPSEND		9
#define CSH_UDPRCV		10
#define CSH_TCPINFO		11
#define CSH_UDPINFO		12
#define CSH_SENDLOAD	13
#define CSH_RCVLOAD		14
#define CSH_STDTEST		15
#define CSH_STARTA		16
#define CSH_SERVERNAME	17
#define CSH_AVAILBW		18
#define CSH_PROGBAR		19

// x1,x2,y1,y2,INFO. x -= 30   y-= 33
int CSHCoordinates[] = {\
	22,246,217,253,CSH_SERVERLIST,\
	44,165,304,314,CSH_RADIO1,\
	44,128,326,337,CSH_RADIO2,\
	44,143,348,359,CSH_RADIO3,\
	275,430,244,279,CSH_MAXTCP,\
	440,595,244,279,CSH_MAXUDP,\
	275,430,280,305,CSH_TCPSEND,\
	275,430,306,334,CSH_TCPRCV,\
	440,595,280,305,CSH_UDPSEND,\
	440,595,306,334,CSH_UDPRCV,\
	275,430,159,243,CSH_TCPINFO,\
	440,595,159,243,CSH_UDPINFO,\
	378,468,368,391,CSH_SENDLOAD,\
	484,584,368,391,CSH_RCVLOAD,\
	64,218,137,179,CSH_STDTEST,\
	184,246,372,398,CSH_STARTA,\
	20,245,258,283,CSH_SERVERNAME,\
	276,380,352,363,CSH_AVAILBW,\
	16,602,420,438,CSH_PROGBAR,\
	0,0,0,0,0\
};

#ifdef ENGLISH

#define MSG_START1			"Start test"
#define MSG_CANCEL1			"Cancel"
#define MSG_CANCEL2			"Cancel"
#define MSG_SENDING1		"Sending"
#define MSG_RECEIVING1		"Receiving"
#define MSG_TESTSENDSPEED1	"Testing send speed"
#define MSG_TESTRCVSPEED1	"Testing receive speed"
#define MSG_STANDARDTEST	"Start standard test"
#define MSG_FINISHED		"Test finished!"
#define MSG_DONE			"Done"
#define MSG_LOOKUP1			"Looking up host"
#define MSG_MQUERY			"Getting server list from"

#else

#define MSG_START1			"Starta test"
#define MSG_CANCEL1			"Avbryt test"
#define MSG_CANCEL2			"Avbryt test"
#define MSG_SENDING1		"Skickar"
#define MSG_RECEIVING1		"Tar emot"
#define MSG_TESTSENDSPEED1	"Testar s�ndhastighet"
#define MSG_TESTRCVSPEED1	"Testar mottagningshastighet"
#define MSG_STANDARDTEST	"Starta standardtest"
#define MSG_FINISHED		"M�tningen �r slutf�rd!"
#define MSG_DONE			"Klart"
#define MSG_LOOKUP1			"H�mtar IP-adressen till"
#define MSG_MQUERY			"H�mtar serverlista fr�n"


#endif


#ifdef ENGLISH
#define SENDMSG1	"Your transmit speed was"
#define RCVMSG1		"Your receive speed was"
#define NOT_TESTED	"Not tested"
#define TPERROR		"Error"
#define TESTSEND	"Testing Transmit at"
#define TESTRCV		"Testing Receive at"
#define TESTDEF		"Testing speed"
#define STOP		"Stop"
#define TESTRES		"Test results"

#undef IDC_TPTEST2
#define IDC_TPTEST2		IDC_TPTEST3

#undef IDD_VALJ
#define IDD_VALJ		IDD_VALJ1

#undef IDD_STANDARD
#define IDD_STANDARD	IDD_STANDARD5

#undef IDD_DIALOG5
#define IDD_DIALOG5		IDD_DIALOG6

#undef IDD_ABOUTBOX
#define IDD_ABOUTBOX	IDD_ABOUTBOX1

char *CSHText[] = {\
	"x",\
	"Here you select what server to use for testing",\
	"Test both send and receive speed of your connection",\
	"Test only the send speed of your connection",\
	"Test only the receive speed of your connection",\
	"Maximum send- and receive speeds achieved using TCP",\
	"Maximum send- and receive speeds achieved using UDP",\
	"Maximum TCP send speed",\
	"Maximum TCP receive speed",\
	"Maximum UDP send speed",\
	"Maximum UDP receive speed",\
	"TCP is a transport protocol that is used when you're e.g. surfing using "\
	"a web browser.\r\nTPTEST measures your maximum attainable surf speed "\
	"under ideal circumstances and presents the result\r\nat the bottom of "\
	"this box. Note that the result you get is transient so to get a good\r\n"\
	"grip on the average bandwidth of your connection you need to make several "\
	"tests at different times.",\
	"UDP is a transport protocol that is used when you e.g. play games on "\
	"the Internet.\r\nTPTEST measures the maximum UDP throughput of your connection "\
	"under ideal circumstances\r\nand presents the result at the bottom of this box.\r\n"\
	"To get a good idea about the average capacity of your connection you should "\
	"make several tests at different times.",\
	"Send Efficiency:\r\n"\
	"This value is the result of the TCP send test divided by the result of the "\
	"UDP send test.\r\nIt is given as a percentage and shows how much of the "\
	"capacity of your connection that you can actually use\r\nwhen you're e.g. "\
	"surfing the web or using TCP-based Internet services. Note that you should\r\n"\
	"do several tests at different times to get a good idea about the average value.",\
	"Receive Efficiency:\r\n"\
	"This value is the result of the TCP receive test divided by the result of the "\
	"UDP receive test.\r\nIt is given as a percentage and shows how much of the "\
	"capacity of your connection that you can actually use\r\nwhen you're e.g. "\
	"surfing the web or using TCP-based Internet services. Note that you should\r\n"\
	"do several tests at different times to get a good idea about the average value.",\
	"Press this button to start TPTEST with the settings we recommend",\
	"Press this button to start TPTEST with your own settings above",\
	"This is the address of the test server you have chosen",\
	"This box shows how much of your maximum possible bandwidth you actually\r\n"\
	"get when e.g. surfing the web. It is the results of the TCP test divided\r\n"\
	"by the results of the UDP test and is displayed as a percentage.",\
	"This progress bar shows how far the currently running test has progressed.\r\n"\
	"Note that every time you press the start button, multiple tests will be made\r\n"\
	"so this bar does not reflect the progress of the whole testing session."\
};

#define ABOUTTEXT ""\
	"TPTEST 3.0 was developed by Ragnar Lonn <ragnar@gatorhole.se>.TPTEST is sponsored\r\n"\
	"by the Foundation for Internet Infrastructure (www.iis.se), the Swedish\r\n"\
	"Consumer Agency (www.konsumentverket.se) and the Swedish National Post and\r\n"\
	"Telecom Agency (www.pts.se).\r\n\r\n"\
	"The II-foundation (II-Stiftelsen), The Swedish Consumer Agency (Konsumentverket),\r\n"\
	"The Swedish National Post and Telecom Agency (Post- och Telestyrelsen),\r\n"\
	"The Swedish ICT-Commission, IP Performance Sverige AB, Autonomica AB or\r\n"\
	"Netnod Internet Exchange AB are not to be held responsible for the accuracy of\r\n"\
	"the test results generated by TPTEST. The II-foundation (II-Stiftelsen), The\r\n"\
	"Swedish Consumer Agency (Konsumentverket), The Swedish National Post and Telecom\r\n"\
	"Agency (Post- och Telestyrelsen), The Swedish ICT-Commission, IP Performance\r\n"\
	"Sverige AB, Autonomica AB or Netnod Internet Exchange AB are not responsible for\r\n"\
	"the maintenance and availability of test servers or master servers, and neither\r\n"\
	"responsible for the continued support, maintenance and availability of TPTEST.\r\n"\
	"\r\n"\
	"It is up to each and every user to make sure TPTEST is configured appropriately\r\n"\
	"for their own computer. The II-foundation (II-Stiftelsen), The Swedish Consumer\r\n"\
	"Agency (Konsumentverket), The Swedish National Post and Telecom Agency (Post- \r\n"\
	"och Telestyrelsen), The Swedish ICT-Commission, IP Performance Sverige AB, \r\n"\
	"Autonomica AB or Netnod Internet Exchange AB does not accept any responsibility\r\n"\
	"for the performance of TPTEST in the local user environment, or for problems\r\n"\
	"TPTEST might cause with operating systems, other applications or hardware, nor\r\n"\
	"for damage the user might inflict on other computer systems through the use of TPTEST.\r\n"

#define DISPLAYINFO "Press \"Standard test\" if you want to test using the settings we recommend\r\n"\
	"Press \"Start test\" if you want to test using your own settings"

#define DISPLAYINFO1 "Doing TCP Send test - Press CANCEL if you wish to abort test"
#define DISPLAYINFO2 "Doing TCP Receive test - Press CANCEL if you wish to abort test"
#define DISPLAYINFO3 "Doing UDP Send test - Press CANCEL if you wish to abort test"
#define DISPLAYINFO4 "Doing UDP Receive test - Press CANCEL if you wish to abort test"

#define TPTEST_INFO	"TPTEST - The Internet bandwidth tester\n"\
	"URL: http://tptest.iis.se/\n"

#define TPTEST_HELP ""\
	"The II-foundation (II-Stiftelsen), The Swedish Consumer Agency (Konsumentverket),\r\n"\
	"The Swedish National Post and Telecom Agency (Post- och Telestyrelsen),\r\n"\
"The Swedish ICT-Commission, IP Performance Sverige AB, Autonomica AB or\r\n"\
"Netnod Internet Exchange AB are not to be held responsible for the accuracy\r\n"\
"of the test results generated by TPTEST. The II-foundation (II-Stiftelsen), \r\n"\
"The Swedish Consumer Agency (Konsumentverket), The Swedish National Post and Telecom\r\n"\
"Agency (Post- och Telestyrelsen), The Swedish ICT-Commission, \r\n"\
"IP Performance Sverige AB, Autonomica AB or Netnod Internet Exchange AB are not\r\n"\
"responsible for the maintenance and availability of test servers or master servers,\r\n"\
"and neither responsible for the continued support, maintenance and availability of\r\n"\
"TPTEST.\r\n\r\n"\
"It is up to each and every user to make sure TPTEST is configured\r\n"\
"appropriately for their own computer. The II-foundation (II-Stiftelsen), The Swedish\r\n"\
"Consumer Agency (Konsumentverket), The Swedish National Post and Telecom Agency\r\n"\
"(Post- och Telestyrelsen), The Swedish ICT-Commission, IP Performance\r\n"\
"Sverige AB, Autonomica AB or Netnod Internet Exchange AB does not accept any\r\n"\
"responsibility for the performance of TPTEST in the local user environment, or for\r\n"\
"problems TPTEST might cause with operating systems, other applications or hardware,\r\n"\
"nor for damage the user might inflict on other computer systems through\r\n"\
"the use of TPTEST.\r\n"\
"\r\n"\
"\r\n"\
"Description of the program TPTEST\r\n"\
"\r\n"\
"Contents:\r\n"\
"1   What TPTEST is measuring\r\n"\
"2   Connections where the transmit and receive speeds differ\r\n"\
"3   TPTEST - main modes of operation\r\n"\
"4   Standard mode - the default mode when the program is started\r\n"\
"5   Advanced mode\r\n"\
"6   Things to consider when setting test parameters\r\n"\
"7   If the test doesn't work or you get an unexpected result?\r\n"\
"\r\n"\
"\r\n"\
"1       What TPTEST is measuring\r\n"\
	"The program TPTEST is measuring the throughput speed, that is the speed\r\n"\
	"(measured in bits/second) to and from the test server that is being used.\r\n"\
	"Note that the throughput is usually lower than the connection speed.\r\n"\
"\r\n"\
	"Several factors decide what throughput you get. The most important ones\r\n"\
	"are the connection speed, the access network, the network of your ISP and\r\n"\
	"how congested the network is. TPTEST tries to avoid a series of known problems\r\n"\
	"network performance metering software has had to contend with by doing all its\r\n"\
	"measurements vs a dedicated test server that is as centrally located and well-\r\n"\
	"connected as possible. The test server is located at an Internet exchange point\r\n"\
	"in Sweden (in Stockholm, to be precise), which is one of the places where traffic\r\n"\
	"is being exchanged between Internet operators. The Internet operators themselves\r\n"\
	"may install test servers inside their own networks too. The number of available\r\n"\
	"test servers may vary because of this. TPTEST will tell you what servers are\r\n"\
	"currently available. Read more below about how to select a test server.\r\n"\
"\r\n"\
"2       Connections where the transmit and receive speeds differ\r\n"\
"There are some types of Internet connections that give you different send and\r\n"\
	"receive speeds (also called \"asymmetrical connections\"). Some examples of\r\n"\
	"such connections are xDSL and many cable-TV connections where the receive speed\r\n"\
	"is usually higher than the send speed.\r\n"\
"\r\n"\
	"The receive speed could be the most interesting thing to measure as that tells\r\n"\
	"you a lot about how long it will take for you to, for instance, download a webpage\r\n"\
	"to your computer. This means that if you, when measuring the speed, find that your\r\n"\
	"send speed is much lower than your receive speed it might not mean you have a problem.\r\n"\
"\r\n"\
"3       TPTEST - main modes of operation\r\n"\
"The program has two main modes: Standard mode and Advanced mode.\r\n"\
"\r\n"\
	"Standard mode is set by default when the program is started. Standard mode means\r\n"\
	"that TPTEST is user-friendly and easy to use.\r\n"\
"\r\n"\
"4       Standard mode - the default mode when the program is started\r\n"\
	"When starting TPTEST you will see a window with some buttons and alternatives to\r\n"\
	"choose from. There are three types of tests you can do (transmit, receive, or both).\r\n"\
	"There is also a button you can use to select the test speed (Read more about that \r\n"\
"under \"Test with a selected speed\"). Finally there is a Start-button that\r\n"\
	"runs the test when you click it.\r\n"\
"\r\n"\
	"The Start-button runs the test you have selected. The Start-button will, after the \r\n"\
	"test is started, change into a Stop-button that you can use to stop the test.\r\n"\
"\r\n"\
	"In Standard mode you can do the following:\r\n"\
	"- Test without a selected speed.\r\n"\
	"- Test with a selected speed.\r\n"\
"\r\n"\
	"The following three types of tests are available in Standard mode:\r\n"\
	"- Both Transmit and Receive tests.\r\n"\
	"- Transmit test only.\r\n"\
	"- Receive test only.\r\n"\
"\r\n"\
	"When in Standard mode the test will be made vs a test server located at the national\r\n"\
	"Internet exchange point in Stockholm (provided you haven't entered Advanced mode,\r\n"\
	"selected another test server, and then jumped back to Standard mode).\r\n"\
"\r\n"\
"4.1     Test without a selected speed\r\n"\
	"If you just click the Start-button without selecting a speed first, TPTEST will\r\n"\
	"try a number of different speeds. The program will test your send or receive speed\r\n"\
	"(or both, depending on what type of test you chose). The testing may take a little\r\n"\
	"while (a minute or so) as TPTEST has to make several measurements with successively\r\n"\
	"higher speeds to determine the maximum speed for your connection.\r\n"\
"\r\n"\
"4.2     Test with a selected speed\r\n"\
	"If you click the button marked \"Select speed\" you will be presented with a small\r\n"\
	"window wher you can choose a predefined test speed that should correspond to the\r\n"\
	"connection speed of your Internet connection. When you have chosen a certain speed\r\n"\
	"TPTEST will measure only once at that exact speed and then report the result it gets.\r\n"\
	"You should note that the throughput speed you get (the test result) is usually lower than\r\n"\
	"the connection speed. Because of this it might be a good idea to start with a speed\r\n"\
	"that is slightly lower than the connection speed of your Internet connection. Then you\r\n"\
	"perform several tests with increasing speed and note the best result you get.\r\n"\
"\r\n"\
	"If you have an asymmetrical connection you might have to test at one speed when doing\r\n"\
	"the send test(s) and another speed when doing the receive test(s).\r\n"\
"\r\n"\
"4.3     Transmit and Receive\r\n"\
	"Transmit means that TPTEST sends data packets to the test server and when the\r\n"\
	"transmission is done the server reports how long it took to receive the packets.\r\n"\
	"TPTEST can then calculate the throughput speed you got when sending data.\r\n"\
"\r\n"\
	"Receive means that the test server sends data packets to TPTEST and TPTEST\r\n"\
	"measures the time it takes to receive the packets. When all packets have been\r\n"\
	"received, TPTEST calculates the throughput speed and reports the results.\r\n"\
"\r\n"\
	"Transmit and Receive means that first a transmit test, then a receive test is performed\r\n"\
"\r\n"\
"4.4     The test result\r\n"\
	"After the completion of the test you will always get the test result in a pop-up window\r\n"\
	"labeled \"Test Result\". The test result is a close approximation of the highest \r\n"\
	"throughput speed achieved. The best result achieved since the program was started will\r\n"\
	"also be shown in a small box when in Standard mode. If you repeat a test and get a\r\n"\
	"lower test result, this value will not be updated.\r\n"\
"\r\n"\
"If you are interested in getting a moderately accurate test result, reflecting your true\r\n"\
"network throughput, you should perform a test more than once and preferably at different\r\n"\
"occasions. The test result you will get usually reflects the maximum throughput you can\r\n"\
"expect to/from the location where the test server you are using is located. The actual\r\n"\
"throughput you get when you, for instance, download web pages from a web server also\r\n"\
"depends on other factors, like the performance and load on the webserver from which \r\n"\
"you are downloading the webpage.\r\n"\
"\r\n"\
"5       Advanced Mode\r\n"\
"The Advanced mode in TPTEST is meant for those with thorough knowledge of Internet\r\n"\
"communication who want to perform more advanced tests than is possible in Standard mode.\r\n"\
"\r\n"\
"In Advanced mode there are a number of settings you can make. At the top you see the\r\n"\
"master server the program is using (the master server is a part of the TPTEST system).\r\n"\
"The master server provides TPTEST with a list of available test servers that can be\r\n"\
"used for performing the actual bandwidth tests. This list will be fetched from the\r\n"\
"master server when you click the \"Fetch testserver list\" button. The list will then\r\n"\
"be displayed in the list box below the same button and you can choose the test server\r\n"\
"to use by clicking on it in the list.\r\n"\
"\r\n"\
"In Advanced mode there are three different types of tests you can perform. They are:\r\n"\
"- Transmit.\r\n"\
"- Receive.\r\n"\
"- Full duplex.\r\n"\
"\r\n"\
"In Advanced mode you can also choose the number of packets per second to use, the\r\n"\
"packet size, the datarate (speed) and the test time.\r\n"\
"\r\n"\
"If you change the packet size or the number of packets per second the datarate will be\r\n"\
"automatically altered to fit these changes.\r\n"\
"\r\n"\
"If you change the datarate TPTEST will automatically change the packetsize and/or the\r\n"\
"number of packets per second and try to match the selected datarate as closely as\r\n"\
"possible. TPTEST will try to keep the packet size at or below 1500 bytes to avoid\r\n"\
"unnecessary fragmentation when transmitting packets across an ethernet.\r\n"\
"\r\n"\
"In the \"Server\" field TPTEST will display the address of the selected test server.\r\n"\
"In the \"Info\" field TPTEST will display an informational string about \r\n"\
"the selected test server.\r\n"\
"In the \"Port\" field TPTEST will display what control port (TCP) the\r\n"\
"selected test server uses.\r\n"\
"\r\n"\
"When the test has started you will be continuously notified of what is happening in the \r\n"\
"large text window to the right.\r\n"\
"\r\n"\
"5.1     Transmit\r\n"\
"Transmit means that TPTEST will send data packets to the test server.\r\n"\
"\r\n"\
"Here is an explanation of the test results you get in the text window to the right\r\n"\
"after a Transmit test is completed:\r\n"\
"\r\n"\
"Type of test: Transmit only.\r\n"\
"\r\n"\
"Send statistics\r\n"\
"  Bits/second sent: The speed at which TPTEST managed to send the packets.\r\n"\
"\r\n"\
"Receive statistics\r\n"\
"  Bit/second received: The speed at which the test server received the packets.\r\n"\
"\r\n"\
"5.2     Receive\r\n"\
"Receive means that the test server will send data packets to TPTEST.\r\n"\
"\r\n"\
"Here is an explanation of the test results you get in the text window to the right\r\n"\
"after a Receive test is completed:\r\n"\
"\r\n"\
"Type of test: Receive only.\r\n"\
"\r\n"\
"Send statistics\r\n"\
"  Bits/second sent: The speed at which the test server managed to send the packets.\r\n"\
"\r\n"\
"Receive statistics\r\n"\
"  Bit/second received: The speed at which TPTEST received the packets.\r\n"\
"\r\n"\
"5.3     Full duplex\r\n"\
"Full duplex is a combined send/receive test. When performing a full duplex test the\r\n"\
"throughput is always limited by whichever is slowest of the outgoing bandwidth and the\r\n"\
"incoming bandwidth.\r\n"\
"\r\n"\
"When doing a full duplex test TPTEST will send the data packets to the test server\r\n"\
"which will immediately return every received packet. TPTEST keeps track of when each\r\n"\
"packet was sent and can that way not only calculate the throughput but also the \r\n"\
"roundtrip time for each packet. The roundtrip time (RTT) is the time it takes for a\r\n"\
"packet to travel from your computer to the server and back. This is sometimes also\r\n"\
"lazily called the \"ping time\" from the program with the same name (ping) that is\r\n"\
"used to, among other things, check the roundtrip time to a certain destination. \r\n"\
"Roundtrip time can also be called \"latency\" and is important for some Internet\r\n"\
"applications like games or telephony.\r\n"\
"\r\n"\
"Here is an explanation of some of the test results you get in the text window to the right:\r\n"\
"\r\n"\
"Roundtrip statistics:\r\n"\
"  Min roundtrip delay: The smallest roundtrip time, ms.\r\n"\
"  Max roundtrip delay: The largest roundtrip time, ms.\r\n"\
"  Avg roundtrip delay: The average roundtrip time, ms.\r\n"\
"\r\n"\
"  5.4     Printing the test results\r\n"\
"The current version of TPTEST is not able to print test results directly to a printer. \r\n"\
"To get the results printed you may cut-and-paste the results into a word processing\r\n"\
"program and use its printing functions.\r\n"\
"\r\n"\
"6       Things to consider when setting test parameters\r\n"\
"A few things to consider when choosing test parameters. If you use much too high\r\n"\
"values for datarate, packets per second or packet size you might overload your\r\n"\
"connection, resulting in large packet loss rates and likely very bad test results.\r\n"\
"The best strategy is to try different test speeds, one at a time, until you find\r\n"\
"one that gives you the best results (that is, the highest throughput).\r\n"\
"\r\n"\
"If you are interested in finding out the roundtrip delays to and from the test server\r\n"\
"you should use fairly small packets to avoid the risk of having the roundtrip time affected\r\n"\
"by the time it takes to transfer the data contained in the packet.\r\n"\
"\r\n"\
"A test time of 10-20 seconds is enough in most cases. Note that the test server may\r\n"\
"refuse to perform a test where some test parameter has been set to a value that is\r\n"\
"deemed too extreme. For instance if a tester is trying to perform a 24-hour test\r\n"\
"or requests a test speed of 200 Mbit/s. The exact maximum values accepted by a test\r\n"\
"server are set by the server owner.\r\n"\
"\r\n"\
"7       If the test doesn't work or you get an unexpected result?\r\n"\
"There can be several reasons whya test might not work or why you might get an \r\n"\
"unexpected result.\r\n"\
"\r\n"\
"If your computer is protected by a firewall there is a large risk that you can't\r\n"\
"perform a Receive test or a Full duplex test. Try a Transmit test and see if it works.\r\n"\
"\r\n"\
"If you lack a fully functional Internet connection the test will of course fail.\r\n"\
"\r\n"\
"If you're using an xDSL- or cable-TV connection and get a much higher throughput when\r\n"\
"doing a Receive test than you get when doing a Transmit test it is likely that everything\r\n"\
"is perfectly OK.\r\n"\
"\r\n"\
"Finally a general advice: the more you test, the more you know. A single test can be\r\n"\
"very difficult to get any useful information from. In the Help-menu under \"Contact info\"\r\n"\
"you can find the address of the TPTEST web page. On that web page you can\r\n"\
"download the latest TPTEST version and also read more about how to use the\r\n"\
"program in order to get the best possible test results.\r\n"\
"\r\n"\
"\r\n"



#else

#define NOT_TESTED	"Ej testad"
#define SENDMSG1	"Din s�ndning uppn�dde en hastighet av"
#define RCVMSG1		"Din mottagning uppn�dde en hastighet av"
#define TPERROR		"Fel"
#define TESTSEND	"Testar s�ndning i"
#define TESTRCV		"Testar mottagning i"
#define TESTDEF		"Testar hastighet"
#define TESTRES		"Testresultat"
#define STOP		"Avbryt"


char *CSHText[] = {\
	"x",\
	"H�r kan du v�lja vilken server du ska testa mot",\
	"Testa b�de s�nd- och mottagningshastighet",\
	"Testa enbart s�ndhastigheten",\
	"Testa enbart mottagningshastigheten",\
	"H�gsta uppm�tta hastigheter med TCP",\
	"H�gsta uppm�tta hastigheter med UDP",\
	"Max TCP s�ndhastighet",\
	"Max TCP mottagningshastighet",\
	"Max UDP s�ndhastighet",\
	"Max UDP mottagningshastighet",\
	"TCP �r ett transportprotokoll som anv�nds n�r du ex.vis surfar.\r\n"\
	"TPTEST m�ter vilken surfhastighet du kan f� under ideala omst�ndigheter "\
	"och presenterar resultatet\r\nl�ngst ned i den h�r rutan. Notera att resultatet "\
	"du f�r h�r �r momentant - dvs det kan variera\r\nfr�n g�ng till g�ng. M�t d�rf�r "\
	"helst flera g�nger vid olika tillf�llen f�r att f� en bra uppfattning om din\r\n"\
	"anslutnings genomsnittliga maximala surfhastighet.",\
	"UDP �r ett transportprotokoll som anv�nds n�r du ex.vis spelar spel p� n�tet.\r\n"\
	"TPTEST m�ter vilken maximal genomstr�mningshastighet din anslutning kan uppn� "\
	"under ideala omst�ndigheter med UDP\r\noch presenterar resultatet l�ngst ned i den "\
	"rutan. M�t g�rna vid flera olika tillf�llen f�r att f� en bra uppfattning om hur\r\n"\
	"snabb din anslutning �r.",\
	"Tillg�nglig bandbredd vid s�ndning:\r\n"\
	"Det h�r v�rdet �r resultatet av TCP-m�tningen dividerat med resultatet av "\
	"UDP-m�tningen och anges i procent.\r\nProcentsatsen visar hur stor del av din "\
	"anslutnings kapacitet du f�r ut n�r du anv�nder en Internettj�nst som utnyttjar\r\n"\
	"�verf�ringsprotokollet TCP. Observera att man b�r g�ra flera m�tningar vid olika "\
	"tillf�llen f�r att f� ett tillf�rlitligt v�rde h�r.",\
	"Tillg�nglig bandbredd vid mottagning:\r\n"\
	"Det h�r v�rdet �r resultatet av TCP-m�tningen dividerat med resultatet av "\
	"UDP-m�tningen och anges i procent.\r\nProcentsatsen visar hur stor del av din "\
	"anslutnings kapacitet du f�r ut n�r du anv�nder en Internettj�nst som utnyttjar\r\n"\
	"�verf�ringsprotokollet TCP. Observera att man b�r g�ra flera m�tningar vid olika "\
	"tillf�llen f�r att f� ett tillf�rlitligt v�rde h�r.",\
	"Tryck p� denna knapp f�r att starta TPTEST med de inst�llningar vi rekommenderar",\
	"Tryck p� denna knapp f�r att starta TPTEST med dina egna inst�llningar ovan",\
	"Detta �r adressen till testservern du har valt",\
	"Denna ruta visar hur stor del av din maximala m�jliga bandbredd du faktiskt\r\n"\
	"f�r n�r du t.ex. surfar. V�rdet �r resultatet av TCP testet dividerat med\r\n"\
	"resultatet av UDP testet och anges som ett procenttal.",\
	"Denna stapel visar hur l�ngt ett deltest har kommit. Observera att varje\r\n"\
	"g�ng du trycker p� start knappen k�rs ett antal test s� denna stapel visar\r\n"\
	"inte hur l�ngt hela testsessionen har kommit."\
};

#define DISPLAYINFO "Tryck p� \"Starta standardtest\" om du vill testa med de inst�llningar vi rekommenderar\r\n"\
	"Tryck p� \"Starta test\" om du vill testa med egna inst�llningar"


#define DISPLAYINFO1 "Testar TCP S�ndning - Tryck p� AVBRYT om du vill avbryta testet"
#define DISPLAYINFO2 "Testar TCP Mottagning - Tryck p� AVBRYT om du vill avbryta testet"
#define DISPLAYINFO3 "Testar UDP S�ndning - Tryck p� AVBRYT om du vill avbryta testet"
#define DISPLAYINFO4 "Testar UDP Mottagning - Tryck p� AVBRYT om du vill avbryta testet"

#define ABOUTTEXT "TPTEST 3.0 har utvecklats av Ragnar L�nn <ragnar@gatorhole.se>.\r\n"\
	"TPTEST st�ds och finansieras av II-stiftelsen (www.iis.se), Konsumentverket \r\n"\
	"(www.konsumentverket.se) och Post- och Telestyrelsen (www.pts.se)\r\n"\
	"\r\n"\
	"Stiftelsen Internetinfrastruktur (II-stiftelsen), Konsumentverket,\r\n"\
	"Post- och Telestyrelsen, IT-kommissionen, IP Performance Sverige AB,\r\n"\
	"Autonomica AB eller Netnod Internet Exchange AB ansvarar inte f�r att de\r\n"\
	"testresultat som levereras av TPTEST �r korrekta. Stiftelsen \r\n"\
	"Internetinfrastruktur (II-stiftelsen), Konsumentverket, Post- och Telestyrelsen,\r\n"\
	"IT-kommissionen, IP Performance Sverige AB, Autonomica AB eller Netnod\r\n"\
	"Internet Exchange AB ansvarar inte f�r drifts�kerhet och tillg�nglighet avseende\r\n"\
	"m�tservrar eller masterserver, och inte heller f�r att TPTEST fortl�pande finns\r\n"\
	"tillg�ngligt, f�r att det fortl�pande finns anv�ndarst�d eller f�r uppdateringar\r\n"\
	"av programmet.\r\n"\
	"\r\n"\
	"Varje anv�ndare ansvarar sj�lv f�r att programmet �r korrekt konfigurerat f�r den\r\n"\
	"egna datorn. Stiftelsen Internetinfrastruktur (II-stiftelsen), Konsumentverket,\r\n"\
	"Post- och Telestyrelsen, IT-kommissionen, IP Performance Sverige AB, \r\n"\
	"Autonomica AB eller Netnod Internet Exchange AB tar inte ansvar f�r \r\n"\
	"klientprogrammets funktion i den individuella driftmilj�n eller f�r fel som\r\n"\
	"programmet orsakar i operativsystem, andra applikationer eller h�rdvara, inte\r\n"\
	"heller f�r skada som anv�ndaren orsakar p� andra datorer genom anv�ndningen\r\n"\
	"av TPTEST.\r\n"

// Default contact info if it can't be retrieved from the master server
#define TPTEST_INFO	"TPTEST - Bandbreddstestaren\n"\
	"Email: bandbreddstest@iis.se\n"\
	"WWW: http://tptest.iis.se/\n"

#define TPTEST_HELP ""\
"Stiftelsen Internetinfrastruktur (II-stiftelsen), Konsumentverket,\r\n"\
"Post- och Telestyrelsen, IT-kommissionen, IP Performance Sverige AB,\r\n"\
"Autonomica AB eller Netnod Internet Exchange AB ansvarar inte f�r att de\r\n"\
"testresultat som levereras av TPTEST �r korrekta. Stiftelsen\r\n"\
"Internetinfrastruktur (II-stiftelsen), Konsumentverket, IT-kommissionen,\r\n"\
"IP Performance Sverige AB, Autonomica AB eller Netnod Internet Exchange AB\r\n"\
"ansvarar inte f�r drifts�kerhet och tillg�nglighet avseende m�tservrar eller\r\n"\
"masterserver, och inte heller f�r att TPTEST fortl�pande finns tillg�ngligt,\r\n"\
"f�r att det fortl�pande finns anv�ndarst�d eller f�r uppdateringar av programmet.\r\n"\
"\r\n"\
"Varje anv�ndare ansvarar sj�lv f�r att programmet �r korrekt konfigurerat f�r den\r\n"\
"egna datorn. Stiftelsen Internetinfrastruktur (II-stiftelsen), Konsumentverket,\r\n"\
"Post- och Telestyrelsen, IT-kommissionen, IP Performance Sverige AB, Autonomica AB\r\n"\
"eller Netnod Internet Exchange AB tar inte ansvar f�r klientprogrammets funktion i\r\n"\
"den individuella driftmilj�n eller f�r fel som programmet orsakar i operativsystem,\r\n"\
"andra applikationer eller h�rdvara, inte heller f�r skada som anv�ndaren orsakar\r\n"\
"p� andra datorer genom anv�ndningen av TPTEST.\r\n"\
"\r\n"\
"\r\n"\
"\r\n"\
"Bruksanvisning f�r programmet TPTEST version 3.0\r\n"\
"\r\n"\
"Inneh�ll:\r\n"\
"\r\n"\
"1	Vad TPTEST m�ter\r\n"\
"2	Anslutningar med olika hastigheter vid s�ndning och mottagning\r\n"\
"3	TPTEST - huvudl�gen\r\n"\
"4	Enkelt l�ge\r\n"\
"5	Avancerat l�ge\r\n"\
"6	Utskrift av m�tresultat\r\n"\
"8	Vad g�r man om m�tningen inte fungerar eller ger ett resultat som man\r\n"\
"	inte f�rv�ntat sig?\r\n"\
"\r\n"\
"\r\n"\
"1	Vad TPTEST m�ter\r\n"\
"\r\n"\
"Programmet TPTEST m�ter genomstr�mningshastigheten, dvs. bandbredden (bit/s),\r\n"\
"till respektive fr�n den m�tserver som anv�nds f�r m�tningen. Genomstr�mningen\r\n"\
"�r vanligen l�gre �n anslutningshastigheten. Fr�n och med TPTEST version 2.01\r\n"\
"utf�rs m�tningar av genomstr�mningshastigheten med b�de transportprotokollen\r\n"\
"TCP- och UDP.\r\n"\
"\r\n"\
"Ut�ver vilket av transportprotokollen som anv�nds �r det flera faktorer som\r\n"\
"avg�r vilken genomstr�mningshastighet du f�r. De viktigaste faktorerna �r\r\n"\
"anslutningshastigheten, accessn�tet, operat�rens n�t och belastning i n�tet.\r\n"\
"TPTEST f�rs�ker undvika en rad k�nda k�llor till fel som kan f�rekomma vid\r\n"\
"prestandam�tningar genom att g�ra m�tningarna mot en s�rskild m�tserver, dvs.\r\n"\
"en server som endast anv�nds f�r bandbreddsm�tningen. En m�tserver �r placerad\r\n"\
"p� en s� operat�rsneutral punkt som m�jligt i Sverige, n�mligen vid den\r\n"\
"nationella knutpunkten i Stockholm, vilken �r en av de platser d�r trafikutbyte\r\n"\
"sker mellan Internetoperat�rer. Andra m�tservrar kan vara anslutna i \r\n"\
"operat�rernas n�t. Antalet m�tservrar kan variera. Av programmet framg�r vilka\r\n"\
"servrar som kan anv�ndas f�r m�tningen. Hur man v�ljer m�tserver behandlas nedan.\r\n"\
"\r\n"\
"\r\n"\
"2	Anslutningar med olika hastigheter vid s�ndning och mottagning\r\n"\
"\r\n"\
"Det finns Internetanslutningar som har olika hastigheter vid s�ndning och\r\n"\
"mottagning (s.k. asymmetriska anslutningar). Exempel p� s�dana anslutningar �r\r\n"\
"ADSL och kabel-TV d�r mottagningshastigheten vanligen �r h�gre �n\r\n"\
"s�ndningshastigheten.\r\n"\
"\r\n"\
"Det kan vara mottagningshastigheten vid TCP som �r det mest intressanta att m�ta\r\n"\
"beroende p� att den �r en viktig faktor n�r det g�ller hur snabbt du f�r\r\n"\
"exempelvis webbsidor till din dator. S� om du vid en m�tning av \r\n"\
"s�ndningshastigheten f�r mycket l�gre v�rde �n vid m�tning av\r\n"\
"mottagningshastigheten beh�ver det inte betyda att det �r n�got fel p� din\r\n"\
"anslutning. S�ndning och mottagning behandlas vidare nedan.\r\n"\
"\r\n"\
"3	TPTEST - huvudl�gen\r\n"\
"\r\n"\
"Programmet har tv� huvudl�gen: Enkelt l�ge och avancerat l�ge.\r\n"\
"\r\n"\
"Enkelt l�ge erh�lls automatiskt n�r programmet startas.\r\n"\
"\r\n"\
"4	Enkelt l�ge\r\n"\
"\r\n"\
"N�r du startar TPTEST f�r du upp ett f�nster som best�r av ett antal f�lt med\r\n"\
"olika knappar och alternativ att v�lja mellan.\r\n"\
"\r\n"\
"Vid enkelt l�ge kan du g�ra tv� olika typer av m�tningar:\r\n"\
"\r\n"\
"- Standardtest. Vilket inneb�r att m�tning utf�rs med de inst�llningar vi\r\n"\
"  rekommenderar.\r\n"\
"- Test med val. Detta alternativ anges i f�ltet Vad vill du test? Test med val\r\n"\
"  inneb�r att du sj�lv v�ljer den m�tserver som ska anv�ndas och vilken typ av\r\n"\
"  m�tning som ska utf�ras (b�de s�ndning och mottagning, enbart s�ndning eller\r\n"\
"  enbart mottagning).\r\n"\
"\r\n"\
"Vid b�de standardtest och test med val presenteras resultatet av m�tningen i\r\n"\
"resultatf�ltet till h�ger.\r\n"\
"\r\n"\
"H�gst upp finns ett f�lt f�r meddelanden. H�ller du muspekaren �ver en rubrik\r\n"\
"eller en knapp visas ett meddelande i detta f�lt. Exempelvis st�r det vid start\r\n"\
"av TPTEST:\r\n"\
"Tryck p� \"Starta standardtest\" om du vill testa med de inst�llningar vi\r\n"\
"rekommenderar.\r\n"\
"Tryck p� \"Starta test\" om du vill testa med egna inst�llningar.\r\n"\
"\r\n"\
"4.1	Testa med standardinst�llningar\r\n"\
"\r\n"\
"Testen inneb�r att m�tningen alltid utf�rs med de inst�llningar vi rekommenderar.\r\n"\
"Detta betyder att m�tningarna alltid sker till/fr�n den m�tserver som �r placerad\r\n"\
"vid knutpunkten i Stockholm, samt att b�de s�ndnings- och mottagningshastigheten\r\n"\
"m�ts.\r\n"\
"\r\n"\
"F�r att starta m�tningen beh�ver du bara trycka p� den stora knappen Starta\r\n"\
"standardtest som finns uppe till v�nster. Efter start omvandlas startknappen till\r\n"\
"en Avbryt-knapp.\r\n"\
"\r\n"\
"TPTEST utf�r alltid ett antal m�tningar. M�tningarna forts�tter till det att den\r\n"\
"h�gsta hastighet uppn�s. Detta g�ller b�de f�r TCP och UDP.\r\n"\
"\r\n"\
"4.2	Test med egna inst�llningar\r\n"\
"\r\n"\
"I f�ltet d�r det st�r \"Vad vill du testa?\" kan du sj�lv v�lja b�de vilken\r\n"\
"m�tserver som ska anv�ndas och vilken typ av m�tning som ska utf�ras, det vill\r\n"\
"s�ga b�de s�ndning och mottagning, bara s�ndning eller bara mottagning.\r\n"\
"\r\n"\
"N�r du valt hur du vill m�ta startar du med knappen \"Starta test\" l�ngst\r\n"\
"ned i f�ltet.\r\n"\
"\r\n"\
"TPTEST utf�r alltid ett antal m�tningar. M�tningarna forts�tter till det att den\r\n"\
"h�gsta hastigheten har uppn�tts. Detta g�ller b�de f�r TCP och UDP.\r\n"\
"\r\n"\
"Om den m�tserver som valts inte st�djer TCP-m�tning utf�rs bara UDP-m�tningar (vilket\r\n"\
"beror p� att m�tservern anv�nder en tidigare version av serverprogrammet).\r\n"\
"\r\n"\
"4.3	Resultat av test\r\n"\
"\r\n"\
"N�r m�tningen �r klar f�r du alltid upp en pop-up-ruta som anger detta.\r\n"\
"\r\n"\
"I f�ltet Resultat presenteras resultatet av m�tningen. F�ltet best�r av tre delf�lt.\r\n"\
"Dessa �r m�rkta TCP, UDP och Tillg�nglig bandbredd. M�tresultaten �r de ungef�rligt\r\n"\
"st�rsta genomstr�mningshastigheter som erh�lls vid TCP respektive UDP.\r\n"\
"\r\n"\
"I delf�lten TCP repektive UDP anges dels den hastighet som testas (v�rden som anges\r\n"\
"under m�tningen), dels den h�gsta uppn�dda hastigheten vid s�ndning respektive\r\n"\
"mottagning.\r\n"\
"\r\n"\
"N�r m�tningen �r klar anges i delf�ltet Tillg�nglig bandbredd TCP-v�rdet dividerat med\r\n"\
"UDP-v�rdet i procent (TCP-v�rdet/UDP-v�rdet * 100). Procentv�rdet anger hur stor del av\r\n"\
"UDP-kapaciteten som vid m�tningstillf�llet kan anv�ndas f�r s�dana till�mpningar som\r\n"\
"anv�nder TCP-protokollet, dvs. hur mycket som kan anv�nds f�r exempelvis webbtrafik\r\n"\
"(surfning), fil�verf�ring och e-post.\r\n"\
"\r\n"\
"Eftersom TCP-v�rdet varierar mycket beroende p� n�tets belastning ska man\r\n"\
"betrakta TCP-v�rdet som ett momentant (tillf�lligt, just nu-) v�rde, vilket\r\n"\
"betyder att det kan variera fr�n g�ng till g�ng. M�t d�rf�r flera g�nger vid\r\n"\
"olika tidpunkter f�r att f� en s�ker uppfattning om Internettj�nstens\r\n"\
"kapacitet.\r\n"\
"\r\n"\
"Dessutom g�ller att den faktiska hastigheten (nedladdingstiden) du f�r n�r du\r\n"\
"exempelvis laddar hem en webbsida fr�n en webbserver �ven �r beroende av andra\r\n"\
"faktorer, exempelvis prestanda och belastning p� webbservern du laddar hem\r\n"\
"sidan fr�n, samt hur mycket data webbsidan inneh�ller.\r\n"\
"\r\n"\
"5	Avancerat l�ge\r\n"\
"\r\n"\
"Avancerat l�ge n�r du via \"Arkiv\" menyn l�ngst upp till v�nster. Avancerat\r\n"\
"l�ge �r avsett f�r de som har god kunskap om Internetkommunikation och vill\r\n"\
"g�ra mer avancerade m�tningar �n de i enkelt l�ge.\r\n"\
"\r\n"\
"I avancerat l�ge finns en m�ngd val du kan g�ra. H�gst upp anges den masterserver\r\n"\
"programmet anv�nder sig av (masterservern �r en del av m�tsystemet f�r TPTEST).\r\n"\
"Dessutom anges portnumret f�r masterservern. Masterservern tillhandah�ller en\r\n"\
"lista med aktuella m�tservrar n�r du trycker p� \"H�mta testserverlista\"-knappen.\r\n"\
"Listan visas sedan i listboxen nedanf�r knappen och du kan d�refter v�lja en av\r\n"\
"servrarna genom att klicka p� den. Under listboxen anges adressen till vald\r\n"\
"m�tserver och serverns portnummer.\r\n"\
"\r\n"\
"I avancerat l�ge kan du g�ra b�de TCP- och UDP-m�tningar.\r\n"\
"\r\n"\
"F�r b�de TCP och UDP kan du utf�ra m�tning av s�ndnings- och \r\n"\
"mottagningshastigheten. Vid UDP kan du �ven utf�ra en s� kallad\r\n"\
"Full duplex-m�tning (se nedan under UDP-test).\r\n"\
"\r\n"\
"Testtiden i sekunder:\r\n"\
"\r\n"\
"�	Vid UDP kan testtiden v�ljas mellan 1 - 30 sekunder.En l�mplig testtid �r\r\n"\
"	i de flesta fall 10 - 20 sekunder.\r\n"\
"�	F�r att f� ett tillf�rlitligt m�tresultat vid TCP m�ste en TCP-m�tning p�g�\r\n"\
"	minst 10 sekunder. Detta inneb�r att du m�ste v�lja ett v�rde p� den datam�ngd\r\n"\
"	(bytes) som ska �verf�ras s� att testtiden blir minst 10 sekunder (se nedan).\r\n"\
"�	Vid TCP b�r testtid v�ljas till minsta 10 sekunder.\r\n"\
"\r\n"\
"5.1	TCP-test\r\n"\
"\r\n"\
"H�r anges den datam�ngd i byte som ska �verf�ras. F�r att erh�lla ett\r\n"\
"tillf�rlitligt m�tresultat m�ste en TCP-m�tning p�g� i minst 10 sekunder.\r\n"\
"(Detta beror p� att buffring av data som sker i de inblandade\r\n"\
"TCP/IP-programmen). Det v�rde i bytes som ska anges beror s�ledes p� vilken\r\n"\
"kapacitet anslutningen har varifr�n m�tningen sker.\r\n"\
"Exempel: Anslutningshastigheten �r 512 kbit/s. Den datam�ngd i bytes som\r\n"\
" b�r anges f�r att f� en m�ttid p� minst 10 sekunder �r minst 640 000 bytes\r\n"\
"(hastigheten i bit/s / 8 * 10).\r\n"\
 "\r\n"\
"Starta m�tningen med \"Start\"-knappen. N�r m�tningen startat f�r du i rutan\r\n"\
"till h�ger l�pande veta vad som h�nder.\r\n"\
"\r\n"\
"5.2	UDP-test\r\n"\
"\r\n"\
"F�r UDP-m�tningar kan du v�lja paket per sekund, paketstorlek och datahastighet.\r\n"\
"�ndrar du paketstorlek eller paket per sekund kommer datahastigheten automatiskt att\r\n"\
"�ndras.\r\n"\
"\r\n"\
"�ndrar du datahastigheten kommer TPTEST att �ndra paketstorlek och/eller antal paket per\r\n"\
"sekund s� det matchar den valda datahastigheten s� bra som m�jligt. TPTEST f�rs�ker om\r\n"\
"m�jligt h�lla paketstorleken under 1500 bytes eftersom det hindrar att paketen fragmenteras\r\n"\
"(delas upp) n�r de ska transporteras �ver Ethernet.\r\n"\
"\r\n"\
"M�tningen startas med \"Start\"-knappen. N�r m�tningen startat f�r du i rutan\r\n"\
"till h�ger l�pande veta vad som h�nder.\r\n"\
"\r\n"\
"5.3	S�ndning\r\n"\
"\r\n"\
"S�ndning inneb�r att TPTEST (anv�ndarens program) s�nder datapaket till m�tservern.\r\n"\
"\r\n"\
"H�r kommenteras n�gra av de m�tresultat som erh�lls i resultatf�ltet till h�ger:\r\n"\
"\r\n"\
"Type of test: TCP transmit respektive UDP transmit.\r\n"\
"\r\n"\
"Send statistics\r\n"\
"  Bits/second sent: H�r anges med vilken hastighet TPTEST s�nder datapaketen.\r\n"\
"\r\n"\
"Receive statistics\r\n"\
"  Bit/second received: H�r anges med vilken hastighet m�tservern tar emot data.\r\n"\
"\r\n"\
"Lost packets (endast vid UDP-test)\r\n"\
"  Total packets lost : Man b�r observera att detta v�rde ska vara 0 eller maximalt\r\n"\
"  n�gon procent. Om ett stort antal paket f�rloras, vilket betyder att en stor del av\r\n"\
"  de data som ska �verf�rs inte kommer fram till mottagaren, beror det troligen p�\r\n"\
"  att du valt en alltf�r h�g hastighet. Du b�r d�rf�r g�ra en ny m�tning med en l�gre\r\n"\
"  hastighet.\r\n"\
"\r\n"\
"5.4	Mottagning\r\n"\
"\r\n"\
"Mottagning inneb�r att m�tservern s�nder datapaket till TPTEST (anv�ndarens program).\r\n"\
"\r\n"\
"H�r kommenteras n�gra av de m�tresultat som erh�lls i resultatf�ltet till h�ger:\r\n"\
"\r\n"\
"Type of test: TCP Receive respektive UDP Receive.\r\n"\
"\r\n"\
"Send statistics\r\n"\
"  Bits/second sent: H�r anges med vilken hastighet m�tservern s�nder datapaketen.\r\n"\
"\r\n"\
"Receive statistics\r\n"\
"  Bit/second received: H�r anges med vilken hastighet TPTEST (anv�ndarens program)\r\n"\
"  tar emot data.\r\n"\
"\r\n"\
"Lost packets (endast vid UDP)\r\n"\
"  Total packets lost: Detta v�rde b�r vara 0 eller maximalt n�gon procent. Om ett stort\r\n"\
"  antal paket f�rloras, vilket betyder att en stor del av de data som ska �verf�ras\r\n"\
"  inte kommer fram till mottagaren, beror det troligen p� att du valt en alltf�r h�g\r\n"\
"  hastighet. Du b�r d�rf�r g�ra en ny m�tning med en l�gre hastighet.\r\n"\
"\r\n"\
"5.5	Full duplex\r\n"\
"\r\n"\
"Full duplex kan endast utf�ras vid UDP. Full duplex �r en kombinerad s�ndning och\r\n"\
"mottagning. Hastigheten begr�nsas av den l�gsta kapaciteten, antingen\r\n"\
"s�ndning eller mottagning).\r\n"\
"\r\n"\
"Vid full duplex s�nder TPTEST (anv�ndarens program) alltid datapaket till m�tservern\r\n"\
"som omedelbart returnerar varje mottaget datapaket. TPTEST h�ller reda p� n�r varje\r\n"\
"datapaket s�nds och kan p� s� s�tt, f�rutom genomstr�mningshastigheten, ange svarstider,\r\n"\
"dvs. hur l�ng tid det tar f�r ett paket att s�ndas fr�n din dator till m�tservern och\r\n"\
"tillbaka (s.k. roundtrip delay). Roundtrip delay anges endast vid full duplex.\r\n"\
"\r\n"\
"H�r kommenteras n�gra av de m�tresultat som erh�lls i rutan till h�ger:\r\n"\
"\r\n"\
"Roundtrip statistics:\r\n"\
"  Min roundtrip delay: Den minsta f�rdr�jningen, ms.\r\n"\
"  Max roundtrip delay: Den st�rsta f�rdr�jningen, ms.\r\n"\
"  Avg roundtrip delay: Genomsnittlig f�rdr�jning, ms.\r\n"\
"\r\n"\
"6	Utskrift av m�tresultat\r\n"\
"\r\n"\
"Du kan skriva ut m�tresultaten direkt p� en skrivare. Utskriftsfunktionen finner du\r\n"\
"under \"Arkiv\" menyn l�ngst uppe till v�nster.\r\n"\
"\r\n"\
"7	Att t�nka p� n�r du v�ljer v�rden f�r m�tningen\r\n"\
"\r\n"\
"N�gra saker att t�nka p� n�r du v�ljer v�rden f�r m�tningen i Avancerat l�ge.\r\n"\
"Om du anger f�r h�ga v�rden s� att din anslutning �verbelastas kommer du att f�\r\n"\
"stora paketf�rluster och f�rmodligen v�ldigt d�liga m�tresultat. Det b�sta �r\r\n"\
"att prova olika hastigheter, en i taget, tills du hittar den som ger dig b�st\r\n"\
"m�tresultatet, dvs. den h�gsta genomstr�mningshastigheten.\r\n"\
"\r\n"\
"Om du vill se vad du har f�r svarstider (roundtrip delay) till och fr�n m�tservern b�r\r\n"\
"du prova med en s� liten paketstorlek som m�jligt s� inte svarstiden p�verkas f�r\r\n"\
"mycket av att det tar tid att �verf�ra all den data paketet inneh�ller.\r\n"\
"\r\n"\
"F�r UDP-m�tningar �r 10 - 20 sekunder i de flesta fall en l�mplig testtid.\r\n"\
"Notera att m�tservern kan v�gra utf�ra en m�tning d�r n�gon parameter f�r m�tningen\r\n"\
"st�lls in p� ett alltf�r extremt v�rde, om man till exempel f�rs�ker m�ta i\r\n"\
"24 timmar eller anger att m�tservern ska s�nda med hastigheten 200 Mbit/s.\r\n"\
"\r\n"\
"8	Vad g�r man om m�tningen inte fungerar eller ger ett resultat man\r\n"\
"   inte f�rv�ntat sig?\r\n"\
"\r\n"\
"Det kan finnas flera orsaker till att en m�tning inte fungerar eller inte ger ett\r\n"\
"f�rv�ntat resultat.\r\n"\
"\r\n"\
"Om din dator till exempel �r skyddad av en brandv�gg finns det stor risk att du inte\r\n"\
"kan m�ta mottagningshastigheten eller den kombinerade s�ndnings- och\r\n"\
"mottagningshastigheten. Prova att m�ta bara s�ndningshastigheten och se om det\r\n"\
"verkar fungera.\r\n"\
"\r\n"\
"Om du inte har en fungerande Internetanslutning kommer sj�lvfallet m�tningen att\r\n"\
"misslyckas.\r\n"\
"\r\n"\
"Om du t.ex. anv�nder en ADSL-anslutning eller en anslutning via kabel-TV och f�r en\r\n"\
"mycket h�gre hastighet vid mottagning �n vid s�ndning �r det f�rmodligen helt\r\n"\
"normalt.\r\n"\
"\r\n"\
"Till sist ett generellt r�d:\r\n"\
"Ju mer man m�ter, desto mer vet man. En enstaka m�tning kan det vara sv�rt att\r\n"\
"utl�sa n�got fr�n. I Hj�lp-menyn under rubriken \"Kontaktinfo\" finns adresser\r\n"\
"till de webbplatser som g�ller TPTEST. D�r kan du dels hitta den senaste\r\n"\
"versionen av programmet, dels f� fler r�d om hur man b�r anv�nda programmet f�r att\r\n"\
"f� b�sta m�jliga resultat.\r\n"\
"\r\n"\
"\r\n"\



#endif	/* !ENGLISH */


#endif /* _TPTEST_H_ */
