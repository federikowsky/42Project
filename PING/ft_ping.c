#include "ft_ping.h"

t_ping g_ping;

void print_usage(void) {
    printf("Usage: ft_ping [OPTION...] HOST ...\n");
    printf("Send ICMP ECHO_REQUEST packets to network hosts.\n\n");
    printf(" Options:\n");
    printf("  -v              verbose output\n");
    printf("  -?              give this help list\n");
    printf("  -c COUNT        stop after sending COUNT packets\n");
    printf("  -f              flood ping\n");
    printf("  -l COUNT        send COUNT packets as fast as possible before normal mode\n");
    printf("  -n              no reverse DNS lookups\n");
    printf("  -p PATTERN      fill packet with PATTERN (hex)\n");
    printf("  -r              record route\n");
    printf("  -s SIZE         packet size\n");
    printf("  -t TTL          time to live\n");
    printf("  -w SECONDS      wait SECONDS for response\n");
    printf("  -W SECONDS      linger SECONDS for late packets\n");
    printf("  -T TYPE         timestamp type (tsonly|tsandaddr|tsprespec)\n");
    printf("      --ttl=N     same as -t\n");
    printf("      --ip-timestamp=TYPE  same as -T\n");
}

void init_ping(void) {
    g_ping.sockfd = -1;
    g_ping.packets_sent = 0;
    g_ping.packets_received = 0;
    g_ping.min_rtt = INFINITY;
    g_ping.max_rtt = 0;
    g_ping.sum_rtt = 0;
    g_ping.sum_rtt2 = 0;
    g_ping.ttl = 64;
    g_ping.verbose = false;
    g_ping.help = false;
    g_ping.flood = false;
    g_ping.numeric = false;
    g_ping.preload = 0;
    g_ping.pattern = 0;
    g_ping.packet_size = 56;
    g_ping.sndbuf = 0;
    g_ping.wait_time = 0;
    g_ping.linger_time = 0;
    g_ping.tos = 0;
    g_ping.quiet = false;
    g_ping.route = false;
    g_ping.timestamp = false;
    g_ping.ts_type = 0;
    g_ping.pid = getpid();
    g_ping.seq = 0;
    g_ping.msg_count = 0;
    g_ping.msg_received_count = 0;
    g_ping.count = 0;
}

void parse_args(int argc, char **argv) {
    int i = 1;
    
    while (i < argc) {
        if (argv[i][0] == '-') {
            if (!strcmp(argv[i], "-v"))
                g_ping.verbose = true;
            else if (!strcmp(argv[i], "-?") || !strcmp(argv[i], "--help")) {
                g_ping.help = true;
                return;
            }
            else if (!strcmp(argv[i], "-f"))
                g_ping.flood = true;
            else if (!strcmp(argv[i], "-n"))
                g_ping.numeric = true;
            else if (!strcmp(argv[i], "-r"))
                g_ping.route = true;
            else if (!strcmp(argv[i], "-q"))
                g_ping.quiet = true;
            else if (!strcmp(argv[i], "-c") && i + 1 < argc) {
                g_ping.count = atoi(argv[++i]);
                if (g_ping.count <= 0) {
                    fprintf(stderr, "ft_ping: invalid count of packets\n");
                    exit(1);
                }
            }
            else if (!strcmp(argv[i], "-l") && i + 1 < argc) {
                g_ping.preload = atoi(argv[++i]);
            }
            else if (!strcmp(argv[i], "-p") && i + 1 < argc) {
                g_ping.pattern = (int)strtol(argv[++i], NULL, 16);
            }
            else if (!strcmp(argv[i], "-s") && i + 1 < argc) {
                g_ping.packet_size = atoi(argv[++i]);
                if (g_ping.packet_size < 0 || g_ping.packet_size > 65507) {
                    fprintf(stderr, "ft_ping: invalid packet size\n");
                    exit(1);
                }
            }
            else if (!strcmp(argv[i], "-t") && i + 1 < argc) {
                g_ping.ttl = atoi(argv[++i]);
                if (g_ping.ttl < 1 || g_ping.ttl > 255) {
                    fprintf(stderr, "ft_ping: invalid TTL\n");
                    exit(1);
                }
            }
            else if (!strcmp(argv[i], "-w") && i + 1 < argc) {
                g_ping.wait_time = atoi(argv[++i]);
            }
            else if (!strcmp(argv[i], "-W") && i + 1 < argc) {
                g_ping.linger_time = atoi(argv[++i]);
            }
            else if (!strcmp(argv[i], "-T") && i + 1 < argc) {
                i++;
                if (!strcmp(argv[i], "tsonly"))
                    g_ping.ts_type = 1;
                else if (!strcmp(argv[i], "tsandaddr"))
                    g_ping.ts_type = 3;
                else if (!strcmp(argv[i], "tsprespec"))
                    g_ping.ts_type = 2;
                g_ping.timestamp = true;
            }
            else if (!strncmp(argv[i], "--ttl=", 6)) {
                g_ping.ttl = atoi(argv[i] + 6);
                if (g_ping.ttl < 1 || g_ping.ttl > 255) {
                    fprintf(stderr, "ft_ping: invalid TTL\n");
                    exit(1);
                }
            }
            else if (!strncmp(argv[i], "--ip-timestamp=", 15)) {
                if (!strcmp(argv[i] + 15, "tsonly"))
                    g_ping.ts_type = 1;
                else if (!strcmp(argv[i] + 15, "tsandaddr"))
                    g_ping.ts_type = 3;
                else if (!strcmp(argv[i] + 15, "tsprespec"))
                    g_ping.ts_type = 2;
                g_ping.timestamp = true;
            }
            else {
                fprintf(stderr, "ft_ping: invalid option -- '%s'\n", argv[i]);
                fprintf(stderr, "Try 'ft_ping -?' for more information.\n");
                exit(1);
            }
        } else {
            g_ping.target_host = argv[i];
        }
        i++;
    }
    
    if (!g_ping.target_host && !g_ping.help) {
        fprintf(stderr, "ft_ping: missing host operand\n");
        fprintf(stderr, "Try 'ft_ping -?' for more information.\n");
        exit(1);
    }
}

