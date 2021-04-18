# Test sequence from waitA0: A0, !A0, A1 => PORTB: 0xF0
tests = [ {'description': 'PINA: 0x00, 0x04, 0x00, 0x02 => PORTB: 1, state:SM1_unlockDoor ',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 5},
        {'inputs': [('PINA', 0x04)], 'iterations': 5},
        {'inputs': [('PINA', 0x00)], 'iterations': 5},
        {'inputs': [('PINA', 0x02)], 'iterations': 5}],
    'expected': [('PORTB',0x01)],
    },
    
 {'description': 'PINA: 0x00, 0x04, 0x00, 0x02 => PORTB: 0, state:SM1_unlockDoor ',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 5},
        {'inputs': [('PINA', 0x04)], 'iterations': 5},
        {'inputs': [('PINA', 0x00)], 'iterations': 5},
        {'inputs':[('PINA', 0x02)], 'iterations': 5}],
    'expected': [('PORTB',0x00)],
    },


    ]
watch = ['SM1_State']
