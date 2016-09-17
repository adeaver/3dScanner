import serial
import math
import matplotlib.pyplot as plt

startFlag = False
finishCycle = False

with serial.Serial('/dev/cu.usbmodem1421', 9600, timeout=1) as ser:
     while not finishCycle:
		line = ser.readline()
		print line
		if line.strip() == "START":
			startFlag = True
			xyList = []
			continue
		if line.strip() == "END":
			if startFlag == True:
				finishCycle = True
				startFlag = False
				break
		if startFlag:
			fLine = float(line)
			xyList.append(fLine)

print "out of the loop"
angleList = range(65, 116)
xList = []
yList = []
for index in range(len(xyList)):
	dst = xyList[index]
	xList.append(dst*math.cos(angleList[index]*math.pi/180))
	yList.append(dst*math.sin(angleList[index]*math.pi/180))


plt.plot(xList, yList, 'ro')
plt.show()








