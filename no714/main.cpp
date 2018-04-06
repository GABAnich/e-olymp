#include <iostream>
#include <cmath>

using namespace std;

bool isOnLine = false;

double min(double a, double b)
{
	return a < b ? a : b;
}

double max(double a, double b)
{
	return a > b ? a : b;
}

void lexicographicalOrder(double x1, double y1, double x2, double y2)
{
  x1 = round(x1 * 10000000000)/10000000000;
  y1 = round(y1 * 10000000000)/10000000000;
  x2 = round(x2 * 10000000000)/10000000000;
  y2 = round(y2 * 10000000000)/10000000000;
  
  if ( x1 < x2 )
    {
      printf("%.10f\n", x1);
      printf("%.10f\n", y1);
      printf("%.10f\n", x2);
      printf("%.10f\n", y2);
    }
    else if (x1 > x2)
    {
      printf("%.10f\n", x2);
      printf("%.10f\n", y2);
      printf("%.10f\n", x1);
      printf("%.10f\n", y1);
    }
    else if (x1 == x2)
    {
      if ( y1 < y2 )
      {
        printf("%.10f\n", x1);
        printf("%.10f\n", y1);
        printf("%.10f\n", x2);
        printf("%.10f\n", y2);
      }
      else if (y1 > y2)
      {
        printf("%.10f\n", x2);
        printf("%.10f\n", y2);
        printf("%.10f\n", x1);
        printf("%.10f\n", y1);
      }
      // Якщо точки співпадають, то це одна точка
      else
      {
        printf("%.10f\n", x1);
        printf("%.10f\n", y1);
      }
    }
}

double lineLength(double x1, double y1, double x2, double y2)
{
	return (pow(sqrt(abs(x1 - x2)), 2) + pow(sqrt(abs(y1 - y2)), 2));
}

bool segmentIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double* px, double* py)
{
	if ((min(x1, x2) <= *px && *px <= max(x1, x2)) &&
		  (min(y1, y2) <= *py && *py <= max(y1, y2)) &&
		  (min(x3, x4) <= *px && *px <= max(x3, x4)) &&
		  (min(y3, y4) <= *py && *py <= max(y3, y4)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool lineIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double* px, double* py)
{
  // Перевірка чи лежать на одній прямі
  // Знайдемо рівняння прямої, по координатах першого відрізка
  // Ax + By + C = 0
  // Всі x та y, які підходять у це рівняння це наша пряма
  // Підставляємо дві точки з другого відрізка, якщо співпадають, тоді відрізки лежать в одній прямі
  // (y1-y2)x + (x2-x1)y + (x1*y2-x2*y1) = 0
  if ( ((y1-y2) * x3 + (x2-x1) * y3 + (x1 * y2 - x2 * y1)) == 0  &&
       ((y1-y2) * x4 + (x2-x1) * y4 + (x1 * y2 - x2 * y1)) == 0)
  {
    isOnLine = true;
    // cout << "Відрізки лежать на одній прямі" << endl;
    
    // Умова перетину відрізків, які лежать на одній прямі - одна 
    // із точок (початок або кінець) другого відрізка знаходиться в так званому квадраті 
    // першого відрізка
    if (!(  (min(x1, x2) <= x3 && x3 <= max(x1, x2)) ||
      		  (min(y1, y2) <= y3 && y3 <= max(y1, y2)) ||
      		  (min(x1, x2) <= x4 && x4 <= max(x1, x2)) ||
      		  (min(y1, y2) <= y4 && y4 <= max(y1, y2))) )
    {
      // cout << "Відрізки не перетинаються" << endl;
      return false;
    }
    
    // Оскільки відрізки лежать на одній прямі і перетинаються, то спільний відрізок буде
    // складатись з двох точок, кожна з який, описує один відрізок і належить другому.
    
    double firstX = 0;
    double firstY = 0;
    double secondX = 0;
    double secondY = 0;
    
    // Якщо xy3 лежить між xy1 та xy2
    if ( (min(x1, x2) <= x3 && x3 <= max(x1, x2)) &&
		     (min(y1, y2) <= y3 && y3 <= max(y1, y2)) )
    {
      firstX = x3;
      firstY = y3;
    }
    // Якщо xy4 лежить між xy1 та xy2
    else if ( (min(x1, x2) <= x4 && x4 <= max(x1, x2)) &&
		          (min(y1, y2) <= y4 && y4 <= max(y1, y2)) )
    {
      firstX = x4;
      firstY = y4;
    }
    
    // Якщо xy1 лежить між xy3 та xy4
    if ( (min(x3, x4) <= x1 && x1 <= max(x3, x4)) &&
		     (min(y3, y4) <= y1 && y1 <= max(y3, y4)) )
    {
      secondX = x1;
      secondY = y1;
    }
    // Якщо xy2 лежить між xy3 та xy4
    else if ( (min(x3, x4) <= x2 && x2 <= max(x3, x4)) &&
		          (min(y3, y4) <= y2 && y2 <= max(y3, y4)) )
    {
      secondX = x2;
      secondY = y2;
    }
    
    lexicographicalOrder(firstX, firstY, secondX, secondY);
    
    return true;
  }
	
	// Перевірка на паралельність або співпадіння (відрізки лежать на одній прямі)
  if ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4) == 0)
	{
	 // cout << "Паралельні або лежать на одній прямі" << endl;
	  
		return false;
	}
	
	// !!!! Неправильний порядок виконання програми
	// Якщо xy1 == xy2, то xy1(xy2) точка перетину, бо відрізки перетинаються
  if (x1 == x2 && y1 == y2)
  {
    *px = x1;
    *py = y1;
    
    return true;
  }
  else if (x3 == x4 && y3 == y4)
  {
    *px = x3;
    *py = y4;
    
    return true;
  }

	*px = (double)((x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4)) / ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4));
	*py = (double)((x1*y2 - y1*x2)*(y3 - y4) - (x1 - y2)*(x3*y4 - y3*x4)) / ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4));

	if (!segmentIntersection(x1, y1, x2, y2, x3, y3, x4, y4, px, py))
	{
		return false;
	}

	return true;
}

int main()
{
	// Введення даних
	int x0, y0, x1, y1, x2, y2, x3, y3;
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	// Знаходження точки перетину
	double px, py;
	if ( !lineIntersection(x0, y0, x1, y1, x2, y2, x3, y3, &px, &py) )
	{
	  cout << "Empty" << endl;
	}
	else if (isOnLine)
  {
    return 0;
  }
	else
	{
	  printf("%.10f\n", round(px * 10000000000)/10000000000);
	  printf("%.10f\n", round(py * 10000000000)/10000000000);
	}
	
	return 0;
}