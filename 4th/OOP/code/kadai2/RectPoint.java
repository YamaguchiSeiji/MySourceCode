class RectPoint {
	private int x;
	private int y;

	RectPoint(int x, int y){
		this.x = x;
		this.y = y;
	}

	int getX(){
		return x;
	}

	int getY(){
		return y;
	}

	private int getQuad(){
		if(x > 0 && y > 0)
		{
			return 1;
		}
		else if(x < 0 && y > 0)
		{
			return 2;
		}
		else if(x < 0 && y < 0)
		{
			return 3;
		}
		else if(x >0 && y < 0)
		{
			return 4;
		}
		else
		{
			return 0;
		}
	}

	boolean isSameQuad(RectPoint rp){
		if(this.getQuad() == rp.getQuad())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	public String toString(){
		return x + "," + y + "(" + this.getQuad() + ")";
	}

}
