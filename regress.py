import numpy
import matplotlib.pyplot as plt

degree2 = 2
degree3 = 3 

y_nums = [15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65]
x_nums = [2.81, 2.6, 2.34, 2.02, 1.76, 1.55, 1.38, 1.24, 1.15, 1.07, 1.01]

x = numpy.array(x_nums)
y = numpy.array(y_nums)

z = numpy.polyfit(x, y, degree2)
z1 = numpy.polyfit(x, y, degree3)

print z1

train_y = numpy.poly1d(z)
train_y2 = numpy.poly1d(z1)

new_y = train_y(x)
new_y1 = train_y2(x)

plt.plot(x_nums, y_nums, 'ro')
plt.plot(x_nums, new_y, 'bo')
plt.plot(x_nums, new_y1, 'go')
plt.show()
