#include <iostream>
#include <cmath>

using namespace std;

double min(double a, double b)
{
	return a < b ? a : b;
}

double max(double a, double b)
{
	return a > b ? a : b;
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

bool lineIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int h, double* px, double* py)
{
  
  // �������� �� ������ �� ���� ����
  // �������� ������� �����, �� ����������� ������� ������
  // Ax + By + C = 0
  // �� x �� y, �� �������� � �� ������� �� ���� �����
  // ϳ���������� �� ����� � ������� ������, ���� ����������, ��� ������ ������ � ���� ����
  // (y1-y2)x + (x2-x1)y + (x1*y2-x2*y1) = 0
  if ( ((y1-y2) * x3 + (x2-x1) * y3 + (x1 * y2 - x2 * y1)) == 0  &&
       ((y1-y2) * x4 + (x2-x1) * y4 + (x1 * y2 - x2 * y1)) == 0)
  {
    cout << "³����� ������ �� ���� ����" << endl;
    
    // ����� �������� ������, �� ������ �� ���� ���� - ���� 
    // �� ����� (������� ��� �����) ������� ������ ����������� � ��� ������� ������� 
    // ������� ������
    if (!(  (min(x1, x2) <= x3 && x3 <= max(x1, x2)) ||
      		  (min(y1, y2) <= y3 && y3 <= max(y1, y2)) ||
      		  (min(x1, x2) <= x4 && x4 <= max(x1, x2)) ||
      		  (min(y1, y2) <= y4 && y4 <= max(y1, y2))) )
    {
      cout << "³����� �� �������������" << endl;
      return false;
    }
    
    if ( lineLength(x1, y1, x3, y3) < lineLength(x1, y1, x4, y4) )
    {
      *px = x3;
      *py = y3;
    }
    else
    {
      *px = x4;
      *py = y4;
    }
    
    return true;
  }
	
	// �������� �� ������������ ��� ��������� (������ ������ �� ���� ����)
  if ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4) == 0)
	{
	  cout << "��������� ��� ������ �� ���� ����" << endl;
	  
		return false;
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
	// �������� �����
	int x0, y0, x1, y1, x2, y2, x3, y3, h;
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> h;

	// ����������� ����� ��������
	double px, py;
	if (!lineIntersection(x0, y0, x1, y1, x2, y2, x3, y3, h, &px, &py))
	{
		printf("%.3f", 0.000);
		return 0;
	}
	
	// ����������� ������
	double radius = lineLength(x0, y0, x1, y1);

	// ����������� ������� ������� ������
	double firsCatet = lineLength(x0, y0, px, py);

	// ����������� ������� ������
	double secondCatet = sqrt(radius * radius - firsCatet * firsCatet);

	// ������� �������
	printf("%.3f", min( round(secondCatet * 1000) / 1000, h));



// 	cout << x0 << " " << y0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << h << endl;

// 	cout << px << " " << py << endl;
	return 0;
}