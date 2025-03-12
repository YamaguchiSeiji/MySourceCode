import java.util.Calendar;

class ExClock extends Clock{
	private boolean showsIn24hours;

	ExClock(boolean showsSecond){
		super(showsSecond);
	}
	
	void changeMode(){
		if(showsIn24hours){
			showsIn24hours = false;
			System.out.println("Switched to 12h (AM / PM) format.");
		} else {
			showsIn24hours = true;
			System.out.println("Switched to 24h format.");
		}
	}
	
	String get12TimeString(int hour, int min, int sec){
		if(hour >= 13){
			return hour-12 + ":" + min + " PM";
		} else {
			return hour + ":" + min + " AM";
		}
	}

	@Override
	String getTimeString(int hour, int min, int sec){
		return hour + ":" + min;	
	}

	void show(){
		Calendar cal = Calendar.getInstance();
		int hour = cal.get(Calendar.HOUR_OF_DAY);
		int min = cal.get(Calendar.MINUTE);
		int sec = cal.get(Calendar.SECOND);
		if(showsIn24hours){
			System.out.println(getTimeString(hour, min, sec));
		} else {
			System.out.println(get12TimeString(hour, min, sec));
		}
	}
}
