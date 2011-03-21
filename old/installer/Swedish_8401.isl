; Translation made with Ini Translator 1.4b
;
; *** Inno Setup version 4.0.0+ Swedish messages ***
;
; Translated by stefan@bodingh.se
; -------+---------+---------+---------+---------+---------+---------+---------
; Translators notes (for Swedes only :)
;
; Rev 030501: 4.0.0 av stefan@bodingh.se
; Rev 020903: 3.0.3 av soren.edzen@frontec.se
; Rev 020602: 3.0.2 av peter@peterandlinda.com
; Rev 010508: 2.0.8 av peter.kind@telia.com
; Rev 001019: 1.3.21 av peter.kind@telia.com
; Rev 000428: 1.3x
; Rev 991028: Sm�rre �ndringar.
; Rev 990927: Nytt
;LanguageName=Swedish
;LanguageID=$041D
[Messages]

; *** Application titles
SetupAppTitle=Installation
SetupWindowTitle=Installation - %1
UninstallAppTitle=Avinstallation
UninstallAppFullTitle=%1 Avinstallation

; *** Misc. common
InformationTitle=Information
ConfirmTitle=Bekr�fta
ErrorTitle=Fel

; *** SetupLdr messages
SetupLdrStartupMessage=Detta installerar %1. Vill du forts�tta?
LdrCannotCreateTemp=Kan ej skapa en tempor�r fil. Installationen avbryts
LdrCannotExecTemp=Kan inte k�ra fil i tempor�r mapp. Installationen avbryts

; *** Startup error messages
LastErrorMessage=%1.%n%nFel %2: %3
SetupFileMissing=Filen %1 saknas i installationsmappen. R�tta till problemet eller h�mta en ny kopia av programmet.
SetupFileCorrupt=Installationsfilerna �r felaktiga. H�mta en ny kopia av programmet
SetupFileCorruptOrWrongVer=Installationsfilerna �r felaktiga, eller st�mmer ej �verens med denna version av installationsprogrammet. R�tta felet eller h�mta en ny programkopia.
NotOnThisPlatform=Detta program kan ej k�ras p� %1.
OnlyOnThisPlatform=Detta program kr�ver %1.
WinVersionTooLowError=Detta program kr�ver %1, version %2 eller senare.
WinVersionTooHighError=Programmet kan inte installeras p� %1 version %2 eller senare.
AdminPrivilegesRequired=Du m�ste vara inloggad som administrat�r n�r du installerar detta program.
PowerUserPrivilegesRequired=Du m�ste vara inloggad som administrat�r eller medlem av gruppen Privilegierade anv�ndare (Power Users) n�r du installerar detta program.
SetupAppRunningError=Installationsprogrammet har uppt�ckt att %1 k�rs f�r tillf�llet.%n%nSt�ng all �ppna instanser av det nu, klicka sedan p� OK f�r att g� vidare, eller Avbryt f�r att avsluta.
UninstallAppRunningError=Avinstallera har uppt�ckt att %1 k�rs f�r tillf�llet.%n%nSt�ng all �ppna instanser av det nu, klicka sedan p� OK f�r att g� vidare, eller Avbryt f�r att avsluta.

; *** Misc. errors
ErrorCreatingDir=Installationsprogrammet kunde inte skapa mappen "%1"
ErrorTooManyFilesInDir=Kunde inte skapa en fil i mappen "%1" d�rf�r att den inneh�ller f�r m�nga filer

; *** Setup common messages
ExitSetupTitle=Avsluta installationen
ExitSetupMessage=Installationen �r inte f�rdig. Om du slutar nu, kommer programmet inte att installeras.%n%nDu kan starta installationsprogrammet igen senare om du vill slutf�ra den d� ist�llet.%n%nVill du avbryta installationen?
AboutSetupMenuItem=Om installationen...
AboutSetupTitle=Om installationen
AboutSetupMessage=%1 version %2%n%3%n%n%1 hemsida:%n%4
AboutSetupNote=Svensk �vers�ttning �r gjord av dickg@go.to 1999, 2002%n%nUppdatering till 3.0.2+ av peter@peterandlinda.com, Kerstin & Ragnar

