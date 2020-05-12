#########################################################################################
#!/bin/bash
# A script to expose three custom Object Identifiers (OIDs) for an organization's network
# Uses SNMPD (Simple Network Management Protocol Daemon) as the server
# Uses SNMP (Simple Network Management Protocol) to expose server commands/APIs
#########################################################################################

# Dependencies
echo "[~] Updating packages..."
sudo apt update
echo "[+] Successfully updated packages"

echo

echo "Installing dependencies..."

echo "Installing [1 of 7] - snmpd"
sudo apt install snmpd

echo "Installing [2 of 7] - snmp"
sudo apt install snmp 

echo "Installing [3 of 7] - libsnmp-dev"
sudo apt install libsnmp-dev

echo "Installing [4 of 7] - snmp-mibs-downloader"
sudo apt install snmp-mibs-downloader

echo "Installing [5 of 7] - libboost-all-dev"
sudo apt-get install libboost-all-dev

echo "Installing [6 of 7] - libpq-dev"
sudo apt-get install libpq-dev

echo "Installing [7 of 7] - libpqxx"
git clone https://github.com/jtv/libpqxx
cd ./libpqxx
./configure --disable-documentation
sudo make
sudo make install

echo "[+] Successfully installed dependencies"
echo

# snmpd.conf
echo "[~] Updating snmpd.conf..."
sudo cp ./snmpd.conf /etc/snmp
echo

# PostgreSQL
echo "[~] Restarting PostgreSQL..."
sudo service postgresql restart
echo

# Simple Network Management Protocol (SNMP) service start
echo "[~] Starting snmpd service..."
sudo service snmpd stop
sudo service snmpd start
echo "[+] Service (snmpd) started"

echo

#Object Idenifiers (OIDs)
echo "[~] Fetching info from the agent..."
echo 

echo "##############"
echo "Version Number"
echo "##############"

snmpwalk -v2c -c communitystring localhost .1.3.6.1.4.1.53864.51

echo

echo "###################"
echo "Latest Signal Value"
echo "###################"

snmpwalk -v2c -c communitystring localhost .1.3.6.1.4.1.53864.52

echo

echo "################"
echo "Total Disk Space"
echo "################"

snmpwalk -v2c -c communitystring localhost .1.3.6.1.4.1.53864.53

echo