void resolve_hostname(void) {
    struct hostent *host;
    struct in_addr addr;
    
    if (inet_aton(g_ping.target_host, &addr)) {
        g_ping.target_ip = strdup(g_ping.target_host);
        g_ping.dest_addr.sin_addr = addr;
    } else {
        host = gethostbyname(g_ping.target_host);
        if (!host) {
            fprintf(stderr, "ft_ping: cannot resolve %s: Unknown host\n", g_ping.target_host);
            exit(2);
        }
        g_ping.dest_addr.sin_addr = *((struct in_addr *)host->h_addr);
        g_ping.target_ip = strdup(inet_ntoa(g_ping.dest_addr.sin_addr));
    }
    
    g_ping.dest_addr.sin_family = AF_INET;
    g_ping.dest_addr.sin_port = 0;
    
    if (!g_ping.numeric && strcmp(g_ping.target_host, g_ping.target_ip) == 0) {
        struct hostent *reverse = gethostbyaddr(&g_ping.dest_addr.sin_addr, 
                                                sizeof(g_ping.dest_addr.sin_addr), AF_INET);
        if (reverse && reverse->h_name)
            g_ping.reverse_hostname = strdup(reverse->h_name);
    }
}

void create_socket(void) {
    g_ping.sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (g_ping.sockfd < 0) {
        if (errno == EPERM) {
            fprintf(stderr, "ft_ping: socket: Operation not permitted\n");
            fprintf(stderr, "ft_ping: Lacking privilege for raw socket.\n");
        } else {
            perror("ft_ping: socket");
        }
        exit(2);
    }
    
    if (setsockopt(g_ping.sockfd, IPPROTO_IP, IP_TTL, &g_ping.ttl, sizeof(g_ping.ttl)) < 0) {
        perror("ft_ping: setsockopt");
        exit(2);
    }
    
    if (g_ping.tos && setsockopt(g_ping.sockfd, IPPROTO_IP, IP_TOS, &g_ping.tos, sizeof(g_ping.tos)) < 0) {
        perror("ft_ping: setsockopt");
        exit(2);
    }
    
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(g_ping.sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("ft_ping: setsockopt");
        exit(2);
    }
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    
    while (len > 1) {
        sum += *buf++;
        len -= 2;
    }
    
    if (len)
        sum += *(unsigned char *)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return ~sum;
}

double get_time_diff(struct timeval *start, struct timeval *end) {
    return ((double)(end->tv_sec - start->tv_sec) * 1000.0) +
           ((double)(end->tv_usec - start->tv_usec) / 1000.0);
}

void send_ping(void) {
    t_ping_pkt packet;
    struct timeval send_time;
    
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.code = 0;
    packet.hdr.un.echo.id = g_ping.pid;
    packet.hdr.un.echo.sequence = g_ping.seq++;
    
    for (int i = 0; i < sizeof(packet.msg) - 1; i++) {
        if (g_ping.pattern)
            packet.msg[i] = g_ping.pattern;
        else
            packet.msg[i] = i + '0';
    }
    packet.msg[sizeof(packet.msg) - 1] = 0;
    
    gettimeofday(&send_time, NULL);
    memcpy(packet.msg, &send_time, sizeof(send_time));
    
    packet.hdr.checksum = 0;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));
    
    if (sendto(g_ping.sockfd, &packet, sizeof(packet), 0,
               (struct sockaddr *)&g_ping.dest_addr, sizeof(g_ping.dest_addr)) <= 0) {
        if (g_ping.verbose)
            perror("ft_ping: sendto");
    } else {
        g_ping.packets_sent++;
    }
}