; *** Buttons
ButtonBack=Tillbaka
ButtonNext=N�sta
ButtonInstall=Installera
ButtonOK=OK
ButtonCancel=Avbryt
ButtonYes=Ja
ButtonYesToAll=Ja till allt
ButtonNo=Nej
ButtonNoToAll=Nej till allt
ButtonFinish=Slutf�r
ButtonBrowse=Bl�ddra...
SelectLanguageTitle=V�lj spr�k f�r installationen
SelectLanguageLabel=V�lj spr�k att anv�nda under installationen

; *** Common wizard text
ClickNext=Klicka p� N�sta f�r att forts�tta, eller Avbryt om du vill avbryta installationen.
BeveledLabel=

; *** "Welcome" wizard page
;WizardWelcome=V�lkommen
;WelcomeLabel1=V�lkommen till installationsprogrammet f�r [name].
;WelcomeLabel2=Detta kommer att installera [name/ver] p� din dator.%n%nDet rekommenderas att du avslutar alla andra program innan du forts�tter. Det f�rebygger konflikter under installationens g�ng.
; *** "Password" wizard page
WelcomeLabel1=V�lkommen till installationen av [name]
WelcomeLabel2=Installationsprogrammet kommer att installera [name] p� din dator.
WizardPassword=L�senord
PasswordLabel1=Denna installation �r skyddad med l�senord.
PasswordLabel3=Var god ange l�senordet, tryck sedan p� N�sta f�r att forts�tta. L�senord skiljer p� versaler/gemener.
PasswordEditLabel=L�senord:
IncorrectPassword=L�senordet du angav �r inkorrekt. F�rs�k igen.

; *** "License Agreement" wizard page
WizardLicense=Licensavtal
LicenseLabel=Var god l�s f�ljande viktiga information innan du forts�tter.
LicenseLabel3=Var god l�s f�ljande licensavtal. Du m�ste acceptera villkoren i avtalet innan du kan forts�tta med installationen.
LicenseAccepted=Jag accepterar avtalet
LicenseNotAccepted=Jag accepterar inte avtalet

; *** "Information" wizard pages
WizardInfoBefore=Information
InfoBeforeLabel=Var god l�s f�ljande viktiga information innan du forts�tter.
InfoBeforeClickLabel=N�r du �r klar att forts�tta med installationen, klicka p� N�sta.
WizardInfoAfter=Information
InfoAfterLabel=Var god l�s f�ljande viktiga information innan du forts�tter.
InfoAfterClickLabel=N�r du �r klar att forts�tta med installationen, klicka p� N�sta.

; *** "User Information" wizard page
WizardUserInfo=Anv�ndarinformation
UserInfoDesc=Var god fyll i f�ljande uppgifter:
UserInfoName=Namn:
UserInfoOrg=Organisation:
UserInfoSerial=Serienummer:
UserInfoNameRequired=Du m�ste fylla i ett namn.

; *** "Select Destination Directory" wizard page
WizardSelectDir=V�lj installationsmapp
SelectDirDesc=Var ska [name] installeras?
SelectDirLabel=V�lj den mapp d�r du vill att [name] ska installeras, tryck sedan p� N�sta.
DiskSpaceMBLabel=Programmet kr�ver minst [mb] MB h�rddiskutrymme.
ToUNCPathname=Installationsprogrammet kan inte installera till UNC s�kv�g. Om du f�rs�ker installera via ett n�tverk, ska du ange n�tverksenheten.
InvalidPath=Du m�ste skriva en fullst�ndig s�kv�g med enhetsbeteckning; till exempel:%C:\APP
InvalidDrive=Enheten du har valt finns inte eller �r inte tillg�nglig. V�lj en annan.
DiskSpaceWarningTitle=Ej tillr�ckligt med diskutrymme
DiskSpaceWarning=Installationsprogrammet beh�ver �tminstone %1 KB av fritt utrymme f�r installationen, men den valda enheten har bara %2 KB tillg�ngligt.%n%nVill du forts�tta �nd�?
BadDirName32=Mappens namn f�r ej inneh�lla n�got av f�ljande tecken:%n%n%1
DirExistsTitle=Mappen finns
DirExists=Mappen:%n%n%1%n%nfinns redan. Vill du �nd� forts�tta installationen till den valda mappen?
DirDoesntExistTitle=Mappen finns inte
DirDoesntExist=Mappen:%n%n%1%n%nfinns inte. Vill du skapa den?

