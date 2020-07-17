# Microsoft Developer Studio Project File - Name="WordGLXT" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WordGLXT - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WordGLXT.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WordGLXT.mak" CFG="WordGLXT - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WordGLXT - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WordGLXT - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WordGLXT - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "WordGLXT - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"../Lib"

!ENDIF 

# Begin Target

# Name "WordGLXT - Win32 Release"
# Name "WordGLXT - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialogin.cpp
# End Source File
# Begin Source File

SOURCE=.\Dwdandlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Dwxxb.cpp
# End Source File
# Begin Source File

SOURCE=.\FileAttri.cpp
# End Source File
# Begin Source File

SOURCE=.\KLxgdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\msword9.cpp
# End Source File
# Begin Source File

SOURCE=.\Rizhib.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Users.cpp
# End Source File
# Begin Source File

SOURCE=.\WDgldlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Wdlbiedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WordGLXT.cpp
# End Source File
# Begin Source File

SOURCE=.\WordGLXT.rc
# End Source File
# Begin Source File

SOURCE=.\WordGLXTDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\YHgldlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Zdmlb.cpp
# End Source File
# Begin Source File

SOURCE=.\Zdxxb.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\Dialogin.h
# End Source File
# Begin Source File

SOURCE=.\Dwdandlg.h
# End Source File
# Begin Source File

SOURCE=.\Dwxxb.h
# End Source File
# Begin Source File

SOURCE=.\FileAttri.h
# End Source File
# Begin Source File

SOURCE=.\KLxgdlg.h
# End Source File
# Begin Source File

SOURCE=.\msword9.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Rizhib.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Users.h
# End Source File
# Begin Source File

SOURCE=.\WDgldlg.h
# End Source File
# Begin Source File

SOURCE=.\Wdlbiedlg.h
# End Source File
# Begin Source File

SOURCE=.\WordGLXT.h
# End Source File
# Begin Source File

SOURCE=.\WordGLXTDlg.h
# End Source File
# Begin Source File

SOURCE=.\YHgldlg.h
# End Source File
# Begin Source File

SOURCE=.\Zdmlb.h
# End Source File
# Begin Source File

SOURCE=.\Zdxxb.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\03.ico
# End Source File
# Begin Source File

SOURCE=.\res\71.ico
# End Source File
# Begin Source File

SOURCE=.\res\84.ico
# End Source File
# Begin Source File

SOURCE=.\res\86.ico
# End Source File
# Begin Source File

SOURCE=.\res\aa.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bb.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Blue Glass Folders Icon 13.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Blue Glass Folders Icon 17.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Blue Glass Folders Icon 2.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Blue Glass Folders Icon 22.ico"
# End Source File
# Begin Source File

SOURCE=.\res\cc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\close.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dd.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ee.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ff.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FLD302.ICO
# End Source File
# Begin Source File

SOURCE=.\res\FLD305.ICO
# End Source File
# Begin Source File

SOURCE=".\res\G2 Folder Blue.ico"
# End Source File
# Begin Source File

SOURCE=.\res\gg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\HH.bmp
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\queren.bmp
# End Source File
# Begin Source File

SOURCE=.\res\quxiao.bmp
# End Source File
# Begin Source File

SOURCE=.\res\saikin_fol.ico
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\up.bmp
# End Source File
# Begin Source File

SOURCE=.\res\up01.bmp
# End Source File
# Begin Source File

SOURCE=.\res\up02.bmp
# End Source File
# Begin Source File

SOURCE=.\res\WordGLXT.ico
# End Source File
# Begin Source File

SOURCE=.\res\WordGLXT.rc2
# End Source File
# Begin Source File

SOURCE=".\res\world图标.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\备份数据.ico"
# End Source File
# Begin Source File

SOURCE=".\res\标题栏.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\查看属性.ico"
# End Source File
# Begin Source File

SOURCE=".\res\查看文件属性.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\单位档案.ico"
# End Source File
# Begin Source File

SOURCE=".\res\登录.ico"
# End Source File
# Begin Source File

SOURCE=".\res\登录界面.BMP"
# End Source File
# Begin Source File

SOURCE=".\res\关闭按钮变前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\豪华包房.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\口令修改.ico"
# End Source File
# Begin Source File

SOURCE=".\res\口令修改.ico"
# End Source File
# Begin Source File

SOURCE=".\res\普通登录1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\日志管理.ico"
# End Source File
# Begin Source File

SOURCE=".\res\删除.ico"
# End Source File
# Begin Source File

SOURCE=".\res\删除文档.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\删除文档].ico"
# End Source File
# Begin Source File

SOURCE=".\res\数据备份.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\数据恢复.ico"
# End Source File
# Begin Source File

SOURCE=".\res\添加.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\添加文档.ico"
# End Source File
# Begin Source File

SOURCE=".\res\添加文档.ico"
# End Source File
# Begin Source File

SOURCE=".\res\退出.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\退出系统.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\文档类别.ico"
# End Source File
# Begin Source File

SOURCE=".\res\修改.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\修改文档.ico"
# End Source File
# Begin Source File

SOURCE=".\res\修改文档.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\用户管理.ico"
# End Source File
# Begin Source File

SOURCE=".\res\用户管理.ico"
# End Source File
# Begin Source File

SOURCE=".\res\工具栏图标\浏览文档.ico"
# End Source File
# End Group
# End Target
# End Project
