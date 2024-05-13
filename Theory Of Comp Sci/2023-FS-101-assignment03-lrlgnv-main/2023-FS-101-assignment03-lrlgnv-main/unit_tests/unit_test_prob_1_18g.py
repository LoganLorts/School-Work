#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import sys
from automata.fa.nfa import NFA

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

### Open files and populate lists ###
accept_file = open("unit_tests/inputs/1_18g_accepts.txt", "r")
reject_file = open("unit_tests/inputs/1_18g_rejects.txt", "r")
accept_list = accept_file.readlines()
reject_list = reject_file.readlines()

### Remove newlines ###
for i in range(len(accept_list)):
    accept_list[i] = accept_list[i][:-1]
for i in range(len(reject_list)):
    reject_list[i] = reject_list[i][:-1]

### Test Inputs ###
from assignment03_main import prob_1_18g
test_machine = NFA.from_regex(prob_1_18g, input_symbols={'0', '1'})

for w in accept_list:
    if (w not in test_machine):
        print(f'UNEXPECTED RESULT ON INPUT: \'{w}\'')
    assert w in test_machine

for w in reject_list:
    if (w in test_machine):
        print(f'UNEXPECTED RESULT ON INPUT: \'{w}\'')
    assert w not in test_machine

### Clean up ###
accept_file.close()
reject_file.close()
