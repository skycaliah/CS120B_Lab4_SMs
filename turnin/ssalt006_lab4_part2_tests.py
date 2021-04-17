# Test sequence from waitA0: A0, !A0, A1 => PORTB: 0xF0
tests = [ {'description': 'PINA: 0x02, 0x02, 0x00 => PORTC: 6, state:SM2_ReadyButton ',
    'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 2},
        {'inputs': [('PINA', 0x02)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2}],
    'expected': [('PORTC',0x06)],
    },
    

    {'description': 'PINA: 0x01, 0x00, 0x01 => PORTC: 8, state:SM2_wait_plus ',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 5},
        {'inputs': [('PINA', 0x00)], 'iterations': 5},
        {'inputs': [('PINA', 0x01)], 'iterations': 5}],
    'expected': [('PORTC',0x08)],
    }
  ,
 {'description': 'PINA: 0x00, 0x03, 0x03 => PORTC: 0, state:SM2_Reset ',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 2},
        {'inputs': [('PINA', 0x03)], 'iterations': 2},
        {'inputs': [('PINA', 0x03)], 'iterations': 2}],
    'expected': [('PORTC',0x00)],
    },




    ]
watch = ['SM2_State']
