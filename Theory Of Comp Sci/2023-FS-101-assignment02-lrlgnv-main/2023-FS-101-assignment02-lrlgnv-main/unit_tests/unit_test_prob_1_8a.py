#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

### Open files and populate lists ###
accept_file = open("unit_tests/inputs/1_8a_accepts.txt", "r")
reject_file = open("unit_tests/inputs/1_8a_rejects.txt", "r")
accept_list = accept_file.readlines()
reject_list = reject_file.readlines()

### Remove newlines ###
for i in range(len(accept_list)):
    accept_list[i] = accept_list[i][:-1]
for i in range(len(reject_list)):
    reject_list[i] = reject_list[i][:-1]

### Test Inputs ###
from assignment02_main import prob_1_8a

for w in accept_list:
    if (w not in prob_1_8a):
        print(f'FAILED ON INPUT: \'{w}\'')
    assert w in prob_1_8a

for w in reject_list:
    if (w in prob_1_8a):
        print(f'FAILED ON INPUT: \'{w}\'')
    assert w not in prob_1_8a

### Clean up ###
accept_file.close()
reject_file.close()
