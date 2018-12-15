
//此程序返回最小值的一半
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100001

typedef struct Point
{
    int p;
    double x, y;
}Point;
Point X[N],Y[N],Z[N];
double distance(Point u, Point v)
{
    double dx, dy;
    dx = u.x - v.x;
    dy = u.y - v.y;
    return sqrt(dx * dx + dy * dy);
}

int CmpX(const void * a, const void * b)
{
    Point* c = (Point*)a;
    Point* d = (Point*)b;
	if (c->x > d->x) return 1;
	else if (c->x == d->x )return 0;
    else return -1;
}

int CmpY(const void * a, const void * b)
{
     Point* c = (Point*)a;
    Point* d = (Point*)b;
	if (c->y > d->y) return 1;
	else if (c->y == d->y )return 0;
    else return -1;
}

void Merge(Point c[], Point d[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while( (i <= m) && (j <= r) )
    {
        if( c[i].y <= c[j].y )    d[k++] = c[i++];
        else    d[k++] = c[j++];
    }
	while(i <= m)
	{
		d[k++] = c[i++];
	}
	while(j <= r)
	{
		d[k++] = c[j++];
	}
}

double closest(Point X[], Point Y[], Point Z[], int l, int r)
{
    double d1, d2, d3;
    double dr = 0, dp = 0, d = 0;
    int i, j, f, g, k, m;
	//if(r <= l) return 9999999;
    if(r - l == 1)// only two point
        return distance(X[l],X[r]);
    if(r - l == 2)
    {   // three point
        d1 = distance(X[l],X[l+1]);
        d2 = distance(X[l+1],X[r]);
        d3 = distance(X[l],X[r]);
        if(d1 <= d2 && d1 <= d3)     return d1;
        else if(d2 <= d3)    return d2;
        else   return d3;
    }

    m = (l + r) / 2;
    f = l, g = m + 1;
    for( i = l; i <= r; ++i )
    {
        if(Y[i].p > m)  Z[g++] = Y[i];
        else   Z[f++] = Y[i];
    }
    d = closest(X,Z,Y,l,m);
    dr = closest(X,Z,Y,m+1,r);
    if (dr < d)     
	{
		d = dr;
	}
    Merge(Z,Y,l,m,r);  

    k = l;
    for ( i = l; i <= r; ++i )
    {
        if (fabs(Y[m].x - Y[i].x) < d)	 Z[k++] = Y[i];
        
	}
    //搜索Z[1:k-1]   
	for ( i = l; i < k; ++i )
    {
        for ( j = i + 1; j < k && Z[j].y - Z[i].y < d; ++j )
		{dp = distance(Z[i],Z[j]);
        if(dp < d)	  d = dp;}
    }
    return d;
}

int main()
{
    int i, n;
    double  d = 0.0;
    while( scanf("%d",&n) == 1)
    {
        if (n == 0)    break;
        for (i = 0; i < n; ++i)
        {
            scanf("%lf%lf",&X[i].x,&X[i].y);
        }
        qsort(X,n,sizeof(Point),CmpX);

        for ( i = 0; i < n; ++i )
        {
			Y[i].p = i;
            Y[i] = X[i];
        }

        qsort(Y,n,sizeof(Point),CmpY);

        d = closest(X,Y,Z,0,n-1); 
        printf("%.2lf\n",d/2.);
    }
    return 0;
}