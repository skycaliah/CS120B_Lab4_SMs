# Test sequence from waitA0: A0, !A0, A1 => PORTB: 0xF0
tests = [ {'description': 'PINA: 0x00, 0x01, 0x00 => PORTB: 2, state:L_WaitOne ',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 2},
        {'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2}],
    'expected': [('PORTB',0x02)],
    },
    

  {'description': 'PINA: 0x00, 0x00, 0x00 => PORTB: 2, state:L_WaitOne ',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2}],
    'expected': [('PORTB',0x02)],
    }
  ,
 {'description': 'PINA: 0x01, 0x01, 0x01 => PORTB: 1, state:L_ZeroOn ',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x01)], 'iterations': 2}],
    'expected': [('PORTB',0x01)],
    },

 {'description': 'PINA: 0x01, 0x00, 0x00 => PORTB: 1, state:L_WaitZero ',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2}],
    'expected': [('PORTB',0x01)],
    },



    ]
watch = ['L_State']
