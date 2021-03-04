import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as mtick
from matplotlib.patches import ConnectionPatch

import pandas
#data = pandas.read_csv('trace_fields_1_6mm.csv', sep=',', usecols=[0,1], names=['size', 'field'])
data = pandas.read_csv('wire_fields.csv', sep=',', usecols=[0,1], names=['size', 'field'])
print(list(data.columns))

trace_size = data['size']
field_strength = data['field']



mag_line = plt.plot(trace_size, field_strength)


plt.ylabel('Field Strength (gauss/amp)', fontsize=14,)
#plt.xlabel('Trace Width (mm)', fontsize=14)
plt.xlabel('Wire Radius (mm)', fontsize=14)
plt.grid(alpha=0.15)
plt.autoscale(True)
plt.margins(x=0)
plt.title('Sensitivity for Wire', fontsize=12)

plt.tight_layout()
#plt.show()
plt.savefig('wire_radius_plt.png', dpi=300)