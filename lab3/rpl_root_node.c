//A mote sends periodically a unicast UDP message at specific manually IPv6 address. 
#include "contiki.h"
#include <stdio.h>//for printf function
#include "project_conf.h"
#include "rpl_lib.c"
#include "../lab2/ipv6_addr_lib.c"//The library is taken from other lab stuff directory. //Actually

PROCESS(rpl_root_node, "rpl_root_nodes");
AUTOSTART_PROCESSES(&rpl_root_node);

PROCESS_THREAD(rpl_root_node, ev, data){
	
	static uip_ipaddr_t rpl_root_ip;
PROCESS_BEGIN();
	
	rpl_dag_t *get_root_node(rpl_root_ip);

PROCESS_END();
}
