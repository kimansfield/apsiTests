#include <stdio.h>
#include <errno.h>

int main() {
	
	fprintf("Something here", strerror(errno));
}
