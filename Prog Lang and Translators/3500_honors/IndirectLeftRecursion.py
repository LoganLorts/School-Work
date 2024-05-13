def is_terminal(symbol):
    if symbol.islower() or symbol.isnumeric():
        return True
    return False

def remove_left_recursion(grammar):
    new_grammar = {}
    
    for non_terminal, productions in grammar.items():
        # Split productions into those with and without left recursion
        recursive_productions = []
        non_recursive_productions = []
        
        for production in productions:
            if production[0] == non_terminal:
                recursive_productions.append(production[1:])
            else:
                non_recursive_productions.append(production)
        
        if len(recursive_productions) == 0:
            new_grammar[non_terminal] = productions
        else:
            new_non_terminal = non_terminal + "'"
            new_grammar[new_non_terminal] = [production + (new_non_terminal,) for production in recursive_productions] + [('ε',)]
            new_productions = [production + (new_non_terminal,) for production in non_recursive_productions]
            new_grammar[non_terminal] = new_productions
    
    return new_grammar


def remove_indirect_recursion(grammer):
    for non_terminal, productions in grammer.items():
        for production in productions:
            if not is_terminal(production[0]):
                for production1 in grammer[production[0]]:
                    grammer[non_terminal].append(production1 + production[1:])
                    grammer[non_terminal] = [production for production in grammer[non_terminal] if production[0] != non_terminal]
        
    return grammer
            
# Example usage:
grammar = {
    'S': [('a', 'A'), ('S', 'c')],
    'A': [('A', 'B', 'b'), ('A', 'd'), ('ε',)],
    'B': [('A', 'd'), ('S', 'c')]
}
x = 0
while True:
    new_grammar = remove_left_recursion(grammar)
    new_grammar = remove_indirect_recursion(new_grammar)
    if new_grammar == x:
        for non_terminal, productions in new_grammar.items():
            print(non_terminal, '->', ' | '.join([' '.join(production) for production in productions]))
        break
    x = new_grammar
