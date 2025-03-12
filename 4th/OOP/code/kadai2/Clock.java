import java.util.Calendar;

class Clock{
	private boolean showsSecond;

	Clock(boolean showsSecond){
		this.showsSecond = showsSecond;
	}

	String getTimeString(int hour, int min, int sec){
		if(showsSecond){
			return hour + ":" + min + ":" + sec;
		} else {
			return hour + ":" + min;
		}
	}

	void show(){
		Calendar cal = Calendar.getInstance();
		int hour = cal.get(Calendar.HOUR_OF_DAY);
		int min = cal.get(Calendar.MINUTE);
		int sec = cal.get(Calendar.SECOND);
		System.out.println(getTimeString(hour, min, sec));
	}
}
