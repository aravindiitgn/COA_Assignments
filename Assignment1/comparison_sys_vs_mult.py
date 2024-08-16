import matplotlib.pyplot as plt
import numpy as np

# Data
languages = {
    'cpp': {
        'integer': {
            'elapsed': [0.00124548, 0.0129012, 0.0916474, 0.775512, 7.02308],
            'sys': [0.005, 0.000, 0.000, 0.000, 0.010]
        },
        'double': {
            'elapsed': [0.0013017, 0.0112976, 0.100147, 0.817398, 12.1445],
            'sys': [0.000, 0.000, 0.000, 0.000, 0.010]
        }
    },
    'python': {
        'integer': {
            'elapsed': [0.06, 0.48, 3.93, 33.79, 300.83],
            'sys': [1.531, 1.502, 1.371, 1.351, 1.490]
        },
        'double': {
            'elapsed': [0.07, 0.55, 4.14, 36.24, 319.81],
            'sys': [1.512, 1.412, 1.466, 1.416, 1.381]
        }
    }
}


language = 'python'  
data_type = 'double' 


sizes = [64, 128, 256, 512, 1024]


elapsed_times = languages[language][data_type]['elapsed']
sys_times = languages[language][data_type]['sys']


bar_width = 0.35
indices = np.arange(len(sizes))


plt.figure(figsize=(12, 6))

plt.bar(indices, elapsed_times, bar_width, label='Elapsed Time', color='lightblue')
plt.bar(indices + bar_width, sys_times, bar_width, label='System Time', color='lightcoral')

plt.xlabel('Matrix Size (NxN)')
plt.ylabel('Time in Seconds')
plt.title(f'{language.capitalize()} {data_type.capitalize()} Matrix Multiplication: System vs Elapsed Time')
plt.xticks(indices + bar_width / 2, sizes, rotation=45)
plt.yscale('log') 
plt.legend()
plt.tight_layout()
plt.savefig('python_double.png')
plt.show()
