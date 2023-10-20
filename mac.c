#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
	struct ifreq ifr;
	int s;

	s = socket(AF_INET, SOCK_DGRAM, 0);
	assert(s != -1);

	strcpy(ifr.ifr_name, "eth0");
	ifr.ifr_hwaddr.sa_data[0] = 0xDE;
	ifr.ifr_hwaddr.sa_data[1] = 0xAD;
	ifr.ifr_hwaddr.sa_data[2] = 0xBE;
	ifr.ifr_hwaddr.sa_data[3] = 0xEF;
	ifr.ifr_hwaddr.sa_data[4] = 0xCA;
	ifr.ifr_hwaddr.sa_data[5] = 0xFE;
	ifr.ifr_hwaddr.sa_family = ARPHRD_ETHER;
	assert(ioctl(s, SIOCSIFHWADDR, &ifr) != -1);

	return EXIT_SUCCESS;
}