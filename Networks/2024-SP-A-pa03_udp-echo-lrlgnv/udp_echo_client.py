#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
UDP_echo program
Solution using python sockets
Student template
"""
import socket
import time
import sys
import statistics


def parse_args() -> tuple[str, int, int, int]:
    """
    parses the 4 args:
    server_hostname, server_port, num_pings, timeout
    """
    server_hostname = str(sys.argv[1])
    server_port = int(sys.argv[2])
    num_pings = int(sys.argv[3])
    timeout = int(sys.argv[4])
    return server_hostname, server_port, num_pings, timeout


def create_socket(timeout: int) -> socket.socket:
    """Create IPv4 UDP client socket"""
    client_socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    # Set socket timeout here.
    client_socket.settimeout(timeout)
    return client_socket


def net_stats(
    num_pings: int, rtt_hist: list[float]
) -> tuple[float, float, float, float, float]:
    """
    Computes statistics for loss and timing.
    Mimicks the real ping's statistics.
    Check them out: `ping 127.0.0.1`
    See `man ping` for definitions.
    This is just a math function.
    Don't do any networking here.
    loss, rtt_min, rtt_avg, rtt_max, rtt_mdev
    """
    if len(rtt_hist) == 0:
        loss = 100.0
        rtt_min = 0.0
        rtt_avg = 0.0
        rtt_max = 0.0
        rtt_mdev = 0.0
        return loss, rtt_min, rtt_avg, rtt_max, rtt_mdev
    else:
        loss = float(((num_pings - len(rtt_hist)) / num_pings) * 100)
        rtt_avg = statistics.mean(rtt_hist)
        rtt_max = max(rtt_hist)
        rtt_min = min(rtt_hist)
        rtt_mdev = statistics.stdev(rtt_hist)
    return loss, rtt_min, rtt_avg, rtt_max, rtt_mdev


def main() -> None:
    SERVER_HOSTNAME, SERVER_PORT, NUM_PINGS, TIMEOUT = parse_args()
    # Get IP from hostname
    SERVER_IP = socket.gethostbyname(SERVER_HOSTNAME)
    # Create the socket
    client_socket = create_socket(timeout=TIMEOUT)
    total = 0.0
    rtt_hist = []
    i = 0
    message = f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {i+1} {time.asctime()}"
    print(f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {len(message)} bytes of data.")
    for i in range(NUM_PINGS):
        try:
            message = f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {i+1} {time.asctime()}"
            start = time.time()
            client_socket.sendto(message.encode(), (SERVER_IP, SERVER_PORT))
            received_message, address = client_socket.recvfrom(1024)
            rtt = float(round((time.time() - start), 2) * 1000)

            decoded_message = received_message.decode()
            rtt_hist.append(rtt)
            total += rtt
            if decoded_message[:4] == "oops":
                print("Damaged packet")
            else:
                rtt = round(rtt)
                print(
                    f"{len(message)} bytes from {SERVER_HOSTNAME} ({SERVER_IP}): ping_seq={i+1} time={rtt} ms"
                )
        except (TimeoutError):
            print("timed out")

    # Note: you will want exception handling for lost packets (think timeout).
    # round RTT the nearest 10ms before adding it to rtt_hist and displaying it

    # ping stats
    loss, rtt_min, rtt_avg, rtt_max, rtt_mdev = net_stats(
        num_pings=NUM_PINGS, rtt_hist=rtt_hist
    )
    loss = round(loss)
    rtt_min = round(rtt_min)
    rtt_avg = round(rtt_avg)
    rtt_max = round(rtt_max)
    rtt_mdev = round(rtt_mdev)
    total = round(total)
    print()
    print("--- localhost ping statistics ---")
    print(
        f"{NUM_PINGS} packets transmitted, {len(rtt_hist)} received, {loss}% packet loss, time {total}ms"
    )
    print(f"rtt min/avg/max/mdev = {rtt_min}/{rtt_avg}/{rtt_max}/{rtt_mdev} ms")
    return


if __name__ == "__main__":
    main()
