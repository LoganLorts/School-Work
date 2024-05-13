from automata.fa.nfa import NFA

example_nfa = NFA(
    states={'q0', 'q1', 'q2'},
    input_symbols={'0', '1'},
    transitions={
        'q0': {'': {'q1', 'q2'}},
        'q1': {'0': {'q1'}, '1': {'q2'}},
        'q2': {'0': {'q1'}, '1': {'q2'}}
    },
    initial_state='q0',
    final_states={'q1'}
)

example_nfa_regex = "(1*0)?(11*0|0)*"



prob_1_21a = "a*b(a|ba*b)*"

prob_1_21b = "(((a|b)a*(bba*)*b)(a((a|b)a*(bba*)*b))*a?)?"



prob_1_28a = NFA(
    states = {'q0', 'q1', 'q2', 'q3','q4','q5','q6','q7','q8','q9','q10','q11'},
    input_symbols = {'a', 'b'},
    transitions = {
        'q0': {'': {'q1', 'q10'}},
        'q1': {'a': {'q2'}},
        'q2': {'': {'q3'}},
        'q3': {'': {'q4'}},
        'q4': {'a': {'q5'}},
        'q5': {'': {'q6'}},
        'q6': {'b': {'q7'}},
        'q7': {'': {'q8'}},
        'q8': {'b': {'q9'}},
        'q9': {'': {'q4'}},
        'q10': {'b': {'q11'}},
    },
    initial_state ='q0',
    final_states = {'q3', 'q9', 'q11'},
)

prob_1_28b = NFA(
    states = {'q0', 'q1', 'q2', 'q3','q4','q5','q6','q7','q8','q9','q10','q11','q12'},
    input_symbols = {'a', 'b'},
    transitions = {
        'q0': {'': {'q1', 'q4'}},
        'q1': {'a': {'q2'}},
        'q2': {'': {'q3'}},
        'q3': {'a': {'q3'}},
        'q4': {'a': {'q5'}},
        'q5': {'': {'q6'}},
        'q6': {'b': {'q7'}},
        'q7': {'': {'q8'}},
        'q8': {'': {'q9'}},
        'q9': {'a': {'q10'}},
        'q10': {'': {'q11'}},
        'q11': {'b': {'q12'}},
        'q12': {'': {'q9'}},
    },
    initial_state = 'q0',
    final_states = {'q3', 'q8', 'q12'},
)

prob_1_28c = NFA(
    states = {'q0', 'q1', 'q2', 'q3','q4','q5','q6','q7','q8','q9','q10','q11'},
    input_symbols = {'a', 'b'},
    transitions = {
        'q0': {'': {'q1', 'q3'}},
        'q1': {'a': {'q2'}},
        'q2': {'': {'q6'}},
        'q3': {'b': {'q4'}},
        'q4': {'': {'q5'}},
        'q5': {'b': {'q5'},'': {'q6'}},
        'q6': {'a': {'q7'}},
        'q7': {'': {'q8'}},
        'q8': {'a': {'q8'}, '':{'q9'}},
        'q9': {'b': {'q10'}},
        'q10': {'': {'q11'}},
        'q11': {'b': {'q11'}},
    },
    initial_state = 'q0',
    final_states = {'q11'},
)

