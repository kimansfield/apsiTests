#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int resolveIt(const char *h);
void checkResolveIt(const int a, int b);

int testDone = 0;
int testPassed = 0;

int main(void) {
 	checkResolveIt(0,resolveIt("localhost"));
	checkResolveIt(0,resolveIt("mail.xmission.com"));
	checkResolveIt(0,resolveIt("google.com"));
	checkResolveIt(0,resolveIt("4.2.2.1"));
	checkResolveIt(0,resolveIt("127.0.0.1"));
	checkResolveIt(0,resolveIt("2607:f8b0:4005:801::200e"));
	checkResolveIt(0,resolveIt("::1"));
	checkResolveIt(0,resolveIt("baluchitherium.apsiwifi.com"));
	checkResolveIt(0,resolveIt("96.92.83.209"));
	checkResolveIt(0,resolveIt("10.1.1.66"));
	//	address from hosts file resolves
	checkResolveIt(0,resolveIt("baluchitherium"));
	checkResolveIt(0,resolveIt("dog.doghouse.com"));
	checkResolveIt(0,resolveIt("192.168.0.1"));
	/* //resolveIt(""); */


	//TESTS that should NOT resolve.
	checkResolveIt(EAI_NONAME,resolveIt("fe80::1e1b:dff:fe64:97d2/64"));
	checkResolveIt(EAI_NONAME,resolveIt("apple.asdf.com"));
	checkResolveIt(EAI_NONAME,resolveIt("::1/128"));
		
	printf("%d of %d TESTS PASSED\n", testPassed, testDone);

	return 0;
}

// I need to return rv and then check rv depending on which string I gave it..
int resolveIt(const char *host) {
	struct addrinfo hints = {0};
	struct addrinfo *addrs, *a;
	int rv, retVal;
	
	//printf("Resolving %s:\n", host);
	if (rv = getaddrinfo(host, NULL, NULL, &addrs)) {
		//retVal = gai_strerror(rv);
		//exit(1);
		// if (gai_strerror(rv) != 0) { 
		//printf("ERROR RESOLVING: %s\n", host);
		//} 
		//print error message
	}
	//printf("retval is :%d\n", rv);
	return rv;
	
	int i;

	char addrstr[NI_MAXHOST];
	for (a = addrs, i = 0; a != NULL; a = a->ai_next, i++) {
		getnameinfo(a->ai_addr, a->ai_addrlen, addrstr, sizeof(addrstr), NULL, 0,
								NI_NUMERICHOST);
		printf("\t%d:\t%s\n", i, addrstr);
	}

	if (rv == 0) {
	freeaddrinfo(addrs);
	}
	//return rv;
}

void checkResolveIt(int checkVal, int retVal) {
	if (checkVal == retVal) {
		testPassed++;
	}
	testDone++;
}