void receive_ping(void) {
    char buf[1024];
    socklen_t addr_len = sizeof(g_ping.from_addr);
    struct timeval recv_time;
    ssize_t bytes;
    
    bytes = recvfrom(g_ping.sockfd, buf, sizeof(buf), 0,
                     (struct sockaddr *)&g_ping.from_addr, &addr_len);
    
    if (bytes > 0) {
        gettimeofday(&recv_time, NULL);
        
        struct iphdr *ip_hdr = (struct iphdr *)buf;
        struct icmphdr *icmp = (struct icmphdr *)(buf + (ip_hdr->ihl * 4));
        
        if (icmp->type == ICMP_ECHOREPLY && icmp->un.echo.id == g_ping.pid) {
            struct timeval *send_time = (struct timeval *)(buf + (ip_hdr->ihl * 4) + sizeof(struct icmphdr));
            double rtt = get_time_diff(send_time, &recv_time);
            
            g_ping.packets_received++;
            g_ping.sum_rtt += rtt;
            g_ping.sum_rtt2 += rtt * rtt;
            
            if (rtt < g_ping.min_rtt) g_ping.min_rtt = rtt;
            if (rtt > g_ping.max_rtt) g_ping.max_rtt = rtt;
            
            int data_size = bytes - (ip_hdr->ihl * 4) - sizeof(struct icmphdr);
            
            if (!g_ping.quiet && !g_ping.flood) {
                printf("%d bytes from %s", (int)bytes - (ip_hdr->ihl * 4),
                       inet_ntoa(g_ping.from_addr.sin_addr));
                if (g_ping.reverse_hostname)
                    printf(" (%s)", g_ping.reverse_hostname);
                else if (!g_ping.numeric && strcmp(g_ping.target_host, g_ping.target_ip) != 0)
                    printf(" (%s)", g_ping.target_host);
                printf(": icmp_seq=%d ttl=%d time=%.1f ms\n",
                       icmp->un.echo.sequence, ip_hdr->ttl, rtt);
            } else if (g_ping.flood) {
                printf("\b \b");
                fflush(stdout);
            }
        } else if (icmp->type != ICMP_ECHOREPLY && g_ping.verbose) {
            fprintf(stderr, "From %s: icmp_type=%d icmp_code=%d\n",
                    inet_ntoa(g_ping.from_addr.sin_addr), icmp->type, icmp->code);
        }
    }
}

void print_stats(int sig) {
    (void)sig;
    
    if (g_ping.packets_sent > 0) {
        printf("\n--- %s ping statistics ---\n", g_ping.target_host);
        
        int packet_loss = ((g_ping.packets_sent - g_ping.packets_received) * 100) / g_ping.packets_sent;
        
        printf("%d packets transmitted, %d packets received, %d%% packet loss\n",
               g_ping.packets_sent, g_ping.packets_received, packet_loss);
        
        if (g_ping.packets_received > 0) {
            double avg = g_ping.sum_rtt / g_ping.packets_received;
            double mdev = sqrt((g_ping.sum_rtt2 / g_ping.packets_received) - (avg * avg));
            
            printf("round-trip min/avg/max/stddev = %.3f/%.3f/%.3f/%.3f ms\n",
                   g_ping.min_rtt, avg, g_ping.max_rtt, mdev);
        }
    }
    
    cleanup();
    exit(g_ping.packets_received == 0 ? 1 : 0);
}

void cleanup(void) {
    if (g_ping.sockfd >= 0)
        close(g_ping.sockfd);
    if (g_ping.target_ip)
        free(g_ping.target_ip);
    if (g_ping.reverse_hostname)
        free(g_ping.reverse_hostname);
}

int main(int argc, char **argv) {
    init_ping();
    parse_args(argc, argv);
    
    if (g_ping.help) {
        print_usage();
        return 0;
    }
    
    resolve_hostname();
    create_socket();
    
    signal(SIGINT, print_stats);
    signal(SIGALRM, print_stats);
    
    gettimeofday(&g_ping.start_time, NULL);
    
    if (!g_ping.quiet)
        printf("PING %s (%s): %d data bytes\n", g_ping.target_host, g_ping.target_ip, g_ping.packet_size);
    
    if (g_ping.preload > 0) {
        for (int i = 0; i < g_ping.preload; i++) {
            send_ping();
            usleep(10000);
        }
    }
    
    if (g_ping.wait_time > 0)
        alarm(g_ping.wait_time);
    
    while (1) {
        send_ping();
        if (g_ping.flood) {
            printf(".");
            fflush(stdout);
        }
        
        receive_ping();
        
        if (g_ping.count > 0 && g_ping.packets_sent >= g_ping.count) {
            print_stats(0);
            break;
        }
        
        if (!g_ping.flood)
            usleep(PING_SLEEP_RATE);
        else
            usleep(10000);
    }
    
    return 0;
}