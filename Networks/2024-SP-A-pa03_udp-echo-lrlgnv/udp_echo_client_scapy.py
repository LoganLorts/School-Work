#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
UDP_echo program
Solution using scapy
Solution
"""
import time
import sys
import statistics
from scapy.all import *  # type: ignore

# https://scapy.readthedocs.io/en/latest/troubleshooting.html
conf.L3socket = L3RawSocket  # type: ignore
# sometimes needed for default gateway, and
# always for localhost, and
# sometimes not for remote.


def parse_args() -> tuple[str, int, int, int]:
    """
    parses the 4 args:
    server_hostname, server_port, num_pings, timeout
    """
    server_hostname = sys.argv[1]
    server_port = int(sys.argv[2])
    num_pings = int(sys.argv[3])
    timeout = int(sys.argv[4])
    return server_hostname, server_port, num_pings, timeout


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
    """
    if len(rtt_hist) == 0:
        loss = 100.0
        rtt_min = 0.0
        rtt_avg = 0.0
        rtt_max = 0.0
        rtt_mdev = 0.0
        return loss, rtt_min, rtt_avg, rtt_max, rtt_mdev
    else:
        loss = ((num_pings - len(rtt_hist)) / num_pings) * 100
        rtt_avg = statistics.mean(rtt_hist)
        rtt_max = max(rtt_hist)
        rtt_min = min(rtt_hist)
        rtt_mdev = statistics.stdev(rtt_hist)
        loss = loss
        rtt_avg = rtt_avg
        rtt_max = rtt_max
        rtt_min = rtt_min
        rtt_mdev = rtt_mdev
        float(loss)
        float(rtt_avg)
        float(rtt_max)
        float(rtt_min)
        float(rtt_mdev)
    return loss, rtt_min, rtt_avg, rtt_max, rtt_mdev


def main() -> None:
    SERVER_HOSTNAME, SERVER_PORT, NUM_PINGS, TIMEOUT = parse_args()
    # Get IP from hostname
    total = 0.0
    rtt_hist = []
    i = 0
    message = f"PING {SERVER_HOSTNAME} ('127.0.0.1') {i+1} {time.asctime()}"

    print(f'PING {SERVER_HOSTNAME} ("127.0.0.1") {len(message)} bytes of data.')
    for i in range(NUM_PINGS):
        try:
            message = f"PING {SERVER_HOSTNAME} ('127.0.0.1') {i+1} {time.asctime()}"
            start = time.time()
            package = sr1(IP(dst=SERVER_HOSTNAME) / UDP(sport=12001) / message, verbose=0)  # type: ignore
            rtt = float(round((time.time() - start), 2) * 1000)
            rtt_hist.append(rtt)
            total += rtt
            if package[:4] == "oops":
                print("Damaged packet")
            else:
                print(
                    f"{len(message)} bytes from {SERVER_HOSTNAME} ({'127.0.0.1'}): ping_seq={i+1} time={rtt} ms"
                )
        except (TimeoutError):
            print("timed out")

    # Note: you will want exception handling for lost packets (think timeout).
    # round RTT the nearest 10ms before adding it to rtt_hist and displaying it

    # ping stats
    loss, rtt_min, rtt_avg, rtt_max, rtt_mdev = net_stats(
        num_pings=int(NUM_PINGS), rtt_hist=rtt_hist
    )
    round(loss)
    round(rtt_min)
    round(rtt_avg)
    round(rtt_max)
    round(rtt_mdev)
    print()
    print("--- localhost ping statistics ---")
    print(
        f"{NUM_PINGS} packets transmitted, {len(rtt_hist)} received, {loss}% packet loss, time {total}ms"
    )
    print(f"rtt min/avg/max/mdev = {rtt_min}/{rtt_avg}/{rtt_max}/{rtt_mdev} ms")
    return


if __name__ == "__main__":
    main()
