//A mote sends periodically a unicast UDP message at specific manually IPv6 address. 
#include "contiki.h"
#include <stdio.h>//for printf function
#include "ipv6_addr_lib.c"//Libraries for IpV6 functions
#include "project_conf.h"

#define HOW_MUCH_TIME 5

PROCESS(unicast_snd_process, "unicast_snd_process");
AUTOSTART_PROCESSES(&unicast_snd_process);

PROCESS_THREAD(unicast_snd_process, ev, data){
	static struct etimer et;
	static struct simple_udp_connection uni_conn;
	static uip_ipaddr_t receiver_addr;
	static uip_ipaddr_t mcast_allnodes_address;

PROCESS_BEGIN();
	etimer_set(&et, CLOCK_SECOND*HOW_MUCH_TIME);
	set_address();
	uip_ip6addr(&receiver_addr,0xfe80, 0,0,0,0xc30c,0,0,2);//Set manually.
	simple_udp_register(&uni_conn, UDP_PORT, NULL,UDP_PORT, 		callback_function);
	mcast_allnodes_address=get_multicast_all_nodes_addr();

while(1){//An unicast message is sent periodically
	PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
	simple_udp_sendto(&uni_conn, "Uni_msg", 7, (const 		uip_ipaddr_t*)&receiver_addr);
	etimer_reset(&et);
}
PROCESS_END();
}
