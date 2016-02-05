import java.util.Vector;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;



public class CanalDiffusion {
	Calendar calendar; 
	ArrayList<Message> listMessages;
	
	ArrayList<Message> messageA;
	ArrayList<Message> messageB; 
	
	CanalDiffusion(){
		 calendar = Calendar.getInstance();
		 listMessages = new ArrayList<Message>();
	}
	
	public void posterMessageAnonyme(String s){
		Message m = new Message();
		m.setContenu(s);
		listMessages.add(m);
	}
	
	public Vector<String> recupererMessagesAnonymes(Date debut, Date fin){
		Vector<String> messages = new Vector<String>();
			
		for (int i = 0; i < listMessages.size(); i++) {
			if (listMessages.get(i).getNow().compareTo(debut) >=0 && listMessages.get(i).getNow().compareTo(fin)<=0) {
				messages.addElement(listMessages.get(i).getContenu());
				//System.out.println(listMessages.get(i).getNow().compareTo(debut));
			}
		}
		return messages;
	}
	
	public void genererSecret(String alice, String bob, int delay) throws InterruptedException{
		int lower = 0;
		int higher = 1;
		int grand = 10;
		
		messageA = new ArrayList<Message>();
		messageB = new ArrayList<Message>();
		
		while(delay>=0){
			int randomA = (int)(Math.random() * (higher-lower)) + lower;
			int aleaA = (int)(Math.random() * (grand-higher)) + higher;
			int randomB = (int)(Math.random() * (higher-lower)) + lower;
			int aleaB = (int)(Math.random() * (grand-higher)) + higher;
			String A;
			String B;
			Message MA = new Message();
			Message MB = new Message();
			
			if (randomA == 0) {
				Thread.sleep(aleaA);
				A="Alice";
				
			}else{
				A="Bob";
			}
			posterMessageAnonyme(A);
			MA.setContenu(A);
			messageA.add(MA);
			if (randomB == 0) {
				Thread.sleep(aleaB);
				B="Bob";
			}else{
				B="Alice";
			}
			MB.setContenu(B);
			posterMessageAnonyme(B);
			messageB.add(MB);
			delay--;
		}
		
		
		
	}
	
	public static void main(String[] args) throws InterruptedException {
		CanalDiffusion canal = new CanalDiffusion();
		Calendar calendar = Calendar.getInstance();
		Timestamp deb;
		Timestamp fin;
		
		deb=new Timestamp(calendar.getTimeInMillis());
		System.out.println(deb.getTime());
		
		canal.posterMessageAnonyme("hello world");
		canal.posterMessageAnonyme("hello world");
		canal.posterMessageAnonyme("hello world");
		canal.posterMessageAnonyme("hello world");
		canal.posterMessageAnonyme("hello world");
		canal.posterMessageAnonyme("hello world");
		canal.posterMessageAnonyme("hello world");
		canal.posterMessageAnonyme("hello world");
		
		Thread.sleep(1000);
		
		Calendar ca = Calendar.getInstance();
		fin = new Timestamp(ca.getTimeInMillis());
		System.out.println(fin.getTime());
		
		Thread.sleep(1000);
		
		canal.posterMessageAnonyme("test");
		canal.posterMessageAnonyme("bye");

		Vector <String>v=new Vector<String>();
		v = canal.recupererMessagesAnonymes(deb, fin);
		System.out.println(v.size());
		for(int i=v.size()-1; i>=0; i--){
			System.out.println(v.get(i));
		}
	}

}
