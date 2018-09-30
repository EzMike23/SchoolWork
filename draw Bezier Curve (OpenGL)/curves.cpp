//CS3388 ASN3
//Yixin Zhang
//#250817133
//This program is mainly about drawing B-spline curve and Beta-spline curve
#include "curves.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
// #include <GL/glut.h>

#include <cmath>
#include <cassert>
#include <iostream>


Vector2D curveOperations::evaluateBezier(float t) const
{
    assert(t >= 0.0f && t <= 1.0f);
    assert(controlPoints.size() > 1);

    // Evaluate the Bezier curve at the given t parameter.
    // You may find the following functions useful:
    //  - curveOperations::binomialCoefficient(m,i) computes "m choose i", 
    //      aka: (m over i)
    //  - std::pow(t,i) computes t raised to the power i

    //@@@@@@@@@@
    // YOUR CODE HERE
    Vector2D p;
    unsigned int L = controlPoints.size() - 1;
    unsigned int fac_L = 1;
    
    for (unsigned int i = 1; i <= L; i++)
    {
        fac_L *= i;
    }
    
    for (unsigned int i = 0; i < controlPoints.size(); i++)
    {
        Vector2D p_i = controlPoints[i];
        
        float f1 = pow(1.0 - t, (double)(L - i));
        float f2 = pow((double)t, (double)i);
        
        unsigned int fac_i = 1;
        
        for (unsigned int j = 1; j <= i; j++)
        {
            fac_i *= j;
        }
        
        unsigned int fac_L_i = 1;
        
        for (unsigned int j = 1; j <= L - i; j++)
        {
            fac_L_i *= j;
        }
        
        p += fac_L / (fac_i * fac_L_i) * f1 * f2 * p_i;
    }
	
	return p; // REPLACE THIS (used only to compile the code)

    //@@@@@@@@@@
}

void curveOperations::drawBezier() const
{
    // Draw this Bezier curve.
    // Do this by evaluating the curve at some finite number of t-values,
    // and drawing line segments between those points.
    // You may use the curveOperations::drawLine() function to do the actual
    // drawing of line segments.

    //@@@@@@@@@@
    // YOUR CODE HERE

    float t = 0.0f;
    Vector2D lastPoint = evaluateBezier(0.0f);
    
    for (t = 0.0f; t <= 1.0f; t += 0.01f)
    {
        Vector2D p = evaluateBezier(t);
        
        drawLine(lastPoint, p);
        
        lastPoint = p;
    }

    //@@@@@@@@@@
 
}


void curveOperations::drawControlPolygon() const
{
    for (size_t i = 1; i < controlPoints.size(); ++i)
    {
        drawLine(controlPoints[i-1], controlPoints[i]);
    }
}


unsigned long curveOperations::binomialCoefficient(int n, int k)
{
    // Compute nCk ("n choose k")
    // WARNING: Vulnerable to overflow when n is very large!

    assert(k >= 0);
    assert(n >= k);

    unsigned long result = 1;
    for (int i = 1; i <= k; ++i)
    {
        result *= n-(k-i);
        result /= i;
    }
    return result;
}


void curveOperations::drawLine(const Vector2D& p1, const Vector2D& p2)
{
    glBegin(GL_LINES);
    glVertex2f(p1[0], p1[1]);
    glVertex2f(p2[0], p2[1]);
    glEnd();
}



