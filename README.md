# APSI Proxy Test-Suite

APSI Proxy Test-Suite are set of bash scripts used in testing the functionality of APSI Proxy

## Prerequisites
+ Environment that run bash file or shell script
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
### createFile
#### Description
It will create a random 1GB file in the $BIN_DIR. It will first check if the $FILENAME exist in the $BIN_DIR. If it is not exist it will access the $TARGET machine through ssh and run the ddFile and getMD5Sum script.If the the $FILENAME exist it will check if the $MD5SUM is exist in the $BIN_DIR.If $MD5SUM does not exist it will access again the $TARGET machine through ssh and run the getMD5Sum script.
#### Usage
```bash
./createFile
````
### runApache
#### Description
It will run apache2ctl with apache2.conf as configuration file that is located at the $APSITEST_DIR. It will first test if apache2 is running or on the list of the processes. If it is actively run it will stop the process. Then it will check if the pid of /sbin/init is equal to 1. If it is true it will access directly the apache2ctl. If it is not true it will access to /usr/sbin/apache2ctl.
#### Usage
```bash
./runApache
```
### 
### runNetcat
#### Description
The first process it does is echo the following:
```bash
HTTP/1.0 200 OK
Content-Length: 3854
```
Where 3854 is the result of printing of number of bytes in ~/.bashrc content. This is the command it used:
```bash
$(wc -c < ~/.bashrc)
```
Then it will read the content of ~/.bashrc using cat command.
The last thing it does is run the netcat command and listen at port 8080
```bash
nc -v -l 8080
```
User can initially test this by going to web browser and access the localhost:8080.
#### Usage
```bash
./runNetcat
```
### runTest
#### Description
This script defines the needed function used by the subTest script.
It defines here the rExec, test_setup, cleanup and control_c functions.
Then it exports the rExec and cleanup function so that it can be see in subTest script. After defining and exporting function it will run the subTest script.
#### Usage
```bash
./runTest
```