; *** "Select Components" wizard page
WizardSelectComponents=V�lj komponenter
SelectComponentsDesc=Vilka komonenter ska installeras?
SelectComponentsLabel2=V�lj de komponenter du vill ska installeras; avmarkera de komponenter du inte vill ha. Tryck p� N�sta n�r du �r klar att forts�tta.
FullInstallation=Full installation

; if possible don't translate 'Compact' as 'Minimal' (I mean 'Minimal' in your language)
CompactInstallation=Kompakt installation
CustomInstallation=Anpassad installation
NoUninstallWarningTitle=Komponenter finns
NoUninstallWarning=Installationsprogrammet har uppt�ckt att f�ljande komponenter redan finns installerade p� din dator:%n%n%1%n%nAtt avmarkera dessa komponenter kommer inte att avinstallera dom.%n%nVill du forts�tta �nd�?
ComponentSize1=%1 KB
ComponentSize2=%1 MB
ComponentsDiskSpaceMBLabel=Aktuella val kr�ver minst [mb] MB diskutrymme.

; *** "Select Additional Tasks" wizard page
WizardSelectTasks=V�lj extra uppgifter
SelectTasksDesc=Vilka extra uppgifter ska utf�ras?
SelectTasksLabel2=V�lj extra uppgifter f�r installationsprogrammet att utf�ra vid installation av [name], tryck sedan p� N�sta.

; *** "Select Start Menu Folder" wizard page
WizardSelectProgramGroup=V�lj Startmeny-mapp
SelectStartMenuFolderDesc=Var ska installationsprogrammet placera programmets genv�gar?
SelectStartMenuFolderLabel=V�lj den Startmeny-mapp d�r du vill skapa programmets genv�gar, tryck sedan p� N�sta.
NoIconsCheck=Skapa inte ikoner
MustEnterGroupName=Du m�ste ange en mapp.
BadGroupName=Mappnamnet kan inte inneh�lla n�got av f�ljande tecken:%n%n%1
NoProgramGroupCheck2=Skapa ingen Startmeny-mapp

; *** "Ready to Install" wizard page
WizardReady=Redo att installera
ReadyLabel1=Installationsprogrammet �r nu redo att installera [name] p� din dator.
ReadyLabel2a=Tryck p� Installera om du vill forts�tta, eller g� Tillbaka om du vill se �ver eller �ndra p� n�got.
ReadyLabel2b=V�lj Installera f�r att p�b�rja installationen.
ReadyMemoUserInfo=Anv�ndarinformation:
ReadyMemoDir=Installationsmapp:
ReadyMemoType=Installationstyp:
ReadyMemoComponents=Valda komponenter:
ReadyMemoGroup=Startmeny-mapp:
ReadyMemoTasks=Extra uppgifter:

; *** "Preparing to Install" wizard page
WizardPreparing=F�rbereder installationen
PreparingDesc=Installationsprogrammet f�rbereder installationen av [name] p� din dator.
PreviousInstallNotCompleted=Installationen/avinstallationen av ett tidigare program har inte slutf�rts. Du m�ste starta om datorn f�r att avsluta den installationen.%n%nEfter att ha startat om datorn k�r du installationsprogrammet igen f�r att slutf�ra installationen av [name].
CannotContinue=Installationsprogrammet kan inte forts�tta. Klicka p� Avbryt f�r att avsluta.

