//Ipv6 node broadcast receiver

#include "contiki.h"
#include <stdio.h>//for printf function

//Libraries for IpV6 functions
#include "stuff.c"

#undef RF_CHANNEL
#define RF_CHANNEL //Set the radio frequency channel
PROCESS(rcv_process, "rcv_process");
AUTOSTART_PROCESSES(&rcv_process);

PROCESS_THREAD(rcv_process, ev, data){
PROCESS_BEGIN();
	set_address();
	receive_udp_broadcast();
	//print_address();
while(1){
PROCESS_WAIT_EVENT();
}
PROCESS_END();
}
