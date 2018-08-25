import math

def segmentIntersection(A, B, C, D, P):
  return ( min(A[0], B[0]) <= P[0] and P[0] <= max(A[0], B[0]) ) and \
         ( min(A[1], B[1]) <= P[1] and P[1] <= max(A[1], B[1]) ) and \
         ( min(C[0], D[0]) <= P[0] and P[0] <= max(C[0], D[0]) ) and \
         ( min(C[1], D[1]) <= P[1] and P[1] <= max(C[1], D[1]) )

def lineIntersection(x1, y1, x2, y2, x3, y3, x4, y4):
  # is parallel
  if (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4) == 0:
    return None, None

  px = ( (x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4) ) / ( (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4) )
  py = ( (x1*y2-y1*x2)*(y3-y4)-(x1-y2)*(x3*y4-y3*x4) ) / ( (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4) )

  # segment intersection
  if not segmentIntersection( (x1, y1), (x2, y2), (x3, y3), (x4, y4), (px, py) ):
    return None, None

  return px, py

def lineLength(x1, y1, x2, y2):
  return math.sqrt( (abs(x1 - x2)) ** 2 + (abs(y1 - y2)) ** 2 )

""" Введення даних """
x0, y0, x1, y1, x2, y2, x3, y3, h = map(int, input().split())

""" Знаходження точки перетину """

x, y = lineIntersection(x0, y0, x1, y1, x2, y2, x3, y3)
if (x == None and y == None):
  print(0.000)
  exit(1)

""" Знаходження радіусу (довжини римської I) """
radius = lineLength(x0, y0, x1, y1)

""" Знаходження довжини першого катета """
firsCatet = lineLength(x0, y0, x, y)

""" Знаходження другого катета """
secondCatet = math.sqrt( radius ** 2 - firsCatet ** 2 )

""" Довжина розриву """
print( "%.3f" % min(secondCatet, h) )