; *** "Installing" wizard page
WizardInstalling=Installerar
InstallingLabel=V�nta medan [name] installeras p� din dator.

; *** "Setup Completed" wizard page
;WizardFinished=Installationen �r nu klar
FinishedHeadingLabel=Avslutar installationen av [name]
FinishedLabelNoIcons=[name] har nu installerats p� din dator.
FinishedLabel=[name] har nu installerats p� din dator. Starta programmet genom att v�lja n�gon av ikonerna.
ClickFinish=V�lj Slutf�r f�r att avsluta installationen.
FinishedRestartLabel=F�r att slutf�ra installationen av [name], m�ste din dator startas om. Vill du starta om nu?
FinishedRestartMessage=F�r att slutf�ra installationen av [name], m�ste din dator startas om.%n%nVill du starta om datorn nu?
ShowReadmeCheck=Ja, jag vill se filen L�S MIG
YesRadio=Ja, jag vill starta om datorn nu
NoRadio=Nej, jag startar sj�lv om datorn senare

; used for example as 'Run MyProg.exe'
RunEntryExec=K�r %1

; used for example as 'View Readme.txt'
RunEntryShellExec=L�s %1

; *** "Setup Needs the Next Disk" stuff
ChangeDiskTitle=Installationsprogrammet beh�ver n�sta diskett
SelectDirectory=V�lj mapp
SelectDiskLabel2=Var god s�tt i diskett %1 och tryck OK.%n%nOm filerna kan hittas i en annan mapp �n den som visas nedan, skriv in r�tt s�kv�g eller v�lj Bl�ddra.
PathLabel=S�kv�g:
FileNotInDir2=Kunde inte hitta filen "%1" i "%2". Var god s�tt i korrekt diskett eller v�lj en annan mapp.
SelectDirectoryLabel=Var god ange s�kv�gen f�r n�sta diskett.

; *** Installation phase messages
SetupAborted=Installationen slutf�rdes inte.%n%nVar god r�tta till felet och k�r Installationsprogrammet igen.
EntryAbortRetryIgnore=V�lj F�rs�k igen eller Ignorera f�r att forts�tta �nd�, Avbryt f�r att avbryta installationen.

; *** Installation status messages
StatusCreateDirs=Skapar mappar...
StatusExtractFiles=Packar upp filer...
StatusCreateIcons=Skapar programikoner...
StatusCreateIniEntries=Skriver INI-v�rden...
StatusCreateRegistryEntries=Skriver register-v�rden...
StatusRegisterFiles=Registrerar filer...
StatusSavingUninstall=Sparar information f�r avinstallation...
StatusRunProgram=Slutf�r installationen...
StatusRollback=�terst�ller �ndringar...

; *** Misc. errors
ErrorInternal2=Internt fel: %1
ErrorFunctionFailedNoCode=%1 misslyckades
ErrorFunctionFailed=%1 misslyckades; kod %2
ErrorFunctionFailedWithMessage=%1 misslyckades; kod %2.%n%3
ErrorExecutingProgram=Kan inte k�ra filen:%n%1

; *** Registry errors
ErrorRegOpenKey=Fel vid �ppning av registernyckel:%n%1\%2
ErrorRegCreateKey=Kan ej skapa registernyckel:%n%1\%2
ErrorRegWriteKey=Kan ej skriva till registernyckel:%n%1\%2

; *** INI errors
ErrorIniEntry=Kan inte skriva nytt INI-v�rde i filen "%1".

