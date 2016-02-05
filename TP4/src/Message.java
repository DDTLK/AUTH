import java.sql.Timestamp;
import java.util.Calendar;

public class Message{
	String contenu;
	Timestamp now;
	
	public Message(){
		Calendar calendar = Calendar.getInstance();
		contenu = "";
		now = new Timestamp(calendar.getTimeInMillis());		
	}

	public String getContenu() {
		return contenu;
	}

	public void setContenu(String contenu) {
		this.contenu = contenu;
	}

	public Timestamp getNow() {
		return now;
	}

	public void setNow(Timestamp now) {
		this.now = now;
	}
}
