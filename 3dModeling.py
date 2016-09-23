import serial
import math
import matplotlib.pyplot as plt

startFlag = False
finishCycle = False
initialize = False


horizontalList = []
verticalList = []

with serial.Serial('/dev/cu.usbmodem1421', 9600, timeout=1) as ser:
	while not initialize:
		line = ser.readline()
		print line
		if line.strip() == "BEGIN_SCAN":
			initialize = True

	while not finishCycle:
		line = ser.readline()
		print line
		if line.strip() == "START_LINE":
			startFlag = True
			horizontalList = []
			continue
		if line.strip() == "END_LINE":
			if startFlag == True:
				startFlag = False
				verticalList.append(horizontalList)
				horizontalList = []
		if line.strip() == "FINISH":
			finishCycle = True
		if startFlag:
			fLine = float(line)
			horizontalList.append(fLine)
print "horizontal: ", len(verticalList[0])
print "vertical: ", len(verticalList)
print "out of the loop"

def dgreeToRadian(degreeAngle):
	return degreeAngle*math.pi/180

def getXYZ(dList, phi):
	angleList = range(65, 116)
	xList = []
	yList = []
	zList = []

	for index in range(len(dList)):
		d = dList[index]
		dxy = d*math.cos(dgreeToRadian(phi))
		xList.append(dxy*math.cos(dgreeToRadian(angleList[index])))
		yList.append(dxy*math.sin(dgreeToRadian(angleList[index])))
		zList.append(d*math.sin(dgreeToRadian(phi)))
	return xList, yList, zList

for index in range(len(verticalList)):
	xList, yList, zList = getXYZ(verticalList[index], index)
	plt.plot(xList, yList, 'ro')
plt.show()