// draw cubic bspline
void curveOperations::drawCubicBspline() const
{
	//@@@@@@@@@@
    // YOUR CODE HERE
    unsigned int n = controlPoints.size();
    Vector2D p_last;
    
    for (float u = 0.0f; u <= 1.0f; u += 0.01f)
    {
        Vector2D p_u;
        
        for (int i = 0; i < (int)(n); i++)
        {
            float t = (n - 1) * u - i;
            float b;
            
            if ( i < floor( n * u - 2 ) || i > ceil( n * u + 2 ))
                continue;
            
            if (t >= -2.0f && t < -1.0f)
            {
                b = (2 + t) * (2 + t) * (2 + t) / 6.0f;
            }
            else if (t >= -1.0f && t < 0.0f)
            {
                b = (4 - 6 * t * t - 3 * t * t * t) / 6.0f;
            }
            else if (t >= 0.0f && t < 1.0f)
            {
                b = (4 - 6 * t * t + 3 * t * t * t) / 6.0f;
            }
            else if (t >= 1.0f && t <= 2.0f)
            {
                b = (2 - t) * (2 - t) * (2 - t) / 6.0f;
            }
            else
            {
                b = 0.0f;
            }
            
            p_u += b * controlPoints[i];
        }
        
        if (u == 0.0f)
            p_last = p_u;
            
        drawLine(p_last, p_u);
        p_last = p_u;
    }


	//@@@@@@@@@@
}


// draw betaspline
void curveOperations::drawBetaspline() const
{
	//@@@@@@@@@@
    // YOUR CODE HERE
    unsigned int n = controlPoints.size();
    Vector2D p_last;
    float S = 1.0f;
    float T = 10.0f;
    float delta = T + 2 * S * S * S + 4 * S * S + 4 * S + 2;

    for (float u = 0.0f; u <= 1.0f; u += 0.01f)
    {
        Vector2D p_u;

        for (int i = 0; i < (int)(n); i++)
        {
            float t = (n - 1) * u - i;
            float b;

            if ( i < floor( n * u - 2 ) || i > ceil( n * u + 2 ))
                continue;

            if (t >= -2.0f && t < -1.0f)
            {
                b = 2 * (2 + t) * (2 + t) * (2 + t) / delta;
            }
            else if (t >= -1.0f && t < 0.0f)
            {
                b = T + 4 * S + 4 * S * S - 6 * (1 - S * S) * t - 3 * t * t * ( 2 + T + 2 * S) - 2 * t * t * t * (1 + T + S + S * S);
                b /= delta;
            }
            else if (t >= 0.0f && t < 1.0f)
            {
                b = T + 4 * S + 4 * S * S - 6 * (S - S * S * S) * t - 3 * t * t * ( T + 2 * S * S + 2 * S * S * S) + 2 * t * t * t * (T + S + S * S + S * S * S);
                b /= delta;
            }
            else if (t >= 1.0f && t <= 2.0f)
            {
                b = 2.0f * S * S *S * (2 - t) * (2 - t) * (2 - t) / delta;
            }
            else
            {
                b = 0.0f;
            }

            p_u += b * controlPoints[i];
        }

        if (u == 0.0f)
            p_last = p_u;

        drawLine(p_last, p_u);
        p_last = p_u;
    }


	//@@@@@@@@@@
}


// draw betaspline for closed curve
void curveOperations::drawBetasplineClosedCurve() const
{
	//@@@@@@@@@@
    // YOUR CODE HERE
    unsigned int n = controlPoints.size();
    Vector2D p_last;
    Vector2D p_first;
    float S = 1.0f;
    float T = 10.0f;
    float delta = T + 2 * S * S * S + 4 * S * S + 4 * S + 2;

    for (float u = 0.0f; u <= 1.0f; u += 0.01f)
    {
        Vector2D p_u;

        for (int i = 0; i < (int)(n); i++)
        {
            float t = (n - 1) * u - i;
            float b;

            if ( i < floor( n * u - 2 ) || i > ceil( n * u + 2 ))
                continue;

            if (t >= -2.0f && t < -1.0f)
            {
                b = 2 * (2 + t) * (2 + t) * (2 + t) / delta;
            }
            else if (t >= -1.0f && t < 0.0f)
            {
                b = T + 4 * S + 4 * S * S - 6 * (1 - S * S) * t - 3 * t * t * ( 2 + T + 2 * S) - 2 * t * t * t * (1 + T + S + S * S);
                b /= delta;
            }
            else if (t >= 0.0f && t < 1.0f)
            {
                b = T + 4 * S + 4 * S * S - 6 * (S - S * S * S) * t - 3 * t * t * ( T + 2 * S * S + 2 * S * S * S) + 2 * t * t * t * (T + S + S * S + S * S * S);
                b /= delta;
            }
            else if (t >= 1.0f && t <= 2.0f)
            {
                b = 2.0f * S * S *S * (2 - t) * (2 - t) * (2 - t) / delta;
            }
            else
            {
                b = 0.0f;
            }

            p_u += b * controlPoints[i];
        }

        if (u == 0.0f)
        {
            p_last = p_u;
            p_first = p_u;
        }

        drawLine(p_last, p_u);
        p_last = p_u;
    }
    
    drawLine(p_last, p_first);	


	//@@@@@@@@@@
}

