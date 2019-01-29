# APSI Proxy Test-Suite

APSI Proxy Test-Suite are set of bash scripts used in testing the functionality of APSI Proxy

## Prerequisites
+ Environment that run bash file
+ Apache HTTP Server
+ Byobu
+ OpenSSH

## Test Scripts
### configFile
This is a user custom file. User need to set his own parameter based on the setting of his local computer.
User needs to set the following variables:
```bash
SERVER 
(e.g. SERVER = ("192.168.254.139" "192.168.254.140") )
```
- It is an array type variable. 
User can list the host names or ip addresses of the server machine where the APSI Proxy server runs.
```bash
TARGET
(e.g. TARGET = ("192.168.254.139" localhost)
```
+ Target can be either Server or Client machine. It is an array type variable so user can list the host names or IP addresses of the machine.
```bash
CLIENT
(e.g. CLIENT = (localhost) )
```
+ It is an array type variable. User can list the host name or IP Address of the machine where the APSI Proxy Client runs.
```bash
SOURCE
(e.g. SOURCE = (localhost) )
```
+ It is an array type variable. User can list the host name or IP Address of the machine where the source of APSI Proxy could find.
```bash
USER
(e.g. USER = "alex@")
```
+ User holds the username of the machine that script want to access.
```bash
PLATFORM
(e.g. PLATFORM = amd64-linux-sysv-dbg)
```
+ It holds the location where the apsiproxy executable file can be found. It is usually found under the build folder of apsiproxy source code.
```bash
MD5SUM
(e.g. MD5SUM="targetMD5Sum")
```
+ It holds the filename of the script where going to process the computation of MD5 Sum.
```bash
WEBSERVER
(e.g. WEBSERVER = ${SERVER[0]} or WEBSERVER = "192.168.254.139")
```
+ It holds the address of the webserver where the script are going to access or download the files for transfer testing.
```bash
LOCATION
(e.g. LOCATION = "file/testfiles")
```
+ It holds the specific folder location in the webserver that the script are going to access or download the files.
```bash
FILENAME
(e.g. FILENAME = "random1GB")
```
+ This is the specific file that is going to access or download in the webserver.
```bash
FILENAMEDEST
(e.g. FILENAMEDEST = "random1GB")
```
+ This is the name of the file after fully received the downloaded file.
```bash
APSI_DIR
(e.g. APSI_DIR = "$HOME/APSI/"
```
+ The directory or location of the APSI Proxy source codes.
```bash
APSI_TESTDIR
(e.g. APSI_TESTDIR = "$HOME/apsiTests/")
```
+ The location of the test scripts of the APSI Proxy.
```bash
BIN_DIR
(e.g. BIN_DIR = "$HOME/bin")
```
+ It is the location of the bin files.
```bash
SERVER_CONFIG
(e.g. SERVER_CONFIG = $APSI_TESDIR/server.cfg)
```
+ It holds the location of the server configuration file of the APSI Proxy server.
```bash
CLIENT_CONFIG
(e.g. CLIENT_CONFIG= $APSI_TESDIR/client.cfg)
```
+ It holds the location of the client configuration file of the APSI Proxy client.
