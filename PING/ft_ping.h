#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <sys/time.h>
# include <signal.h>
# include <errno.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>

# define PING_PKT_S 64
# define RECV_TIMEOUT 1
# define PING_SLEEP_RATE 1000000

typedef struct s_ping_pkt {
    struct icmphdr hdr;
    char msg[PING_PKT_S - sizeof(struct icmphdr)];
} t_ping_pkt;

typedef struct s_ping {
    int sockfd;
    char *target_host;
    char *target_ip;
    char *reverse_hostname;
    struct sockaddr_in dest_addr;
    struct sockaddr_in from_addr;
    int packets_sent;
    int packets_received;
    double min_rtt;
    double max_rtt;
    double sum_rtt;
    double sum_rtt2;
    struct timeval start_time;
    int ttl;
    int msg_count;
    int msg_received_count;
    bool verbose;
    bool help;
    bool flood;
    bool numeric;
    int preload;
    int pattern;
    int packet_size;
    int sndbuf;
    int wait_time;
    int linger_time;
    int tos;
    bool quiet;
    bool route;
    bool timestamp;
    int ts_type;
    pid_t pid;
    int seq;
    int count;
} t_ping;

extern t_ping g_ping;

/* Core functions */
void init_ping(void);
void parse_args(int argc, char **argv);
void resolve_hostname(void);
void create_socket(void);
void send_ping(void);
void receive_ping(void);
void print_stats(int sig);
unsigned short checksum(void *b, int len);
double get_time_diff(struct timeval *start, struct timeval *end);
void print_usage(void);
void cleanup(void);

#endif