// draw cubic bspline with phantom endpoints
void curveOperations::drawCubicBsplinePhantom() const
{
	//@@@@@@@@@@
    // YOUR CODE HERE
    unsigned int n = controlPoints.size();
    Vector2D p_last;

    for (float u = 0.0f; u <= 1.0f; u += 0.01f)
    {
        Vector2D p_u;

        for (int i = -1; i < (int)(n + 1); i++)
        {
            float t = (n - 1) * u - i;
            float b;

            if ( i < floor( n * u - 2 ) || i > ceil( n * u + 2 ))
                continue;

            if (t >= -2.0f && t < -1.0f)
            {
                b = (2 + t) * (2 + t) * (2 + t) / 6.0f;
            }
            else if (t >= -1.0f && t < 0.0f)
            {
                b = (4 - 6 * t * t - 3 * t * t * t) / 6.0f;
            }
            else if (t >= 0.0f && t < 1.0f)
            {
                b = (4 - 6 * t * t + 3 * t * t * t) / 6.0f;
            }
            else if (t >= 1.0f && t <= 2.0f)
            {
                b = (2 - t) * (2 - t) * (2 - t) / 6.0f;
            }
            else
            {
                b = 0.0f;
            }

            if (i == -1)
                p_u += b * ( 2 * controlPoints[0] - controlPoints[1]);
            else if (i == n)
                p_u += b * ( 2 * controlPoints[n - 1] - controlPoints[n - 2]);
            else
                p_u += b * controlPoints[i];
        }

        if (u == 0.0f)
            p_last = p_u;

        drawLine(p_last, p_u);
        p_last = p_u;
    }


	//@@@@@@@@@@
}



/*************************** You don't need to modify this block ***************************/
void CurveManager::drawCurves() const
{
    if (points == NULL || points->size() < 2)
    {
        return;
    }

    if (curveMode == BEZIER_MODE)
    {
        // Basic Mode (default)
        // Create a Bezier curve from the entire set of points,
        // and then simply draw it to the screen.
        
        curveOperations curve(*points);
        curve.drawBezier();

    }
	else
		if (curveMode == CUBIC_BSPLINE_MODE)
		{
			// mode to draw a cubic b-spline
			curveOperations curve(*points);
			curve.drawCubicBspline();
		}
		else
			if (curveMode == BETA_SPLINE_MODE)
			{
				// mode to draw a beta-spline
				curveOperations curve(*points);
				curve.drawBetaspline();
			}
			else
				if (curveMode == BETA_SPLINE_CLOSEDCURVE_MODE)
				{
					// mode to draw a beta-spline for closed curve
					curveOperations curve(*points);
					curve.drawBetasplineClosedCurve();
				} 
				else
					if (curveMode == CUBIC_BSPLINE_PHANTOM_MODE)
					{
						// mode to draw a cubic b-spline with phantom endpoints
						curveOperations curve(*points);
						curve.drawCubicBsplinePhantom();
					}
}
/*************************** You don't need to modify this block ***************************/