; *** File copying errors
FileAbortRetryIgnore=V�lj F�rs�k igen eller Ignorera f�r att hoppa �ver denna fil (ej rekommenderat), eller Avbryt installationen.
FileAbortRetryIgnore2=V�lj F�rs�k igen eller Ignorera och forts�tt �nd� (ej rekommenderat), eller Avbryt installationen.
SourceIsCorrupted=K�llfilen �r felaktig
SourceDoesntExist=K�llfilen "%1" finns inte
ExistingFileReadOnly=Den nuvarande filen �r skrivskyddad.%n%nV�lj F�rs�k igen f�r att ta bort skrivskyddet, Ignorera f�r att hoppa �ver denna fil, eller Avbryt installationen.
ErrorReadingExistingDest=Ett fel uppstod vid f�rs�k att l�sa den befintliga filen:
FileExists=Filen finns redan.%n%nSka installationsprogrammet skriva �ver den?
ExistingFileNewer=Den befintliga filen �r nyare �n den du f�rs�ker installera. Du rekommenderas beh�lla den befintliga filen. %n%nVill Du beh�lla den befintliga filen?
ErrorChangingAttr=Ett fel uppstod vid f�rs�k att �ndra attribut p� den befintliga filen:
ErrorCreatingTemp=Ett fel uppstod vid ett f�rs�k att skapa installationsmappen:
ErrorReadingSource=Ett fel uppstod vid ett f�rs�k att l�sa k�llfilen:
ErrorCopying=Ett fel uppstod vid kopiering av filen:
ErrorReplacingExistingFile=Ett fel uppstod vid f�rs�k att ers�tta den befintliga filen:
ErrorRestartReplace=RestartReplace misslyckades:
ErrorRenamingTemp=Ett fel uppstod vid f�rs�k att byta namn p� en fil i installationsmappen:
ErrorRegisterServer=Kunde inte registrera DLL/OCX: %1
ErrorRegisterServerMissingExport=DllRegisterServer export kunde inte hittas
ErrorRegisterTypeLib=Kunde inte registrera typbibliotek: %1

; *** Post-installation errors
ErrorOpeningReadme=Ett fel uppstod vid �ppnandet av L�S MIG-filen.
ErrorRestartingComputer=Installationsprogrammet kunde inte starta om datorn. Var god g�r det manuellt.

; *** Uninstaller messages
UninstallNotFound=Filen "%1" finns inte. Kan inte avinstallera.
UninstallOpenError=Filen "%1" kan inte �ppnas. Kan inte avinstallera.
UninstallUnsupportedVer=Avinstallationsloggen "%1" har ett inneh�ll som denna version av installationsprogrammet inte k�nner igen. Kan ej avinstallera
UninstallUnknownEntry=En felaktig rad (%1) hittades i avinstallationsloggen
ConfirmUninstall=�r du s�ker p� att du vill ta bort %1 och alla tillh�rande komponenter?
OnlyAdminCanUninstall=Denna installation kan endast avinstalleras av en anv�ndare med administrativa r�ttigheter.
UninstallStatusLabel=Var god v�nta medan %1 tas bort fr�n din dator.
UninstalledAll=%1 �r nu borttagen fr�n din dator.
UninstalledMost=Avinstallationen av %1 �r nu klar.%n%nEn del filer/mappar gick ej att ta bort. Dessa kan tas bort manuellt.
UninstalledAndNeedsRestart=F�r att slutf�ra avinstallationen av %1 m�ste datorn startas om.%n%nVill du starta om nu?
UninstallDataCorrupted=Filen "%1" �r felaktig. Kan inte avinstallera.

; *** Uninstallation phase messages
ConfirmDeleteSharedFileTitle=Ta bort delad fil?
ConfirmDeleteSharedFile2=Detta system indikerar att f�ljande delade filer inte l�ngre anv�nds av n�gra program. Vill du ta bort den delade filen?%n%n%1%n%nOm n�got program fortfarande anv�nder denna fil och den raderas, kanske programmet inte fungerar ordentligt. �r du os�ker, v�lj Nej. Det kommer inte att skada systemet.
SharedFileNameLabel=Filnamn:
SharedFileLocationLabel=Plats:
WizardUninstalling=Avinstallationsstatus
StatusUninstalling=Avinstallerar %1...
