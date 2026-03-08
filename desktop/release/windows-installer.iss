#define MyAppName "Drawing Board Pro"
#define MyAppPublisher "DrawingBoard"
#define MyAppVersion GetEnv("DRAWING_BOARD_APP_VERSION")
#if MyAppVersion == ""
  #undef MyAppVersion
  #define MyAppVersion "1.0.0"
#endif
#define MyAppExeName "DrawingBoardDesktop.exe"

[Setup]
AppId={{D08A4B6C-8D56-4D66-A3D0-3DCC8A83D9C9}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\Drawing Board Pro
DefaultGroupName=Drawing Board Pro
DisableProgramGroupPage=yes
UninstallDisplayIcon={app}\{#MyAppExeName}
OutputDir=artifacts
OutputBaseFilename=DrawingBoardPro-Setup-{#MyAppVersion}
Compression=lzma2/ultra64
SolidCompression=yes
WizardStyle=modern
PrivilegesRequired=admin
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Create desktop shortcut"; GroupDescription: "Additional tasks"; Flags: unchecked

[Files]
Source: "windows-app\*"; DestDir: "{app}"; Excludes: "*.map"; Flags: recursesubdirs createallsubdirs ignoreversion

[Icons]
Name: "{autoprograms}\Drawing Board Pro"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\Drawing Board Pro"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "Launch Drawing Board Pro"; Flags: nowait postinstall skipifsilent
