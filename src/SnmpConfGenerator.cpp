#include "../include/SnmpConfGenerator.h"

SnmpConfGenerator::SnmpConfGenerator()
{}

string SnmpConfGenerator::getTemplateString()
{
    string templateString = "";
    templateString += "view   systemonly  included   .1.3.6.1.2.1.1 \n";
    templateString += "view   systemonly  included   .1.3.6.1.2.1.25.1 \n";
    templateString += "rocommunity public  localhost \n";
    templateString += "rocommunity public  default    -V systemonly \n";
    templateString += "rocommunity6 public  default   -V systemonly \n";
    templateString += "rouser   authOnlyUser \n";
    templateString += "rocommunity communitystring localhost \n";
    templateString += "sysLocation    Sitting on the Dock of the Bay \n";
    templateString += "sysContact     Me <me@example.org> \n";
    templateString += "sysServices    72 \n";
    templateString += "proc  mountd \n";
    templateString += "proc  ntalkd    4 \n";
    templateString += "proc  sendmail 10 1 \n";
    templateString += "disk       /     10000 \n";
    templateString += "disk       /var  5% \n";
    templateString += "includeAllDisks  10% \n";
    templateString += "load   12 10 5 \n";
    templateString += "trapsink     localhost public \n";
    templateString += "iquerySecName   internalUser \n";
    templateString += "rouser          internalUser \n";
    templateString += "defaultMonitors          yes \n";
    templateString += "linkUpDownNotifications  yes \n";
    templateString += "master          agentx \n";

    return templateString;
}

void SnmpConfGenerator::resetConf()
{
    this->fullConfString = SnmpConfGenerator::getTemplateString();
}

void SnmpConfGenerator::addCommand(string cmd)
{
    this->fullConfString += cmd + "\n";
}

void SnmpConfGenerator::registerConf()
{
    ofstream confFile;
    // confFile.open("./docs/output.txt");
    confFile.open("./snmpd.conf");
    confFile << this->fullConfString << endl;
    confFile.close();
}