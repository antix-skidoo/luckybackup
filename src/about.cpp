/* ---------------------------------- about.cpp ---------------------------------------------------------------------------
      Class to display the about dialog

      ===============================================================================================================================
      ===============================================================================================================================
        This file is part of "luckyBackup" project
        Copyright, Loukas Avgeriou
        luckyBackup is distributed under the terms of the GNU General Public License
        luckyBackup is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.
        
        luckyBackup is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.
        
        You should have received a copy of the GNU General Public License
        along with luckyBackup.  If not, see <http://www.gnu.org/licenses/>.

        project version   : Please see "main.cpp" for project version

        developer         : luckyb 
        last modified     : 2 Nov 2018
      ===============================================================================================================================
      ===============================================================================================================================
*/
#include "about.h"
#include "global.h"

// class aboutDialog Constructor=================================================================================================
// Displays a simple about dialog
aboutDialog::aboutDialog (QUrl licenseUrl, QDialog *parent) : QDialog (parent)
{
    uiA.setupUi(this);
    //connect okay pushButton SLOTs ----------------
    connect ( uiA.pushButton_ok, SIGNAL( clicked() ), this, SLOT( okay() ) );

    setTop();
    setAbout();
    setAuthor();
    setThanks();
    setLicense(licenseUrl);
    setSupport();
}
// SLOTS-------------------------------------------------------------------------------------
// --------------------------------okay pressed------------------------------------------------
void aboutDialog::okay()
{
    close();
}

// FUNCTIONS-------------------------------------------------------------------------------------
void aboutDialog::setTop()
{
    Text = appName+" "+ appVersionString;
    uiA.label_Top -> setText(Text);
}
void aboutDialog::setAbout()
{
    uiA.textBrowser_About -> setOpenLinks(true);
    uiA.textBrowser_About -> setOpenExternalLinks(true);

    Text = 	"<p align=\"center\"><b>"+appName + " " + appVersionString +"</b> ("+
        tr("Backup & Sync Application")+"<br>version 0.5.0-3~ski<br>(customized to suppress TrayMessage notification balloons)<br>"

        "(C) 2008-2018,	"+
        tr("Loukas Avgeriou") +"<br><br>"

        "project homepage:<br>"
        "http://luckybackup.sourceforge.net<br>"+

        tr("luckyBackup is distributed under the terms of the GNU General Public License (GPL v3)","") +"<br><br>" +

        tr("It is <b>free software</b>: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3 of the License.","") +"<br>" +
        tr("It is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.")+ "<br>";

    uiA.textBrowser_About -> setText(Text);
}
void aboutDialog::setAuthor()
{
    uiA.textBrowser_Author -> setOpenLinks(true);
    uiA.textBrowser_Author -> setOpenExternalLinks(true);

    Text =	"<p align=\"center\"><br><img name=\"luckyb\" src=\":/luckyPrefix/luckyb.png\" width=\"80\" height=\"80\" border=\"0\"><b><br><br>"+
        tr("Loukas Avgeriou") +"</b> (luckyb)<br>"+
        tr("Athens, Greece") +
        "<br><br><a href=\"mailto:luckyb69@users.sourceforge.net\">luckyb69@users.sourceforge.net</a></p>";
    uiA.textBrowser_Author -> setText(Text);
}
void aboutDialog::setThanks()
{
    uiA.textBrowser_Thanks -> setOpenLinks(false);
    uiA.textBrowser_Thanks -> setOpenExternalLinks(false);
    Text =	"<p align=\"center\">" + tr("") + "";
    uiA.textBrowser_Thanks-> setText(Text);
}
void aboutDialog::setLicense(QUrl licenseUrl)
{
    uiA.textBrowser_License -> setOpenLinks(false);
    uiA.textBrowser_License -> setOpenExternalLinks(false);
    licenseUrl.setScheme("file");
    uiA.textBrowser_License -> setText(tr("") + "");
}

void aboutDialog::setSupport()
{
    uiA.textBrowser_Support -> setOpenLinks(false);
    uiA.textBrowser_Support -> setOpenExternalLinks(false);
    Text = 	"" + tr("") + "";
    uiA.textBrowser_Support -> setText(Text);
}
// end of about.cpp ---------------------------------------------------------------------------

