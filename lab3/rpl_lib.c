//Library that contains a lot of useful function. 
//Functions list:
//

#include "simple-udp.h"
#include "net/rpl/rpl.h"
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/ip/uip-debug.h"
#include "simple-udp.h"
#include <stdio.h>
#include "project_conf.h"
#define UDP_PORT 1234

//Initialize a node as RPL root node
rpl_dag_t *get_root_node(uip_ipaddr_t *ip_addr){
rpl_dag_t *dag;
dag=rpl_set_root(RPL_DEFAULT_INSTANCE, (uip_ip6addr_t *)&ip_addr);
rpl_set_prefix(dag, ip_addr,64);
return dag;
}

//An address is assigned and returned
uip_ipaddr_t get_address(){
uip_ipaddr_t ip_addr;
//First field is the prefix of my link local(?).The last field is what IPv6 adrress it is assigned to my device
uip_ip6addr(&ip_addr,0xaaaa, 0,0,0,0,0,0,0);
uip_ds6_set_addr_iid(&ip_addr, &uip_lladdr);//The IPv6 address is get from MAC address.
uip_ds6_addr_add(&ip_addr, 0, ADDR_AUTOCONF);
return ip_addr;
}
