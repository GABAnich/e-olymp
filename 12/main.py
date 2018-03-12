import math

def line_intersection(line1, line2):
  xdiff = (line1[0][0] - line1[1][0], line2[0][0] -       line2[1][0])
  ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1]) #Typo was here

  def det(a, b):
      return a[0] * b[1] - a[1] * b[0]

  div = det(xdiff, ydiff)
  if div == 0:
     raise Exception('lines do not intersect')

  d = (det(*line1), det(*line2))
  x = det(d, xdiff) / div
  y = det(d, ydiff) / div
  return x, y

"""
#input x0, y0, x1, y1, x2, y2, x3, y3, h
x0, y0, x1, y1, x2, y2, x3, y3, h = input().split(' ')
x0 = int(x0)
y0 = int(y0)
x1 = int(x1)
y1 = int(y1)
x2 = int(x2)
y2 = int(y2)
x3 = int(x3)
y3 = int(y3)
h = int(h)
"""

x0 = 1
y0 = 1
x1 = 6
y1 = 1
x2 = 4
y2 = 0
x3 = 4
y3 = 5
h = 6

radius = math.sqrt( (abs(x0-x1)) ** 2 + (abs(y0-y1)) ** 2 )

xP, yP = line_intersection((x0, y0), (x1, y1))

print(xP, yP)