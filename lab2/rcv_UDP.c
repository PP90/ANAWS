//Ipv6 node receiver. The node is "hearing" for incoming message.

#include "contiki.h"
#include <stdio.h>//for printf function

//Libraries for IpV6 functions
#include "ipv6_addr_lib.c"
#include "project_conf.h"

static struct simple_udp_connection connection;
PROCESS(rcv_process, "rcv_process");
AUTOSTART_PROCESSES(&rcv_process);

PROCESS_THREAD(rcv_process, ev, data){
PROCESS_BEGIN();
	set_address();
	simple_udp_register(&connection, UDP_PORT, NULL, UDP_PORT, callback_function);
	//print_address();
while(1){
	PROCESS_WAIT_EVENT();
}
PROCESS_END();
}
