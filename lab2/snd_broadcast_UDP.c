//A mote sends periodically a broadcast UDP message in the link local scope. 
#include "contiki.h"
#include <stdio.h>//for printf function
#include "ipv6_addr_lib.c"//Libraries for IpV6 functions

#undef RF_CHANNEL
#define RF_CHANNEL 26//Set the radio frequency channel
#define HOW_MUCH_TIME 2
PROCESS(snd_process, "snd_process");
AUTOSTART_PROCESSES(&snd_process);
//print_address();

PROCESS_THREAD(snd_process, ev, data){
	static struct etimer et;
	static struct simple_udp_connection broadcast_connection;
	static uip_ipaddr_t mcast_allnodes_address;

PROCESS_BEGIN();
	etimer_set(&et, CLOCK_SECOND*HOW_MUCH_TIME);
	set_address();
	simple_udp_register(&broadcast_connection, UDP_PORT, NULL,UDP_PORT, 		callback_function);
	mcast_allnodes_address=get_multicast_all_nodes_addr();

	while(1){//A broadcast message is sent periodically
		PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
		simple_udp_sendto(&broadcast_connection, "Hello", 5, (const 		uip_ipaddr_t*)&mcast_allnodes_address);
		etimer_reset(&et);
		}
	
PROCESS_END();
}
