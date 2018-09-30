//Code for the colors
#ifndef _COLOR_H_
#define _COLOR_H_


class color
{
public:
	color(){}

	color(float r_, float g_, float b_)
	:	r(r_), g(g_), b(b_) 
	{}

	color(const color& rhs)
	:	r(rhs.r),
		g(rhs.g),
		b(rhs.b)
	{}

	~color(){}

	static color red()		{	return color(1.0f ,0.0f ,0.0f); }
	static color green()	{	return color(0.0f ,1.0f ,0.0f); }
	static color blue() 	{	return color(0.0f ,0.0f ,1.0f); }
	static color grey()	{	return color(0.5f ,0.5f ,0.5f); }
	static color yellow()	{	return color(1.0f ,1.0f ,0.0f); }
	static color black()	{	return color(0.0f ,0.0f ,0.0f); }
	static color white()	{	return color(1.0f ,1.0f ,1.0f); }

	inline void set(float r_, float g_, float b_)
	{
		r = r_;
		g = g_;
		b = b_;
	}

	inline color operator * (float scale) const
	{
		return color(r * scale, g * scale, b * scale);
	}

	inline color& operator *= (float scale)
	{
		r *= scale;
		g *= scale;
		b *= scale;

		return *this;
	}

	inline color operator + (const color& rhs) const
	{
		return color(r + rhs.r, g + rhs.g, b + rhs.b);
	}

	inline void operator = (const color& rhs)
	{
		r = rhs.r;
		g = rhs.g;
		b = rhs.b;
	}

	inline void operator += (const color& rhs)
	{
		r += rhs.r;
		g += rhs.g;
		b += rhs.b;
	}

	inline color& operator *= (const color& rhs)
	{
		r *= rhs.r;
		g *= rhs.g;
		b *= rhs.b;
	
		return *this;
	}

	inline const color operator * (const color& rhs) const
	{
		return color(r * rhs.r, g * rhs.g, b * rhs.b);
	}

	inline void setToMult(const color& other, float factor)
	{
		r = other.r * factor;
		g = other.g * factor;
		b = other.b * factor;
	}

	inline void addMult(const color& other, float factor)
	{
		r += other.r * factor;
		g += other.g * factor;
		b += other.b * factor;
	}

	inline void add(const color& other)
	{
		r += other.r;
		g += other.g;
		b += other.b;
	}

	inline void clipComponents()
	{
		if(r < 0.0f)
			r = 0.0f;
		else if(r > 1.0f)
			r = 1.0f;

		if(g < 0.0f)
			g = 0.0f;
		else if(g > 1.0f)
			g = 1.0f;

		if(b < 0.0f)
			b = 0.0f;
		else if(b > 1.0f)
			b = 1.0f;
	}

	inline void positiveClipComponents()
	{
		if(r > 1.0f)
			r = 1.0f;

		if(g > 1.0f)
			g = 1.0f;

		if(b > 1.0f)
			b = 1.0f;
	}

	const float* toFloatArray() const { return (const float*)this; }
	const float* data() const { return (const float*)this; }
	

	float r,g,b;
};


#endif //_COLOR_H_